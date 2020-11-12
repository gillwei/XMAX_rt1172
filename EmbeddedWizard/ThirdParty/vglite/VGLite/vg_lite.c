/****************************************************************************
*
*    The MIT License (MIT)
*
*    Copyright 2012 - 2020 Vivante Corporation, Santa Clara, California.
*    All Rights Reserved.
*
*    Permission is hereby granted, free of charge, to any person obtaining
*    a copy of this software and associated documentation files (the
*    'Software'), to deal in the Software without restriction, including
*    without limitation the rights to use, copy, modify, merge, publish,
*    distribute, sub license, and/or sell copies of the Software, and to
*    permit persons to whom the Software is furnished to do so, subject
*    to the following conditions:
*
*    The above copyright notice and this permission notice (including the
*    next paragraph) shall be included in all copies or substantial
*    portions of the Software.
*
*    THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND,
*    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
*    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.
*    IN NO EVENT SHALL VIVANTE AND/OR ITS SUPPLIERS BE LIABLE FOR ANY
*    CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
*    TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
*    SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include "vg_lite.h"
#include "vg_lite_kernel.h"


/* This is the function to call from the VGLite driver to interface with the GPU. */
vg_lite_error_t vg_lite_kernel(vg_lite_kernel_command_t command, void * data);


/*** Command buffer dump ***/
#ifndef DUMP_COMMAND
#define DUMP_COMMAND 0
#endif

#ifndef DUMP_IMAGE
#define DUMP_IMAGE 0

#else
#ifndef DUMP_COMMAND
#define DUMP_COMMAND 0
#endif

#ifndef DUMP_IMAGE
#define DUMP_IMAGE 0
#endif
#endif

#define VG_TARGET_FC_DUMP 0

/* Fast clear is not used by default,if SOC should use this ,set this macro to 1. */
#ifndef VG_TARGET_FAST_CLEAR
    #define VG_TARGET_FAST_CLEAR 0
#endif /* VG_TARGET_FAST_CLEAR */

#if DUMP_COMMAND || DUMP_IMAGE
#ifdef __linux__
#include <unistd.h>
#endif
#endif

/*** Command buffer configurations ***/

/*** Global Context Access ***/
#define GET_CONTEXT() &s_context

/*** Command buffer configurations, double buffer support ***/
#define VG_LITE_COMMAND_BUFFER_SIZE (64 << 10)
#define CMDBUF_BUFFER(context)  (context).command_buffer[(context).command_buffer_current]
#define CMDBUF_INDEX(context)   (context).command_buffer_current
#define CMDBUF_SIZE(context)    (context).command_buffer_size
#define CMDBUF_OFFSET(context)  (context).command_offset[(context).command_buffer_current]
#define CMDBUF_SWAP(context)    (context).command_buffer_current = \
                                    ((context).command_buffer_current + 1) % CMDBUF_COUNT

#define VG_LITE_RETURN_ERROR(func) \
if ((error = func) != VG_LITE_SUCCESS) \
return error

#define VG_LITE_BREAK_ERROR(func) \
if ((error = func) != VG_LITE_SUCCESS) \
break

/*** Command macros ***/

#define VG_LITE_END(interrupt)  (0x00000000 | interrupt)
#define VG_LITE_SEMAPHORE(id)   (0x10000000 | id)
#define VG_LITE_STALL(id)       (0x20000000 | id)
#define VG_LITE_STATE(address)  (0x30010000 | address)
#define VG_LITE_STATES(count, address)  (0x30000000 | ((count) << 16) | address)
#define VG_LITE_DATA(count)     (0x40000000 | count)
#define VG_LITE_CALL(count)     (0x60000000 | count)
#define VG_LITE_RETURN()        (0x70000000)
#define VG_LITE_NOP()           (0x80000000)

/*** Shortcuts. ***/
#define A(color) (color) >> 24
#define R(color) ((color) & 0x00ff0000) >> 16
#define G(color) ((color) & 0x0000ff00) >> 8
#define B(color) ((color) & 0xff)
#define ARGB(a, r, g, b) ((a) << 24) | ((r) << 16) | ((g) << 8 ) | (b)
#define ARGB4(a, r, g, b) (((a) & 0xf0) << 8) | (((r) & 0xf0) << 4) | (((g) & 0xf0)) | ((b) >> 4)

#define FC_BURST_BYTES  64
#define FC_BIT_TO_BYTES 64

#define MIN(a, b) (a) > (b) ? (b) : (a)
#define MAX(a, b) (a) > (b) ? (a) : (b)

static uint32_t command_buffer_size = VG_LITE_COMMAND_BUFFER_SIZE;

#define FORMAT_ALIGNMENT(stride,align) \
    { \
        if((stride) % (align) != 0) \
            return VG_LITE_INVALID_ARGUMENT; \
        return VG_LITE_SUCCESS; \
    }

#define DEST_ALIGNMENT_LIMITATION 64  /* To match hardware alignment requirement */

typedef struct vg_lite_context {
    vg_lite_kernel_context_t    context;
    vg_lite_capabilities_t      capabilities;
    uint8_t                   * command_buffer[CMDBUF_COUNT];
    uint32_t                    command_buffer_size;
    uint32_t                    command_offset[CMDBUF_COUNT];
    uint32_t                    command_buffer_current;
    vg_lite_tsbuffer_info_t     tsbuffer;
    vg_lite_buffer_t          * rtbuffer;                   /* DDRLess: this is used as composing buffer. */

#if VG_TARGET_FAST_CLEAR
    vg_lite_buffer_t            fcBuffer;                   /* Buffer used for fast clear cache. */
    uint32_t                    clearValue;
#endif

    uint32_t                    scissor_enabled;
    uint32_t                    scissor_dirty;              /* Indicates whether scissor states are changed or not. e.g., scissors[4] or scissor_enabled. */
    int32_t                     scissor[4];                 /* Scissor area: x, y, right, bottom. */
    uint32_t                    chip_id;
    uint32_t                    chip_rev;
} vg_lite_context_t;

typedef struct vg_lite_feature_database{
    uint32_t                    chip_id;
    uint32_t                    chip_version;
    uint32_t                    cid;
    uint32_t                    vg_im_index_format:1;
    uint32_t                    vg_pe_premultiply:1;
    uint32_t                    vg_scissor:1;
    uint32_t                    vg_border_culling:1;
    uint32_t                    vg_rgba2_format:1;
    uint32_t                    vg_quality_8x:1;
} vg_lite_feature_database_t;

static vg_lite_feature_database_t VGFeatureInfos[] = {
    /* vg255 */
    {
        0x255, /* ChipID */
        0x1311, /* ChipRevision */
        0x404,  /* CID */
        0x0, /* gcFEATURE_BIT_VG_IM_INDEX_FORMAT */
        0x1, /* gcFEATURE_BIT_VG_PE_PREMULTIPLY */
        0x0, /* gcFEATURE_BIT_VG_SCISSOR */
        0x1, /* gcFEATURE_BIT_VG_BORDER_CULLING */
        0x1, /* gcFEATURE_BIT_VG_RGBA2_FORMAT */
        0X0, /* gcFEATURE_BIT_VG_QUALITY_8X */
    },
    /* vg255 */
    {
        0x255, /* ChipID */
        0x1311, /* ChipRevision */
        0x40a,  /* CID */
        0x1, /* gcFEATURE_BIT_VG_IM_INDEX_FORMAT */
        0x1, /* gcFEATURE_BIT_VG_PE_PREMULTIPLY */
        0x0, /* gcFEATURE_BIT_VG_SCISSOR */
        0x1, /* gcFEATURE_BIT_VG_BORDER_CULLING */
        0x1, /* gcFEATURE_BIT_VG_RGBA2_FORMAT */
        0X1, /* gcFEATURE_BIT_VG_QUALITY_8X */
    },
    /* vg255 */
    {
        0x255, /* ChipID */
        0x1311, /* ChipRevision */
        0x40b,  /* CID */
        0x1, /* gcFEATURE_BIT_VG_IM_INDEX_FORMAT */
        0x1, /* gcFEATURE_BIT_VG_PE_PREMULTIPLY */
        0x0, /* gcFEATURE_BIT_VG_SCISSOR */
        0x1, /* gcFEATURE_BIT_VG_BORDER_CULLING */
        0x1, /* gcFEATURE_BIT_VG_RGBA2_FORMAT */
        0X1, /* gcFEATURE_BIT_VG_QUALITY_8X */
    },
    /* vg355 */
    {
        0x355, /* ChipID */
        0x1217, /* ChipRevision */
        0x408,  /* CID */
        0x1, /* gcFEATURE_BIT_VG_IM_INDEX_FORMAT */
        0x1, /* gcFEATURE_BIT_VG_PE_PREMULTIPLY */
        0x1, /* gcFEATURE_BIT_VG_SCISSOR */
        0x0, /* gcFEATURE_BIT_VG_BORDER_CULLING */
        0x0, /* gcFEATURE_BIT_VG_RGBA2_FORMAT */
        0X0, /* gcFEATURE_BIT_VG_QUALITY_8X */
    },
    /* vg355 (MIMXRT1170) */
    {
        0x355, /* ChipID */
        0x1216, /* ChipRevision */
        0x0,  /* CID */
        0x1, /* gcFEATURE_BIT_VG_IM_INDEX_FORMAT */
        0x1, /* gcFEATURE_BIT_VG_PE_PREMULTIPLY */
        0x1, /* gcFEATURE_BIT_VG_SCISSOR */
        0x0, /* gcFEATURE_BIT_VG_BORDER_CULLING */
        0x0, /* gcFEATURE_BIT_VG_RGBA2_FORMAT */
        0X0, /* gcFEATURE_BIT_VG_QUALITY_8X */
    },
};

typedef struct vg_lite_ftable {
    uint32_t    ftable[gcFEATURE_COUNT];
    uint32_t    ftflag;
} vg_lite_ftable_t;

#if DUMP_COMMAND
FILE * fp;
char filename[30];
#endif

vg_lite_context_t s_context = {0};
vg_lite_ftable_t s_ftable = {{0}, 0};

int submit_flag = 0;

/* A 2D Point definition. */
typedef struct vg_lite_point {
    int x;
    int y;
}
vg_lite_point_t;

static void _memset(void *p, unsigned char value, int size)
{
    int i;
    for (i = 0; i < size; i++) {
        ((unsigned char*) p)[i] = value;
    }
}

static int has_valid_command_buffer(vg_lite_context_t *context)
{
    if(context == NULL)
        return 0;
    if(context->command_buffer_current >= CMDBUF_COUNT)
        return 0;
    if(context->command_buffer == NULL)
        return 0;
    if(context->command_buffer[context->command_buffer_current] == NULL)
        return 0;

    return 1;
}

#if DUMP_IMAGE
static void dump_img(void * memory, int width, int height, vg_lite_buffer_format_t format)
{
    FILE * fp;
    char imgname[255] = {'\0'};
    int i;
    static int num = 1;
    unsigned int* pt = (unsigned int*) memory;

    sprintf(imgname, "img_pid%d_%d.txt", getpid(), num++);

    fp = fopen(imgname, "w");

    if (fp == NULL)
        printf("error!\n");


    switch (format) {
        case VG_LITE_INDEX_1:
            for(i = 0; i < width * height / 32; ++i)
            {
                fprintf(fp, "0x%08x\n",pt[i]);
            }
            break;

        case VG_LITE_INDEX_2:
            for(i = 0; i < width * height / 16; ++i)
            {
                fprintf(fp, "0x%08x\n",pt[i]);
            }
            break;

        case VG_LITE_INDEX_4:
            for(i = 0; i < width * height / 8; ++i)
            {
                fprintf(fp, "0x%08x\n",pt[i]);
            }
            break;

        case VG_LITE_INDEX_8:
            for(i = 0; i < width * height / 4; ++i)
            {
                fprintf(fp, "0x%08x\n",pt[i]);
            }
            break;

        case VG_LITE_RGBA2222:
            for(i = 0; i < width * height / 4; ++i)
            {
                fprintf(fp, "0x%08x\n",pt[i]);
            }
            break;

        case VG_LITE_RGBA4444:
        case VG_LITE_BGRA4444:
        case VG_LITE_RGB565:
        case VG_LITE_BGR565:
            for(i = 0; i < width * height / 2; ++i)
            {
                fprintf(fp, "0x%08x\n",pt[i]);
            }
            break;

        case VG_LITE_RGBA8888:
        case VG_LITE_BGRA8888:
        case VG_LITE_RGBX8888:
        case VG_LITE_BGRX8888:
            for(i = 0; i < width * height; ++i)
            {
                fprintf(fp, "0x%08x\n",pt[i]);
            }
            break;

        default:
            break;
    }
    fclose(fp);
    fp = NULL;
}
#endif

/* Convert VGLite data format to HW value. */
static uint32_t convert_path_format(vg_lite_format_t format)
{
    switch (format) {
        case VG_LITE_S8:
            return 0;

        case VG_LITE_S16:
            return 0x100000;

        case VG_LITE_S32:
            return 0x200000;

        case VG_LITE_FP32:
            return 0x300000;

        default:
            return 0;
    }
}

/* Convert VGLite quality enums to HW values. */
static uint32_t convert_path_quality(vg_lite_quality_t quality)
{
    switch (quality) {
        case VG_LITE_HIGH:
            return 0x3;

        case VG_LITE_UPPER:
            return 0x2;

        case VG_LITE_MEDIUM:
            return 0x1;

        default:
            return 0x0;
    }
}

static uint32_t rgb_to_l(uint32_t color)
{
    uint32_t l = (uint32_t)((0.2126f * (vg_lite_float_t)(color & 0xFF)) +
                            (0.7152f * (vg_lite_float_t)((color >> 8) & 0xFF)) +
                            (0.0722f * (vg_lite_float_t)((color >> 16) & 0xFF)));
    return l | (l << 24);
}

/* Get the bpp information of a color format. */
static void get_format_bytes(vg_lite_buffer_format_t format,
                             uint32_t *mul,
                             uint32_t *div,
                             uint32_t *bytes_align)
{
    *mul = *div = 1;
    *bytes_align = 4;
    switch (format) {
        case VG_LITE_L8:
        case VG_LITE_A8:
            break;

        case VG_LITE_A4:
            *div = 2;
            break;

        case VG_LITE_ABGR1555:
        case VG_LITE_ARGB1555:
        case VG_LITE_BGRA5551:
        case VG_LITE_RGBA5551:
        case VG_LITE_RGBA4444:
        case VG_LITE_BGRA4444:
        case VG_LITE_ABGR4444:
        case VG_LITE_ARGB4444:
        case VG_LITE_RGB565:
        case VG_LITE_BGR565:
        case VG_LITE_YUYV:
        case VG_LITE_YUY2:
        case VG_LITE_YUY2_TILED:
        /* AYUY2 buffer memory = YUY2 + alpha. */
        case VG_LITE_AYUY2:
        case VG_LITE_AYUY2_TILED:
            *mul = 2;
            break;

        case VG_LITE_RGBA8888:
        case VG_LITE_BGRA8888:
        case VG_LITE_ABGR8888:
        case VG_LITE_ARGB8888:
        case VG_LITE_RGBX8888:
        case VG_LITE_BGRX8888:
        case VG_LITE_XBGR8888:
        case VG_LITE_XRGB8888:
            *mul = 4;
            break;

        case VG_LITE_NV12:
        case VG_LITE_NV12_TILED:
            *mul = 3;
            break;

        case VG_LITE_ANV12:
        case VG_LITE_ANV12_TILED:
            *mul = 4;
            break;

        case VG_LITE_INDEX_1:
            *div = 8;
            *bytes_align = 8;
            break;

        case VG_LITE_INDEX_2:
            *div = 4;
            *bytes_align = 8;
            break;

        case VG_LITE_INDEX_4:
            *div = 2;
            *bytes_align = 8;
            break;

        case VG_LITE_INDEX_8:
            *bytes_align = 1;
            break;

        case VG_LITE_RGBA2222:
        case VG_LITE_BGRA2222:
        case VG_LITE_ABGR2222:
        case VG_LITE_ARGB2222:
           *mul = 1;
           break;

        default:
            break;
    }
}

/* Convert VGLite target color format to HW value. */
static uint32_t convert_target_format(vg_lite_buffer_format_t format, vg_lite_capabilities_t caps)
{
    switch (format) {
        case VG_LITE_A8:
            return 0x0;

        case VG_LITE_L8:
            return 0x6;

        case VG_LITE_ABGR4444:
            return 0x14;

        case VG_LITE_ARGB4444:
            return 0x34;

        case VG_LITE_RGBA4444:
            return 0x24;

        case VG_LITE_BGRA4444:
            return 0x4;

        case VG_LITE_RGB565:
            return 0x21;

        case VG_LITE_BGR565:
            return 0x1;

        case VG_LITE_ABGR8888:
            return 0x13;

        case VG_LITE_ARGB8888:
            return 0x33;

        case VG_LITE_RGBA8888:
            return 0x23;

        case VG_LITE_BGRA8888:
            return 0x3;

        case VG_LITE_RGBX8888:
            return 0x22;

        case VG_LITE_BGRX8888:
            return 0x2;

        case VG_LITE_XBGR8888:
            return 0x12;

        case VG_LITE_XRGB8888:
            return 0x32;

        case VG_LITE_ABGR1555:
            return 0x15;

        case VG_LITE_RGBA5551:
            return 0x25;

        case VG_LITE_ARGB1555:
            return 0x35;

        case VG_LITE_BGRA5551:
            return 0x5;

        case VG_LITE_YUYV:
        case VG_LITE_YUY2:
        case VG_LITE_YUY2_TILED:
            return 0x8;

        case VG_LITE_NV12:
        case VG_LITE_NV12_TILED:
            return 0xB;

        case VG_LITE_ANV12:
        case VG_LITE_ANV12_TILED:
            return 0xE;

        case VG_LITE_BGRA2222:
            return 0x7;

        case VG_LITE_RGBA2222:
            return 0x27;

        case VG_LITE_ABGR2222:
            return 0x17;

        case VG_LITE_ARGB2222:
            return 0x37;

        case VG_LITE_AYUY2:
        case VG_LITE_AYUY2_TILED:
        default:
            return 0xF;
    }
}

/* determine source IM is aligned by specified bytes */
static vg_lite_error_t _check_source_aligned(vg_lite_buffer_format_t format,uint32_t stride)
{
    switch (format) {
        case VG_LITE_A4:
        case VG_LITE_INDEX_1:
        case VG_LITE_INDEX_2:
        case VG_LITE_INDEX_4:
            FORMAT_ALIGNMENT(stride,8);
            break;

        case VG_LITE_L8:
        case VG_LITE_A8:
        case VG_LITE_INDEX_8:
        case VG_LITE_RGBA2222:
        case VG_LITE_BGRA2222:
        case VG_LITE_ABGR2222:
        case VG_LITE_ARGB2222:
            FORMAT_ALIGNMENT(stride,16);
            break;

        case VG_LITE_RGBA4444:
        case VG_LITE_BGRA4444:
        case VG_LITE_ABGR4444:
        case VG_LITE_ARGB4444:
        case VG_LITE_RGB565:
        case VG_LITE_BGR565:
        case VG_LITE_BGRA5551:
        case VG_LITE_RGBA5551:
        case VG_LITE_ABGR1555:
        case VG_LITE_ARGB1555:
        case VG_LITE_YUYV:
        case VG_LITE_YUY2:
        case VG_LITE_NV12:
        case VG_LITE_YV12:
        case VG_LITE_YV24:
        case VG_LITE_YV16:
        case VG_LITE_NV16:
            FORMAT_ALIGNMENT(stride,32);
            break;

        case VG_LITE_RGBA8888:
        case VG_LITE_BGRA8888:
        case VG_LITE_ABGR8888:
        case VG_LITE_ARGB8888:
        case VG_LITE_RGBX8888:
        case VG_LITE_BGRX8888:
        case VG_LITE_XBGR8888:
        case VG_LITE_XRGB8888:
            FORMAT_ALIGNMENT(stride,64);
            break;

        default:
            return VG_LITE_SUCCESS;
    }
}

/* Convert VGLite source color format to HW values. */
static uint32_t convert_source_format(vg_lite_buffer_format_t format)
{
    switch (format) {
        case VG_LITE_L8:
            return 0x0;

        case VG_LITE_A4:
            return 0x1;

        case VG_LITE_A8:
            return 0x2;

        case VG_LITE_RGBA4444:
            return 0x23;

        case VG_LITE_BGRA4444:
            return 0x3;

        case VG_LITE_ABGR4444:
            return 0x13;

        case VG_LITE_ARGB4444:
            return 0x33;

        case VG_LITE_RGB565:
            return 0x25;

        case VG_LITE_BGR565:
            return 0x5;

        case VG_LITE_RGBA8888:
            return 0x27;

        case VG_LITE_BGRA8888:
            return 0x7;

        case VG_LITE_ABGR8888:
            return 0x17;

        case VG_LITE_ARGB8888:
            return 0x37;

        case VG_LITE_RGBX8888:
            return 0x26;

        case VG_LITE_BGRX8888:
            return 0x6;

        case VG_LITE_XBGR8888:
            return 0x16;

        case VG_LITE_XRGB8888:
            return 0x36;

        case VG_LITE_BGRA5551:
            return 0x4;

        case VG_LITE_RGBA5551:
            return 0x24;

        case VG_LITE_ABGR1555:
            return 0x14;

        case VG_LITE_ARGB1555:
            return 0x34;

        case VG_LITE_YUYV:
            return 0x8;

        case VG_LITE_YUY2:
        case VG_LITE_YUY2_TILED:
            return 0x8;

        case VG_LITE_NV12:
        case VG_LITE_NV12_TILED:
            return 0xB;

        case VG_LITE_ANV12:
        case VG_LITE_ANV12_TILED:
            return 0xE;

        case VG_LITE_YV12:
            return 0x9;

        case VG_LITE_YV24:
            return 0xD;

        case VG_LITE_YV16:
            return 0xC;

        case VG_LITE_NV16:
            return 0xA;

        case VG_LITE_AYUY2:
        case VG_LITE_AYUY2_TILED:
        default:
            return 0xF;

        case VG_LITE_INDEX_1:
            return 0x200;

        case VG_LITE_INDEX_2:
            return 0x400;

        case VG_LITE_INDEX_4:
            return 0x600;

        case VG_LITE_INDEX_8:
            return 0x800;

        case VG_LITE_RGBA2222:
            return 0xA20;

        case VG_LITE_BGRA2222:
            return 0xA00;

        case VG_LITE_ABGR2222:
            return 0xA10;

        case VG_LITE_ARGB2222:
            return 0xA30;
    }
}

/* Convert VGLite blend modes to HW values. */
static uint32_t convert_blend(vg_lite_blend_t blend)
{
    switch (blend) {
        case VG_LITE_BLEND_SRC_OVER:
            return 0x00000100;

        case VG_LITE_BLEND_DST_OVER:
            return 0x00000200;

        case VG_LITE_BLEND_SRC_IN:
            return 0x00000300;

        case VG_LITE_BLEND_DST_IN:
            return 0x00000400;

        case VG_LITE_BLEND_SCREEN:
            return 0x00000600;

        case VG_LITE_BLEND_MULTIPLY:
            return 0x00000500;

        case VG_LITE_BLEND_ADDITIVE:
            return 0x00000900;

        case VG_LITE_BLEND_SUBTRACT:
            return 0x00000A00;

        default:
            return 0;
    }
}

/* Convert VGLite uv swizzle enums to HW values. */
static uint32_t convert_uv_swizzle(vg_lite_swizzle_t swizzle)
{
    switch (swizzle) {
        case VG_LITE_SWIZZLE_UV:
            return 0x00000040;
            break;

        case VG_LITE_SWIZZLE_VU:
            return 0x00000050;

        default:
            return 0;
            break;
    }
}

/* Convert VGLite yuv standard enums to HW values. */
static uint32_t convert_yuv2rgb(vg_lite_yuv2rgb_t yuv)
{
    switch (yuv) {
        case VG_LITE_YUV601:
            return 0;
            break;

        case VG_LITE_YUV709:
            return 0x00008000;

        default:
            return 0;
            break;
    }
}

/* Initialize the feature table of a chip. */
static vg_lite_error_t fill_feature_table(uint32_t * feature)
{
    uint16_t size = sizeof(VGFeatureInfos) / sizeof(VGFeatureInfos[0]);
    uint16_t i;
    uint32_t cid = 0;

    /* Clear all bits. */
    _memset(feature, 0, sizeof(uint32_t) * gcFEATURE_COUNT);
    vg_lite_get_product_info(NULL,&s_context.chip_id,&s_context.chip_rev);
    vg_lite_get_register(0x30, &cid);

    for(i = 0;i < size; i++){
        if ((VGFeatureInfos[i].chip_id == s_context.chip_id)
            && (VGFeatureInfos[i].chip_version == s_context.chip_rev)
            && (VGFeatureInfos[i].cid == cid)
           )
        {
            feature[gcFEATURE_BIT_VG_IM_INDEX_FORMAT] = VGFeatureInfos[i].vg_im_index_format;
            feature[gcFEATURE_BIT_VG_PE_PREMULTIPLY] = VGFeatureInfos[i].vg_pe_premultiply;
            feature[gcFEATURE_BIT_VG_SCISSOR] = VGFeatureInfos[i].vg_scissor;
            feature[gcFEATURE_BIT_VG_BORDER_CULLING] = VGFeatureInfos[i].vg_border_culling;
            feature[gcFEATURE_BIT_VG_RGBA2_FORMAT] = VGFeatureInfos[i].vg_rgba2_format;
            feature[gcFEATURE_BIT_VG_QUALITY_8X] = VGFeatureInfos[i].vg_quality_8x;
            break;
        }
    }

    if(i == size) {
        return VG_LITE_INVALID_ARGUMENT;
    }
    s_ftable.ftflag = 1;

    return VG_LITE_SUCCESS;
}

static vg_lite_error_t submit(vg_lite_context_t * context);
static vg_lite_error_t stall(vg_lite_context_t * context, uint32_t time_ms, uint32_t mask);

/* Push a state array into current command buffer. */
static vg_lite_error_t push_states(vg_lite_context_t * context, uint32_t address, uint32_t count, uint32_t *data)
{
    uint32_t i;
    vg_lite_error_t error;
    if (!has_valid_command_buffer(context))
        return VG_LITE_NO_CONTEXT;

    if (CMDBUF_OFFSET(*context) + 8 + VG_LITE_ALIGN(count + 1, 2) * 4 >= CMDBUF_SIZE(*context)) {
        VG_LITE_RETURN_ERROR(submit(context));
        VG_LITE_RETURN_ERROR(stall(context, 0, (uint32_t)~0));
    }

    ((uint32_t *) (CMDBUF_BUFFER(*context) + CMDBUF_OFFSET(*context)))[0] = VG_LITE_STATES(count, address);

    for (i = 0; i < count; i++) {
        ((uint32_t *) (CMDBUF_BUFFER(*context) + CMDBUF_OFFSET(*context)))[1 + i] = data[i];
    }
    if (i%2 == 0) {
        ((uint32_t *) (CMDBUF_BUFFER(*context) + CMDBUF_OFFSET(*context)))[1 + i] = VG_LITE_NOP();
    }

#if DUMP_COMMAND
    {
        uint32_t loops;
        if (strncmp(filename, "Commandbuffer", 13)) {
            sprintf(filename, "Commandbuffer_pid%d.txt", getpid());
        }

        fp = fopen(filename, "a");

        if (fp == NULL)
            printf("error!\n");

        fprintf(fp, "Command buffer: 0x%08x, ",
                ((uint32_t *) (CMDBUF_BUFFER(*context) + CMDBUF_OFFSET(*context)))[0]);

        for (loops = 0; loops < count / 2; loops++) {
            fprintf(fp, "0x%08x,\nCommand buffer: 0x%08x, ",
                    ((uint32_t *) (CMDBUF_BUFFER(*context) + CMDBUF_OFFSET(*context)))[(loops + 1) * 2 - 1],
                    ((uint32_t *) (CMDBUF_BUFFER(*context) + CMDBUF_OFFSET(*context)))[(loops + 1) * 2]);
        }

        fprintf(fp, "0x%08x,\n",
                ((uint32_t *) (CMDBUF_BUFFER(*context) + CMDBUF_OFFSET(*context)))[(loops + 1) * 2 - 1]);

        fclose(fp);
        fp = NULL;
    }
#endif

    CMDBUF_OFFSET(*context) += VG_LITE_ALIGN(count + 1, 2) * 4;

    return VG_LITE_SUCCESS;
}

/* Push a single state command into the current command buffer. */
static vg_lite_error_t push_state(vg_lite_context_t * context, uint32_t address, uint32_t data)
{
    vg_lite_error_t error;
    if (!has_valid_command_buffer(context))
        return VG_LITE_NO_CONTEXT;

    if (CMDBUF_OFFSET(*context) + 16 >= CMDBUF_SIZE(*context)) {
        VG_LITE_RETURN_ERROR(submit(context));
        VG_LITE_RETURN_ERROR(stall(context, 0, (uint32_t)~0));
    }

    ((uint32_t *) (CMDBUF_BUFFER(*context) + CMDBUF_OFFSET(*context)))[0] = VG_LITE_STATE(address);
    ((uint32_t *) (CMDBUF_BUFFER(*context) + CMDBUF_OFFSET(*context)))[1] = data;

#if DUMP_COMMAND
    if (strncmp(filename, "Commandbuffer", 13)) {
        sprintf(filename, "Commandbuffer_pid%d.txt", getpid());
    }

    fp = fopen(filename, "a");

    if (fp == NULL)
        printf("error!\n");

    fprintf(fp, "Command buffer: 0x%08x, 0x%08x,\n",
            ((uint32_t *) (CMDBUF_BUFFER(*context) + CMDBUF_OFFSET(*context)))[0],
            ((uint32_t *) (CMDBUF_BUFFER(*context) + CMDBUF_OFFSET(*context)))[1]);

    fclose(fp);
    fp = NULL;
#endif

    CMDBUF_OFFSET(*context) += 8;

    return VG_LITE_SUCCESS;
}

/* Push a single state command with given address. */
static vg_lite_error_t push_state_ptr(vg_lite_context_t * context, uint32_t address, void * data_ptr)
{
    vg_lite_error_t error;
    uint32_t data = *(uint32_t *) data_ptr;
    if (!has_valid_command_buffer(context))
        return VG_LITE_NO_CONTEXT;

    if (CMDBUF_OFFSET(*context) + 16 >= CMDBUF_SIZE(*context)) {
        VG_LITE_RETURN_ERROR(submit(context));
        VG_LITE_RETURN_ERROR(stall(context, 0, (uint32_t)~0));
    }

    ((uint32_t *) (CMDBUF_BUFFER(*context) + CMDBUF_OFFSET(*context)))[0] = VG_LITE_STATE(address);
    ((uint32_t *) (CMDBUF_BUFFER(*context) + CMDBUF_OFFSET(*context)))[1] = data;

#if DUMP_COMMAND
    if (strncmp(filename, "Commandbuffer", 13)) {
        sprintf(filename, "Commandbuffer_pid%d.txt", getpid());
    }

    fp = fopen(filename, "a");

    if (fp == NULL)
        printf("error!\n");
    fprintf(fp, "Command buffer: 0x%08x, 0x%08x,\n",
            ((uint32_t *) (CMDBUF_BUFFER(*context) + CMDBUF_OFFSET(*context)))[0],
            ((uint32_t *) (CMDBUF_BUFFER(*context) + CMDBUF_OFFSET(*context)))[1]);

    fclose(fp);
    fp = NULL;
#endif

    CMDBUF_OFFSET(*context) += 8;

    return VG_LITE_SUCCESS;
}

/* Push a "call" command into the current command buffer. */
static vg_lite_error_t push_call(vg_lite_context_t * context, uint32_t address, uint32_t bytes)
{
    vg_lite_error_t error;
    if (!has_valid_command_buffer(context))
        return VG_LITE_NO_CONTEXT;

    if (CMDBUF_OFFSET(*context) + 16 >= CMDBUF_SIZE(*context)) {
        VG_LITE_RETURN_ERROR(submit(context));
        VG_LITE_RETURN_ERROR(stall(context, 0, (uint32_t)~0));
    }

    ((uint32_t *) (CMDBUF_BUFFER(*context) + CMDBUF_OFFSET(*context)))[0] = VG_LITE_CALL((bytes + 7) / 8);
    ((uint32_t *) (CMDBUF_BUFFER(*context) + CMDBUF_OFFSET(*context)))[1] = address;

#if DUMP_COMMAND
    if (strncmp(filename, "Commandbuffer", 13)) {
        sprintf(filename, "Commandbuffer_pid%d.txt", getpid());
    }

    fp = fopen(filename, "a");

    if (fp == NULL)
        printf("error!\n");
    fprintf(fp, "Command buffer: 0x%08x, 0x%08x,\n",
            ((uint32_t *) (CMDBUF_BUFFER(*context) + CMDBUF_OFFSET(*context)))[0],
            ((uint32_t *) (CMDBUF_BUFFER(*context) + CMDBUF_OFFSET(*context)))[1]);

    fclose(fp);
    fp = NULL;
#endif

    CMDBUF_OFFSET(*context) += 8;

    return VG_LITE_SUCCESS;
}

/* Push a rectangle command into the current command buffer. */
static vg_lite_error_t push_rectangle(vg_lite_context_t * context, int x, int y, int width, int height)
{
    vg_lite_error_t error;
    if (!has_valid_command_buffer(context))
        return VG_LITE_NO_CONTEXT;

    if (CMDBUF_OFFSET(*context) + 16 >= CMDBUF_SIZE(*context)) {
        VG_LITE_RETURN_ERROR(submit(context));
        VG_LITE_RETURN_ERROR(stall(context, 0, (uint32_t)~0));
    }

    ((uint32_t *) (CMDBUF_BUFFER(*context) + CMDBUF_OFFSET(*context)))[0] = VG_LITE_DATA(1);
    ((uint32_t *) (CMDBUF_BUFFER(*context) + CMDBUF_OFFSET(*context)))[1] = 0;
    ((uint16_t *) (CMDBUF_BUFFER(*context) + CMDBUF_OFFSET(*context)))[4] = (uint16_t)x;
    ((uint16_t *) (CMDBUF_BUFFER(*context) + CMDBUF_OFFSET(*context)))[5] = (uint16_t)y;
    ((uint16_t *) (CMDBUF_BUFFER(*context) + CMDBUF_OFFSET(*context)))[6] = (uint16_t)width;
    ((uint16_t *) (CMDBUF_BUFFER(*context) + CMDBUF_OFFSET(*context)))[7] = (uint16_t)height;

#if DUMP_COMMAND
    if (strncmp(filename, "Commandbuffer", 13)) {
        sprintf(filename, "Commandbuffer_pid%d.txt", getpid());
    }

    fp = fopen(filename, "a");

    if (fp == NULL)
        printf("error!\n");

    fprintf(fp, "Command buffer: 0x%08x, 0x%08x,\n",
            ((uint32_t *) (CMDBUF_BUFFER(*context) + CMDBUF_OFFSET(*context)))[0], 0);

    fprintf(fp, "Command buffer: 0x%08x, 0x%08x,\n",
            ((uint16_t *) (CMDBUF_BUFFER(*context) + CMDBUF_OFFSET(*context)))[5] << 16 |
            ((uint16_t *) (CMDBUF_BUFFER(*context) + CMDBUF_OFFSET(*context)))[4],
            ((uint16_t *) (CMDBUF_BUFFER(*context) + CMDBUF_OFFSET(*context)))[7] << 16 |
            ((uint16_t *) (CMDBUF_BUFFER(*context) + CMDBUF_OFFSET(*context)))[6]);

    fclose(fp);
    fp = NULL;
#endif

    CMDBUF_OFFSET(*context) += 16;

    return VG_LITE_SUCCESS;
}

/* Push a data array into the current command buffer. */
static vg_lite_error_t push_data(vg_lite_context_t * context, int size, void * data)
{
    vg_lite_error_t error;
    int bytes = VG_LITE_ALIGN(size, 8);

    if (!has_valid_command_buffer(context))
        return VG_LITE_NO_CONTEXT;

    if (CMDBUF_OFFSET(*context) + 16 + bytes >= CMDBUF_SIZE(*context)) {
        VG_LITE_RETURN_ERROR(submit(context));
        VG_LITE_RETURN_ERROR(stall(context, 0, (uint32_t)~0));
    }

    ((uint64_t *) (CMDBUF_BUFFER(*context) + CMDBUF_OFFSET(*context)))[(bytes / 8)] = 0;
    ((uint32_t *) (CMDBUF_BUFFER(*context) + CMDBUF_OFFSET(*context)))[0] = VG_LITE_DATA(bytes / 8);
    ((uint32_t *) (CMDBUF_BUFFER(*context) + CMDBUF_OFFSET(*context)))[1] = 0;
    memcpy(CMDBUF_BUFFER(*context) + CMDBUF_OFFSET(*context) + 8, data, size);

#if DUMP_COMMAND
    {
        int loops;

        if (strncmp(filename, "Commandbuffer", 13)) {
            sprintf(filename, "Commandbuffer_pid%d.txt", getpid());
        }

        fp = fopen(filename, "a");

        if (fp == NULL)
            printf("error!\n");

        fprintf(fp, "Command buffer: 0x%08x, 0x%08x,\n",
                ((uint32_t *) (CMDBUF_BUFFER(*context) + CMDBUF_OFFSET(*context)))[0], 0);
        for (loops = 0; loops < bytes / 8; loops++) {
            fprintf(fp, "Command buffer: 0x%08x, 0x%08x,\n",
                   ((uint32_t *) (CMDBUF_BUFFER(*context) + CMDBUF_OFFSET(*context)))[(loops + 1) * 2],
                   ((uint32_t *) (CMDBUF_BUFFER(*context) + CMDBUF_OFFSET(*context)))[(loops + 1) * 2 + 1]);
        }

        fclose(fp);
        fp = NULL;
    }
#endif

    CMDBUF_OFFSET(*context) += 8 + bytes;

    return VG_LITE_SUCCESS;
}

/* Push a "stall" command into the current command buffer. */
static vg_lite_error_t push_stall(vg_lite_context_t * context, uint32_t module)
{
    vg_lite_error_t error;
    if (!has_valid_command_buffer(context))
        return VG_LITE_NO_CONTEXT;

    if (CMDBUF_OFFSET(*context) + 16 >= CMDBUF_SIZE(*context)) {
        VG_LITE_RETURN_ERROR(submit(context));
        VG_LITE_RETURN_ERROR(stall(context, 0, (uint32_t)~0));
    }

    ((uint32_t *) (CMDBUF_BUFFER(*context) + CMDBUF_OFFSET(*context)))[0] = VG_LITE_SEMAPHORE(module);
    ((uint32_t *) (CMDBUF_BUFFER(*context) + CMDBUF_OFFSET(*context)))[1] = 0;
    ((uint32_t *) (CMDBUF_BUFFER(*context) + CMDBUF_OFFSET(*context)))[2] = VG_LITE_STALL(module);
    ((uint32_t *) (CMDBUF_BUFFER(*context) + CMDBUF_OFFSET(*context)))[3] = 0;

#if DUMP_COMMAND
    if (strncmp(filename, "Commandbuffer", 13)) {
        sprintf(filename, "Commandbuffer_pid%d.txt", getpid());
    }

    fp = fopen(filename, "a");

    if (fp == NULL)
        printf("error!\n");

    fprintf(fp, "Command buffer: 0x%08x, 0x%08x,\n",
            ((uint32_t *) (CMDBUF_BUFFER(*context) + CMDBUF_OFFSET(*context)))[0], 0);
    fprintf(fp, "Command buffer: 0x%08x, 0x%08x,\n",
            ((uint32_t *) (CMDBUF_BUFFER(*context) + CMDBUF_OFFSET(*context)))[2], 0);

    fclose(fp);
    fp = NULL;
#endif

    CMDBUF_OFFSET(*context) += 16;

    return VG_LITE_SUCCESS;
}

/* Submit the current command buffer to HW and reset the current command buffer offset. */
static vg_lite_error_t submit(vg_lite_context_t *context)
{
    vg_lite_error_t error = VG_LITE_SUCCESS;
    vg_lite_kernel_submit_t submit;

    /* Check if there is a valid context and an allocated command buffer. */
    if (!has_valid_command_buffer(context))
        return VG_LITE_NO_CONTEXT;

    /* Check if there is anything to submit. */
    if (CMDBUF_OFFSET(*context) == 0)
        return VG_LITE_INVALID_ARGUMENT;

    /* Check if there is enough space in the command buffer for the END. */
    if (CMDBUF_OFFSET(*context) + 8 > CMDBUF_SIZE(*context)) {
        /* Reset command buffer offset. */
        CMDBUF_OFFSET(*context) = 0;
        return VG_LITE_OUT_OF_RESOURCES;
    }

    /* Append END command into the command buffer. */
    ((uint32_t *) (CMDBUF_BUFFER(*context) + CMDBUF_OFFSET(*context)))[0] = VG_LITE_END(EVENT_END);
    ((uint32_t *) (CMDBUF_BUFFER(*context) + CMDBUF_OFFSET(*context)))[1] = 0;

#if DUMP_COMMAND
    if (strncmp(filename, "Commandbuffer", 13)) {
        sprintf(filename, "Commandbuffer_pid%d.txt", getpid());
    }

    fp = fopen(filename, "a");

    if (fp == NULL)
        printf("error!\n");

    fprintf(fp, "Command buffer: 0x%08x, 0x%08x,\n",
            ((uint32_t *) (CMDBUF_BUFFER(*context) + CMDBUF_OFFSET(*context)))[0], 0);

    fprintf(fp, "Command buffer addr is : %p,\n", CMDBUF_BUFFER(*context));
    fprintf(fp, "Command buffer offset is : %d,\n", CMDBUF_OFFSET(*context) + 8);

    fclose(fp);
    fp = NULL;
#endif

    CMDBUF_OFFSET(*context) += 8;

    /* Submit the command buffer. */
    submit.context = &context->context;
    submit.commands = CMDBUF_BUFFER(*context);
    submit.command_size = CMDBUF_OFFSET(*context);
    submit.command_id = CMDBUF_INDEX(*context);

    /* Wait if GPU has not completed previous CMD buffer */
    if (submit_flag)
    {
        VG_LITE_RETURN_ERROR(stall(&s_context, 0, (uint32_t)~0));
    }
    VG_LITE_RETURN_ERROR(vg_lite_kernel(VG_LITE_SUBMIT, &submit));

    submit_flag = 1;

    vglitemDUMP_BUFFER("command", (unsigned int)CMDBUF_BUFFER(*context),
        submit.context->command_buffer_logical[CMDBUF_INDEX(*context)], 0, submit.command_size);
    vglitemDUMP("@[commit]");

    /* Reset command buffer. */
    CMDBUF_OFFSET(*context) = 0;

    return error;
}

/* Wait for the HW to finish the current execution. */
static vg_lite_error_t stall(vg_lite_context_t * context, uint32_t time_ms, uint32_t mask)
{
    vg_lite_error_t error;
    vg_lite_kernel_wait_t wait;

    vglitemDUMP("@[stall]");
    /* Wait until GPU is ready. */
    wait.context = &context->context;
    wait.timeout_ms = time_ms > 0 ? time_ms : VG_LITE_INFINITE;
    wait.event_mask = mask;
    VG_LITE_RETURN_ERROR(vg_lite_kernel(VG_LITE_WAIT, &wait));

    submit_flag = 0;
    return VG_LITE_SUCCESS;
}

/* Get the inversion of a matrix. */
static int inverse(vg_lite_matrix_t * result, vg_lite_matrix_t * matrix)
{
    vg_lite_float_t det00, det01, det02;
    vg_lite_float_t d;
    int isAffine;

    /* Test for identity matrix. */
    if (matrix == NULL) {
        result->m[0][0] = 1.0f;
        result->m[0][1] = 0.0f;
        result->m[0][2] = 0.0f;
        result->m[1][0] = 0.0f;
        result->m[1][1] = 1.0f;
        result->m[1][2] = 0.0f;
        result->m[2][0] = 0.0f;
        result->m[2][1] = 0.0f;
        result->m[2][2] = 1.0f;

        /* Success. */
        return 1;
    }

    det00 = (matrix->m[1][1] * matrix->m[2][2]) - (matrix->m[2][1] * matrix->m[1][2]);
    det01 = (matrix->m[2][0] * matrix->m[1][2]) - (matrix->m[1][0] * matrix->m[2][2]);
    det02 = (matrix->m[1][0] * matrix->m[2][1]) - (matrix->m[2][0] * matrix->m[1][1]);

    /* Compute determinant. */
    d = (matrix->m[0][0] * det00) + (matrix->m[0][1] * det01) + (matrix->m[0][2] * det02);

    /* Return 0 if there is no inverse matrix. */
    if (d == 0.0f)
        return 0;

    /* Compute reciprocal. */
    d = 1.0f / d;

    /* Determine if the matrix is affine. */
    isAffine = (matrix->m[2][0] == 0.0f) && (matrix->m[2][1] == 0.0f) && (matrix->m[2][2] == 1.0f);

    result->m[0][0] = d * det00;
    result->m[0][1] = d * ((matrix->m[2][1] * matrix->m[0][2]) - (matrix->m[0][1] * matrix->m[2][2]));
    result->m[0][2] = d * ((matrix->m[0][1] * matrix->m[1][2]) - (matrix->m[1][1] * matrix->m[0][2]));
    result->m[1][0] = d * det01;
    result->m[1][1] = d * ((matrix->m[0][0] * matrix->m[2][2]) - (matrix->m[2][0] * matrix->m[0][2]));
    result->m[1][2] = d * ((matrix->m[1][0] * matrix->m[0][2]) - (matrix->m[0][0] * matrix->m[1][2]));
    result->m[2][0] = isAffine ? 0.0f : d * det02;
    result->m[2][1] = isAffine ? 0.0f : d * ((matrix->m[2][0] * matrix->m[0][1]) - (matrix->m[0][0] * matrix->m[2][1]));
    result->m[2][2] = isAffine ? 1.0f : d * ((matrix->m[0][0] * matrix->m[1][1]) - (matrix->m[1][0] * matrix->m[0][1]));

    /* Success. */
    return 1;
}

/* Transform a 2D point by a given matrix. */
static int transform(vg_lite_point_t * result, vg_lite_float_t x, vg_lite_float_t y, vg_lite_matrix_t * matrix)
{
    vg_lite_float_t pt_x;
    vg_lite_float_t pt_y;
    vg_lite_float_t pt_w;

    /* Test for identity matrix. */
    if (matrix == NULL) {
        result->x = (int)x;
        result->y = (int)y;

        /* Success. */
        return 1;
    }

    /* Transform x, y, and w. */
    pt_x = (x * matrix->m[0][0]) + (y * matrix->m[0][1]) + matrix->m[0][2];
    pt_y = (x * matrix->m[1][0]) + (y * matrix->m[1][1]) + matrix->m[1][2];
    pt_w = (x * matrix->m[2][0]) + (y * matrix->m[2][1]) + matrix->m[2][2];

    if (pt_w <= 0.0f)
        return 0;

    /* Compute projected x and y. */
    result->x = (int)((pt_x / pt_w) + 0.5f);
    result->y = (int)((pt_y / pt_w) + 0.5f);

    /* Success. */
    return 1;
}

/*!
 Flush specific VG module.
 */
static vg_lite_error_t flush_target()
{
    vg_lite_error_t error = VG_LITE_SUCCESS;
    vg_lite_context_t *context = GET_CONTEXT();

    do {
        VG_LITE_BREAK_ERROR(push_state(context, 0x0A1B, 0x00000001));
        VG_LITE_BREAK_ERROR(push_stall(context, 7));
    } while (0);

    return error;
}

/****************** FAST_CLEAR feature implementation. ***************/
#if VG_TARGET_FAST_CLEAR
static vg_lite_error_t convert_color(vg_lite_buffer_format_t format, uint32_t value, uint32_t *result, int *bpp)
{
    vg_lite_error_t error = VG_LITE_SUCCESS;
    uint32_t r, g, b, a;
    int Bpp = 0;

    r = B(value);
    g = G(value);
    b = R(value);
    a = A(value);

    do {
        switch (format) {
            case VG_LITE_RGBA8888:
                *result = ARGB(a, b, g, r);
                Bpp = 32;
                break;

            case VG_LITE_BGRA8888:
                *result = ARGB(a, r, g, b);
                Bpp = 32;
                break;

            case VG_LITE_RGBX8888:
                *result = ARGB(0xff, b, g, r);
                Bpp = 32;
                break;

            case VG_LITE_BGRX8888:
                *result = ARGB(0xff, r, g, b);
                Bpp = 32;
                break;


            case VG_LITE_RGBA4444:
                *result = ARGB4(a, b, g, r);
                Bpp = 16;
                break;

            case VG_LITE_BGRA4444:
                *result = ARGB4(a, r, g, b);
                Bpp = 16;
                break;

            case VG_LITE_RGB565:
                *result = ((b & 0xf8) << 8) |
                ((g & 0xfc) << 3) |
                ((r & 0xf8) >> 3);
                Bpp = 16;
                break;

            case VG_LITE_BGR565:
                *result = ((r & 0xf8) << 8) |
                ((g & 0xfc) << 3) |
                ((b & 0xf8) >> 3);
                Bpp = 16;
                break;

            case VG_LITE_BGRA5551:
                *result = ((b & 0xf8) << 8) |
                ((g & 0xf8) << 3) |
                ((r & 0xf8) >> 2) |
                ((a & 0x80) >> 7);
                Bpp = 16;
                break;

            case VG_LITE_A8:
                *result = ARGB(a, a, a, a);
                Bpp = 8;
                break;

            case VG_LITE_L8:
                *result = ARGB(r, r, r, r);
                Bpp = 8;
                break;

            default:
                error = VG_LITE_NOT_SUPPORT;
                break;
        }
    } while (0);

    if (bpp != NULL) {
        *bpp = Bpp;
    }

    if (Bpp == 16) {
        *result = ((*result) << 16) | (*result);
    }
    return error;
}

/* Fill Target buffer by FC buffer. Only used in cmodel/fpga for verification. */
#if defined(DEBUG) || defined(_DEBUG)
static vg_lite_error_t fill_fc_target(vg_lite_buffer_t *target, vg_lite_buffer_t *fcb)
{
    vg_lite_error_t error = VG_LITE_SUCCESS;
    uint8_t *fc = (uint8_t *)fcb->memory;
    uint16_t *target16;
    uint32_t *target32;
    uint8_t *target8;
    uint32_t  clear32;
    int byte_done = 0;
    int i, j, k;
    int bpp;

    do {
        convert_color(target->format, s_context.clearValue, &clear32, &bpp);

        if (bpp == 32) {
            target32 = (uint32_t *)target->memory;
            for (i = 0; i < fcb->width; i++) {

                for (j = 0; j < 8; j++) {   /* Loop the bits*/

                    if (!(((*fc) >> j) & 1)) {
                        for (k = 0; k < 64 / 4; k++) {
                            target32[k] = clear32;
                            byte_done+=4;
                            if (byte_done >= target->stride * target->height) {
                                return error;
                            }
                        }
                    }

                    target32 += 64/4;
                }

                fc++;
            }
        }
        else if (bpp == 16){
            target16 = (uint16_t *)target->memory;
            for (i = 0; i < fcb->width; i++) {

                for (j = 0; j < 8; j++) {   /* Loop the bits*/

                    if (!(((*fc) >> j) & 1)) {
                        for (k = 0; k < 64 / 2; k++) {
                            target16[k] = (uint16_t)clear32;
                            byte_done+=2;
                            if (byte_done >= target->stride * target->height) {
                                return error;
                            }
                        }
                    }

                    target16 += 64/2;
                }

                fc++;
            }
        }
        else if (bpp == 8) {
            target8 = (uint8_t *)target->memory;
            for (i = 0; i < fcb->width; i++) {

                for (j = 0; j < 8; j++) {   /* Loop the bits*/

                    if (!(((*fc) >> j) & 1)) {
                        for (k = 0; k < 64; k++) {
                            target8[k] = (uint8_t)clear32;
                            byte_done++;
                            if (byte_done >= target->stride * target->height) {
                                return error;
                            }
                        }
                    }

                    target8 += 64;
                }

                fc++;
            }
        }
    } while (0);

    return error;
}
#endif

/* Update the fast_clear buffer when render target switched. */
static vg_lite_error_t update_fc_buffer(vg_lite_buffer_t *target)
{
    int rt_bytes;
    vg_lite_error_t error = VG_LITE_SUCCESS;
    vg_lite_context_t *context = GET_CONTEXT();
    vg_lite_kernel_allocate_t allocate;

    do {
        if (target == NULL) {
            error = VG_LITE_INVALID_ARGUMENT;
            break;
        }

        rt_bytes = target->stride * target->height;
        rt_bytes = VG_LITE_ALIGN(rt_bytes, (FC_BIT_TO_BYTES * 8));
        rt_bytes = rt_bytes / FC_BIT_TO_BYTES / 8;
        /* Only allocate new buffer when the allocated is not big enough. Yes*/
        if (rt_bytes > context->fcBuffer.stride ) {
            vg_lite_free(&context->fcBuffer);

            context->fcBuffer.width = rt_bytes;         /* The actually used bytes. */
            rt_bytes = VG_LITE_ALIGN(rt_bytes, FC_BURST_BYTES);     /* The allocated aligned bytes. */
            context->fcBuffer.stride = rt_bytes;
            allocate.bytes = rt_bytes;
            allocate.contiguous = 1;

            VG_LITE_BREAK_ERROR(vg_lite_kernel(VG_LITE_ALLOCATE, &allocate));
            context->fcBuffer.handle = allocate.memory_handle;
            context->fcBuffer.memory = allocate.memory;
            context->fcBuffer.address = allocate.memory_gpu;
        }
        else {
            /* Just update the fc buffer size. */
            context->fcBuffer.width = rt_bytes;
        }
        memset(context->fcBuffer.memory, 0xff, context->fcBuffer.stride);
    } while (0);

    return error;
}

/* Update FC registers and clear FC buffer. */
static vg_lite_error_t clear_fc(uint32_t value)
{
    vg_lite_error_t error = VG_LITE_SUCCESS;
    vg_lite_context_t *context = GET_CONTEXT();
    uint32_t bytes_to_clear = context->fcBuffer.stride / FC_BURST_BYTES;

    do {
        VG_LITE_BREAK_ERROR(push_state(context, 0x0A9A, context->fcBuffer.address));   /* FC buffer address. */
        VG_LITE_BREAK_ERROR(push_state(context, 0x0A9B, value));                       /* FC clear value. */
        VG_LITE_BREAK_ERROR(push_state(context, 0x0AB0, 0x80000000 | bytes_to_clear));   /* FC clear command. */
    } while (0);

    return error;
}

#if VG_TARGET_FC_DUMP
static int fc_buf_dump(vg_lite_buffer_t *target, vg_lite_buffer_t *fcb)
{
    int error = VG_LITE_SUCCESS;
    uint8_t *fc = (uint8_t *)fcb->memory;
    uint8_t *target8;
    int byte_done = 0;
    int target_bytes;
    int i, j;

    static unsigned s_cnt;
    unsigned cnt = s_cnt;

    FILE *fpFCBuf;
    FILE *fpTargetBuf;
    FILE *fpTargetBufInfo;
    char buf[256];

    s_cnt++;

    sprintf(buf, "vg255v2.fc_buf.f%04d.txt", cnt);
    fpFCBuf = fopen(buf, "wt");
    if (NULL == fpFCBuf) {
        fprintf(stderr, "[Warning] Open file \'%s\' fail.\n", buf);
        return -1;
    }

    sprintf(buf, "vg255v2.target_buf_info.f%04d.txt", cnt);
    fpTargetBufInfo = fopen(buf, "wt");
    if (NULL == fpTargetBufInfo) {
        fprintf(stderr, "[Warning] Open file \'%s\' fail.\n", buf);
        fclose(fpFCBuf);
        return -1;
    } else {
        fprintf(fpTargetBufInfo, "%-12s: %d\n", "format", target->format);
        fprintf(fpTargetBufInfo, "%-12s: %d\n", "tiled",  target->tiled);
        fprintf(fpTargetBufInfo, "%-12s: %d\n", "width",  target->width);
        fprintf(fpTargetBufInfo, "%-12s: %d\n", "height", target->height);
        fprintf(fpTargetBufInfo, "%-12s: %d\n", "stride", target->stride);

        fclose(fpTargetBufInfo);
    }

    sprintf(buf, "vg255v2.target_buf.f%04d.txt", cnt);
    fpTargetBuf = fopen(buf, "wt");
    if (NULL == fpTargetBuf) {
        fprintf(stderr, "[Warning] Open file \'%s\' fail.\n", buf);
        fclose(fpFCBuf);
        return -1;
    }

    /* Dump FC buffer & Dump target buffer */
    target8 = (uint8_t *)target->memory;
    target_bytes = target->stride * target->height;

    for (i = 0; i < fcb->width; ++i)
    {
        fprintf(fpFCBuf, "%02x\n", fc[i]);
        /* 1 byte of fc related with 512 bytes of target buffer */
        for (j = 0; j < 128; ++j) {
            fprintf(fpTargetBuf, "%02x",   byte_done < target_bytes ? target8[0] : 0);
            byte_done++;

            fprintf(fpTargetBuf, "%02x",   byte_done < target_bytes ? target8[1] : 0);
            byte_done++;

            fprintf(fpTargetBuf, "%02x",   byte_done < target_bytes ? target8[2] : 0);
            byte_done++;

            fprintf(fpTargetBuf, "%02x\n", byte_done < target_bytes ? target8[3] : 0);
            byte_done++;

            target8 += 4;
        }
    }

    fclose(fpFCBuf);
    fclose(fpTargetBuf);

    return error;
}
#endif /* VG_TARGET_FC_DUMP */

#endif

/* Set the current render target. */
static vg_lite_error_t set_render_target(vg_lite_buffer_t *target)
{
    vg_lite_error_t error = VG_LITE_SUCCESS;
    uint32_t yuv2rgb = 0;
    uint32_t uv_swiz = 0;
    int32_t tiled;

    if(target == NULL)
        return VG_LITE_INVALID_ARGUMENT;
    /* Skip if render target and scissor are not changed. */
    if ((s_context.rtbuffer != NULL) && (target == s_context.rtbuffer) &&
        !(memcmp(s_context.rtbuffer,target,sizeof(vg_lite_buffer_t))) &&
        (s_context.scissor_dirty == 0))
    {
        return VG_LITE_SUCCESS;
    }

    if ((target != NULL) &&
        (target->format == VG_LITE_YUY2 ||
         target->format == VG_LITE_AYUY2 ||
         target->format == VG_LITE_YUY2_TILED ||
         target->format == VG_LITE_AYUY2_TILED))
    {
        return VG_LITE_NOT_SUPPORT;
    }


#if VG_TARGET_FAST_CLEAR
    /* Flush target if necessary when switching. */
    if (s_context.rtbuffer != NULL) {    /* If it's not the first time to set target. */
        vg_lite_finish();
    }
    update_fc_buffer(target);
#else
    if (s_context.rtbuffer != NULL) {
        /* Flush the old target. */
        vg_lite_finish();
    }
#endif

    tiled = (target->tiled != VG_LITE_LINEAR) ? 0x10000000 : 0;

    if (((target->format >= VG_LITE_YUY2) &&
         (target->format <= VG_LITE_AYUY2)) ||
        ((target->format >= VG_LITE_YUY2_TILED) &&
         (target->format <= VG_LITE_AYUY2_TILED))) {
            yuv2rgb = convert_yuv2rgb(target->yuv.yuv2rgb);
            uv_swiz = convert_uv_swizzle(target->yuv.swizzle);
        }

    /* Program render target. */
    if (s_context.rtbuffer != target || memcmp(s_context.rtbuffer,target,sizeof(vg_lite_buffer_t)) ) {
        if(target->tiled == VG_LITE_TILED) {
            if((target->stride % DEST_ALIGNMENT_LIMITATION) != 0)
                return VG_LITE_INVALID_ARGUMENT;
        }
        VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A10,
           convert_target_format(target->format, s_context.capabilities) | 0x00010000 | uv_swiz | yuv2rgb));
           //convert_target_format(target->format, s_context.capabilities) | 0x00010000 | uv_swiz | yuv2rgb | 0x100));
        if (target->yuv.uv_planar)
        {   /* Program uv plane address if necessary. */
            VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A5C, target->yuv.uv_planar));
        }
        if (target->yuv.alpha_planar) {
            VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A5D, target->yuv.alpha_planar));
        }
        VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A11, target->address));
        VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A12, target->stride | tiled));
    }

    if (s_context.scissor_dirty != 0) {
        if (s_context.scissor_enabled) {
            VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A13, s_context.scissor[2] | (s_context.scissor[3] << 16)));
        }
        else {
            VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A13, target->width | (target->height << 16)));
        }
        s_context.scissor_dirty = 0;
    }
    else {
        VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A13, target->width | (target->height << 16)));
    }

    s_context.rtbuffer = target;

    return error;
}

static vg_lite_error_t set_interpolation_steps(vg_lite_buffer_t *target,
                                               vg_lite_float_t s_width,
                                               vg_lite_float_t s_height,
                                               vg_lite_matrix_t *matrix,
                                               vg_lite_point_t *pmin,
                                               vg_lite_point_t *pmax)
{
    vg_lite_point_t     point_min, point_max, temp;
    vg_lite_matrix_t    im;
    vg_lite_float_t     xs[3], ys[3], cs[3];
    int                 left, top, right, bottom;
    vg_lite_error_t     error = VG_LITE_SUCCESS;
    float               dx = 0.0f, dy = 0.0f;

    #define SET_MIN_MAX_POINT                               \
    do {                                                    \
        if (temp.x < point_min.x) point_min.x = temp.x;     \
        if (temp.y < point_min.y) point_min.y = temp.y;     \
        if (temp.x > point_max.x) point_max.x = temp.x;     \
        if (temp.y > point_max.y) point_max.y = temp.y;     \
    } while (0)

    #define ERR_LIMIT   0.0000610351562f

    /* Transform image point (0, 0) to screen. */
    if (!transform(&temp, 0.0f, 0.0f, matrix))
        return VG_LITE_INVALID_ARGUMENT;
    /* Set initial point. */
    point_min = temp;
    point_max = temp;
    /* Transform image point (0, height) to screen. */
    if (!transform(&temp, 0.0f, s_height, matrix))
        return VG_LITE_INVALID_ARGUMENT;
    SET_MIN_MAX_POINT;
    /* Transform image point (width, height) to screen. */
    if (!transform(&temp, s_width, s_height, matrix))
        return VG_LITE_INVALID_ARGUMENT;
    SET_MIN_MAX_POINT;
    /* Transform image point (width, 0) to screen. */
    if (!transform(&temp, s_width, 0.0f, matrix))
        return VG_LITE_INVALID_ARGUMENT;
    SET_MIN_MAX_POINT;
    /* Clip to target. */
    if (s_context.scissor_enabled) {
        left = s_context.scissor[0];
        top  = s_context.scissor[1];
        right= s_context.scissor[2];
        bottom = s_context.scissor[3];
    } else {
        left = top = 0;
        right = target->width;
        bottom = target->height;
    }
    point_min.x = MAX(point_min.x, left);
    point_min.y = MAX(point_min.y, top);
    point_max.x = MIN(point_max.x, right);
    point_max.y = MIN(point_max.y, bottom);
    /* Compute inverse matrix. */
    if (!inverse(&im, matrix))
        return VG_LITE_INVALID_ARGUMENT;
    /* Compute interpolation steps. */
    /* X step */
    xs[0] = im.m[0][0] / s_width;
    xs[1] = im.m[1][0] / s_height;
    xs[2] = im.m[2][0];
    /* Y step */
    ys[0] = im.m[0][1] / s_width;
    ys[1] = im.m[1][1] / s_height;
    ys[2] = im.m[2][1];
    /* C step 2 */
    cs[2] = 0.5f * (im.m[2][0] + im.m[2][1]) + im.m[2][2];
    /* Keep track of the rounding errors (underflow) */
    if (s_context.chip_id == 0x255) {
        /* Check if matrix has rotation or perspective transformations */
        if (matrix != NULL &&
            (matrix->m[0][1] != 0.0f || matrix->m[1][0] != 0.0f ||
             matrix->m[2][0] != 0.0f || matrix->m[2][1] != 0.0f ||
             matrix->m[2][2] != 1.0f)) {
            if (xs[0] != 0.0f && -ERR_LIMIT < xs[0] && xs[0] < ERR_LIMIT)
                dx = 0.5f * (point_max.x + point_min.x) * im.m[0][0];
            else if (ys[0] != 0.0f && -ERR_LIMIT < ys[0] && ys[0] < ERR_LIMIT)
                dx = 0.5f * (point_max.y + point_min.y) * im.m[0][1];
            if (xs[1] != 0.0f && -ERR_LIMIT < xs[1] && xs[1] < ERR_LIMIT)
                dy = 0.5f * (point_max.x + point_min.x) * im.m[1][0];
            else if (ys[1] != 0.0f && -ERR_LIMIT < ys[1] && ys[1] < ERR_LIMIT)
                dy = 0.5f * (point_max.y + point_min.y) * im.m[1][1];
        }
    }
    /* C step 0, 1*/
    cs[0] = (0.5f * (im.m[0][0] + im.m[0][1]) + im.m[0][2] + dx) / s_width;
    cs[1] = (0.5f * (im.m[1][0] + im.m[1][1]) + im.m[1][2] + dy) / s_height;
    /* Set command buffer */
    VG_LITE_RETURN_ERROR(push_state_ptr(&s_context, 0x0A18, (void *)&cs[0]));
    VG_LITE_RETURN_ERROR(push_state_ptr(&s_context, 0x0A19, (void *)&cs[1]));
    VG_LITE_RETURN_ERROR(push_state_ptr(&s_context, 0x0A1A, (void *)&cs[2]));
    VG_LITE_RETURN_ERROR(push_state_ptr(&s_context, 0x0A1C, (void *)&xs[0]));
    VG_LITE_RETURN_ERROR(push_state_ptr(&s_context, 0x0A1D, (void *)&xs[1]));
    VG_LITE_RETURN_ERROR(push_state_ptr(&s_context, 0x0A1E, (void *)&xs[2]));
    VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A1F, 0x00000001));
    VG_LITE_RETURN_ERROR(push_state_ptr(&s_context, 0x0A20, (void *)&ys[0]));
    VG_LITE_RETURN_ERROR(push_state_ptr(&s_context, 0x0A21, (void *)&ys[1]));
    VG_LITE_RETURN_ERROR(push_state_ptr(&s_context, 0x0A22, (void *)&ys[2]));
    if (pmin) {
        pmin->x = point_min.x;
        pmin->y = point_min.y;
    }
    if (pmax) {
        pmax->x = point_max.x;
        pmax->y = point_max.y;
    }
    return VG_LITE_SUCCESS;
}

/*************** API Functions ***********************************************/
vg_lite_error_t vg_lite_clear(vg_lite_buffer_t * target,
                              vg_lite_rectangle_t * rectangle,
                              vg_lite_color_t color)
{
    vg_lite_error_t error;
    int32_t x, y, width, height;
    uint32_t color32;

    error = set_render_target(target);
    if (error != VG_LITE_SUCCESS) {
        return error;
    }

    /* Get rectangle. */
    x = (rectangle != NULL) ? rectangle->x : 0;
    y = (rectangle != NULL) ? rectangle->y : 0;
    width  = (rectangle != NULL) ? rectangle->width : s_context.rtbuffer->width;
    height = (rectangle != NULL) ? rectangle->height : s_context.rtbuffer->height;

    /* Compute the valid rectangle. */
    if (x < 0)
    {
        width += x;
        x = 0;
    }
    if (y < 0)
    {
        height += y;
        y = 0;
    }

    if (s_context.scissor_enabled)
    {
        int right, bottom;
        right = x + width;
        bottom = y + height;

        /* Bounds check. */
        if ((s_context.scissor[0] >= x + width) ||
            (s_context.scissor[2] <= x) ||
            (s_context.scissor[1] >= y + height) ||
            (s_context.scissor[3] <= y))
        {
            /* Do nothing. */
            return VG_LITE_SUCCESS;
        }
        /* Intersects the scissor and the rectangle. */
        x = (x > s_context.scissor[0] ? x : s_context.scissor[0]);
        y = (y > s_context.scissor[1] ? y : s_context.scissor[1]);
        right = (right < s_context.scissor[2]  ? right : s_context.scissor[2]);
        bottom = (bottom < s_context.scissor[3] ? bottom : s_context.scissor[3]);
        width = right - x;
        height = bottom - y;
    }

    /* Get converted color when target is in L8 format. */
    color32 = (target->format == VG_LITE_L8) ? rgb_to_l(color) : color;

#if VG_TARGET_FAST_CLEAR
    if ((rectangle == NULL) ||
        ((x == 0) && (y == 0)  &&
         (width == s_context.rtbuffer->width) &&
         (height  == s_context.rtbuffer->height))) {
            s_context.clearValue = color32;
            convert_color(s_context.rtbuffer->format, color32, &color32, NULL);
            clear_fc((uint32_t)color32);
    }
    else
#endif
    {
        /* Setup the command buffer. */
        VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A00, 0x00000001));
        //VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A00, 0x10000001));
        VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A02, color32));
        VG_LITE_RETURN_ERROR(push_rectangle(&s_context, x, y, width, height));
    }

    /* Success. */
    return VG_LITE_SUCCESS;
}

vg_lite_error_t vg_lite_blit(vg_lite_buffer_t * target,
                             vg_lite_buffer_t * source,
                             vg_lite_matrix_t * matrix,
                             vg_lite_blend_t blend,
                             vg_lite_color_t color,
                             vg_lite_filter_t filter)
{
    vg_lite_error_t error;
    vg_lite_point_t point_min, point_max;
    uint32_t imageMode;
    uint32_t blend_mode;
    uint32_t transparency_mode = 0;
    vg_lite_blend_t forced_blending = blend;
    uint32_t conversion = 0;
    uint32_t tiled_source;

    error = set_render_target(target);
    if (error != VG_LITE_SUCCESS) {
        return error;
    }

    transparency_mode = (source->transparency_mode == VG_LITE_IMAGE_TRANSPARENT ? 0x8000:0);
    /* Check if the specified matrix has rotation or perspective. */
    if (   (matrix != NULL)
        && (   (matrix->m[0][1] != 0.0f)
            || (matrix->m[1][0] != 0.0f)
            || (matrix->m[2][0] != 0.0f)
            || (matrix->m[2][1] != 0.0f)
            || (matrix->m[2][2] != 1.0f)
            )
        && (   blend == VG_LITE_BLEND_NONE
            || blend == VG_LITE_BLEND_SRC_IN
            || blend == VG_LITE_BLEND_DST_IN
            )
        ) {
            if(vg_lite_query_feature(gcFEATURE_BIT_VG_BORDER_CULLING)) {
                /* Mark that we have rotation. */
                transparency_mode = 0x8000;
            }else
            {
                blend_mode = VG_LITE_BLEND_SRC_OVER;
            }

    }

    /* Check whether L8 is supported or not. */
    if ((target->format == VG_LITE_L8) && ((source->format != VG_LITE_L8) && (source->format != VG_LITE_A8))) {
        conversion = 0x80000000;
    }

    /* determine if source specify bytes are aligned */
    error = _check_source_aligned(source->format,source->stride);
    if (error != VG_LITE_SUCCESS) {
        return error;
    }

    /* Determine image mode (NORMAL, NONE or MULTIPLY) depending on the color. */
    imageMode = (source->image_mode == VG_LITE_NONE_IMAGE_MODE) ? 0 : (source->image_mode == VG_LITE_MULTIPLY_IMAGE_MODE) ? 0x00002000 : 0x00001000;
    blend_mode = convert_blend(forced_blending);
    tiled_source = (source->tiled != VG_LITE_LINEAR) ? 0x10000000 : 0 ;

    /* Setup the command buffer. */
    VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A00, 0x00000001 | imageMode | blend_mode | transparency_mode));
    //VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A00, 0x10000001 | imageMode | blend_mode | transparency_mode));
    VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A02, color));

    VG_LITE_RETURN_ERROR(set_interpolation_steps(target, source->width, source->height, matrix, &point_min, &point_max));

    if(source->transparency_mode == VG_LITE_IMAGE_OPAQUE){
        VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A25, convert_source_format(source->format) | filter | conversion | 0x01000100));
    } else {
        VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A25, convert_source_format(source->format) | filter | conversion | 0x00000100));
    }

    VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A27, 0));
    VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A29, source->address));

    VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A2B, source->stride | tiled_source));
    VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A2D, 0));
    VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A2F, source->width | (source->height << 16)));
    VG_LITE_RETURN_ERROR(push_rectangle(&s_context, point_min.x, point_min.y, point_max.x - point_min.x,
                                        point_max.y - point_min.y));
    error = flush_target();
    vglitemDUMP_BUFFER("image", source->address, source->memory, 0, (source->stride)*(source->height));

#if DUMP_IMAGE
    dump_img(source->memory, source->width, source->height, source->format);
#endif

    return error;
}

vg_lite_error_t vg_lite_blit_rect(vg_lite_buffer_t * target,
                                 vg_lite_buffer_t * source,
                                 uint32_t         * rect,
                                 vg_lite_matrix_t * matrix,
                                 vg_lite_blend_t blend,
                                 vg_lite_color_t color,
                                 vg_lite_filter_t filter)
{
    vg_lite_error_t error;
    vg_lite_point_t point_min, point_max;
    uint32_t imageMode;
    uint32_t transparency_mode = 0;
    uint32_t blend_mode;
    vg_lite_blend_t forced_blending = blend;
    uint32_t conversion = 0;
    uint32_t tiled_source;
    uint32_t rect_x = 0, rect_y = 0, rect_w = 0, rect_h = 0;

    error = set_render_target(target);
    if (error != VG_LITE_SUCCESS) {
        return error;
    }

    transparency_mode = (source->transparency_mode == VG_LITE_IMAGE_TRANSPARENT ? 0x8000:0);
    /* Check if the specified matrix has rotation or perspective. */
    if (   (matrix != NULL)
        && (   (matrix->m[0][1] != 0.0f)
            || (matrix->m[1][0] != 0.0f)
            || (matrix->m[2][0] != 0.0f)
            || (matrix->m[2][1] != 0.0f)
            || (matrix->m[2][2] != 1.0f)
            )
        && (   blend == VG_LITE_BLEND_NONE
            || blend == VG_LITE_BLEND_SRC_IN
            || blend == VG_LITE_BLEND_DST_IN
            )
        ) {
            if(vg_lite_query_feature(gcFEATURE_BIT_VG_BORDER_CULLING)) {
                /* Mark that we have rotation. */
                transparency_mode = 0x8000;
            }else
            {
                blend_mode = VG_LITE_BLEND_SRC_OVER;
            }

    }

    /* Check whether L8 is supported or not. */
    if ((target->format == VG_LITE_L8) && ((source->format != VG_LITE_L8) && (source->format != VG_LITE_A8))) {
        conversion = 0x80000000;
    }

    /* determine if source specify bytes are aligned */
    error = _check_source_aligned(source->format,source->stride);
    if (error != VG_LITE_SUCCESS) {
        return error;
    }
    /* Set source region. */
    if (rect != NULL) {
        rect_x = rect[0];
        rect_y = rect[1];
        rect_w = rect[2];
        rect_h = rect[3];

        if ((rect_x > (uint32_t)source->width) || (rect_y > (uint32_t)source->height) ||
            (rect_w == 0) || (rect_h == 0))
        {
            /*No intersection*/
            return VG_LITE_INVALID_ARGUMENT;
        }

        if (rect_x + rect_w > (uint32_t)source->width)
        {
            rect_w = source->width - rect_x;
        }

        if (rect_y + rect_h > (uint32_t)source->height)
        {
            rect_h = source->height - rect_y;
        }
    }
    else {
        rect_x = rect_y = 0;
        rect_w = source->width;
        rect_h = source->height;
    }
    /* Determine image mode (NORMAL, NONE or MULTIPLY) depending on the color. */
    imageMode = (source->image_mode == VG_LITE_NONE_IMAGE_MODE) ? 0 : (source->image_mode == VG_LITE_MULTIPLY_IMAGE_MODE) ? 0x00002000 : 0x00001000;
    blend_mode = convert_blend(forced_blending);
    tiled_source = (source->tiled != VG_LITE_LINEAR) ? 0x10000000 : 0 ;

    /* Setup the command buffer. */
    VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A00, 0x00000001 | imageMode | blend_mode | transparency_mode));
    //VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A00, 0x10000001 | imageMode | blend_mode | transparency_mode));
    VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A02, color));

    VG_LITE_RETURN_ERROR(set_interpolation_steps(target, rect_w, rect_h, matrix, &point_min, &point_max));

    if(source->transparency_mode == VG_LITE_IMAGE_OPAQUE){
        VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A25, convert_source_format(source->format) | filter | conversion | 0x01000100));
    } else {
        VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A25, convert_source_format(source->format) | filter | conversion | 0x00000100));
    }

    VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A27, 0));
    VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A29, source->address));

    VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A2B, source->stride | tiled_source));
    VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A2D, rect_x | (rect_y << 16)));
    VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A2F, rect_w | (rect_h << 16)));
    VG_LITE_RETURN_ERROR(push_rectangle(&s_context, point_min.x, point_min.y, point_max.x - point_min.x,
                                        point_max.y - point_min.y));
    error = flush_target();
    vglitemDUMP_BUFFER("image", source->address, source->memory, 0, (source->stride)*(source->height));
#if DUMP_IMAGE
    dump_img(source->memory, source->width, source->height, source->format);
#endif

    return error;
}

/* Program initial states for tessellation buffer. */
static vg_lite_error_t program_tessellation(vg_lite_context_t *context)
{
    vg_lite_error_t error = VG_LITE_SUCCESS;
    uint32_t tessellation_size;

    tessellation_size = (  context->tsbuffer.tessellation_buffer_size[2]
                         ? context->tsbuffer.tessellation_buffer_size[2]
                         : context->tsbuffer.tessellation_buffer_size[1]
                         );
    /* Since TS buffer won't change during runtime, we program it here in initialization. */
    /* Program tessellation buffer: input for VG module. */
    VG_LITE_RETURN_ERROR(push_state(context, 0x0A30, context->tsbuffer.tessellation_buffer_gpu[0]));   /* Tessellation buffer address. */
    VG_LITE_RETURN_ERROR(push_state(context, 0x0A31, context->tsbuffer.tessellation_buffer_gpu[1]));   /* L1 address of tessellation buffer. */
    VG_LITE_RETURN_ERROR(push_state(context, 0x0A32, context->tsbuffer.tessellation_buffer_gpu[2]));   /* L2 address of tessellation buffer. */
    VG_LITE_RETURN_ERROR(push_state(context, 0x0A33, context->tsbuffer.tessellation_stride));
    /* Program tessellation control: for TS module. */
    VG_LITE_RETURN_ERROR(push_state(context, 0x0A35, context->tsbuffer.tessellation_buffer_gpu[0]));
    VG_LITE_RETURN_ERROR(push_state(context, 0x0A36, context->tsbuffer.tessellation_buffer_gpu[1]));
    VG_LITE_RETURN_ERROR(push_state(context, 0x0A37, context->tsbuffer.tessellation_buffer_gpu[2]));
    VG_LITE_RETURN_ERROR(push_state(context, 0x0A38, context->tsbuffer.tessellation_stride));
    VG_LITE_RETURN_ERROR(push_state(context, 0x0A3A, context->tsbuffer.tessellation_width_height));

    VG_LITE_RETURN_ERROR(push_state(context, 0x0A3D, tessellation_size / 64));

    return error;
}

vg_lite_error_t vg_lite_init(int32_t tessellation_width,
                             int32_t tessellation_height)
{
    vg_lite_error_t error;
    vg_lite_kernel_initialize_t initialize;

    s_context.rtbuffer = NULL;

    if (tessellation_width <= 0) {
        tessellation_width = 0;
        tessellation_height = 0;
    }
    if (tessellation_height <= 0) {
        tessellation_height = 0;
        tessellation_width = 0;
    }
    tessellation_width  = VG_LITE_ALIGN(tessellation_width, 16);

    /* Allocate a command buffer and a tessellation buffer. */
    initialize.command_buffer_size = command_buffer_size;
    initialize.tessellation_width = tessellation_width;
    initialize.tessellation_height = tessellation_height;
    initialize.context = &s_context.context;
    VG_LITE_RETURN_ERROR(vg_lite_kernel(VG_LITE_INITIALIZE, &initialize));

    /* Save draw context. */
    s_context.capabilities = initialize.capabilities;
    s_context.command_buffer[0] = (uint8_t *)initialize.command_buffer[0];
    s_context.command_buffer[1] = (uint8_t *)initialize.command_buffer[1];
    s_context.command_buffer_size = initialize.command_buffer_size;
    s_context.command_offset[0] = 0;
    s_context.command_offset[1] = 0;

    if ((tessellation_width  > 0) &&
        (tessellation_height > 0))
    {
        /* Set and Program Tessellation Buffer states. */
        s_context.tsbuffer.tessellation_buffer_gpu[0] = initialize.tessellation_buffer_gpu[0];
        s_context.tsbuffer.tessellation_buffer_gpu[1] = initialize.tessellation_buffer_gpu[1];
        s_context.tsbuffer.tessellation_buffer_gpu[2] = initialize.tessellation_buffer_gpu[2];
        s_context.tsbuffer.tessellation_buffer_logic[0] = initialize.tessellation_buffer_logic[0];
        s_context.tsbuffer.tessellation_buffer_logic[1] = initialize.tessellation_buffer_logic[1];
        s_context.tsbuffer.tessellation_buffer_logic[2] = initialize.tessellation_buffer_logic[2];
        s_context.tsbuffer.tessellation_stride = initialize.tessellation_stride;
        s_context.tsbuffer.tessellation_width_height = initialize.tessellation_width_height;
        s_context.tsbuffer.tessellation_buffer_size[0] = initialize.tessellation_buffer_size[0];
        s_context.tsbuffer.tessellation_buffer_size[1] = initialize.tessellation_buffer_size[1];
        s_context.tsbuffer.tessellation_buffer_size[2] = initialize.tessellation_buffer_size[2];
        s_context.tsbuffer.tessellation_shift          = initialize.tessellation_shift;

        VG_LITE_RETURN_ERROR(program_tessellation(&s_context));
    }

    /* Fill feature table. */
    if (!s_ftable.ftflag){
        VG_LITE_RETURN_ERROR(fill_feature_table(s_ftable.ftable));
    }

#if VG_TARGET_FAST_CLEAR
    /* Reset the FAST_CLEAR buffer. */
    memset(&s_context.fcBuffer, 0, sizeof(s_context.fcBuffer));
    s_context.fcBuffer.format = VG_LITE_A8;
    s_context.fcBuffer.height = 1;
    s_context.clearValue = 0;
#endif

    /* Init scissor rect. */
    s_context.scissor[0] =
    s_context.scissor[1] =
    s_context.scissor[2] =
    s_context.scissor[3] = 0;
#if DUMP_CAPTURE
    _SetDumpFileInfo();
#endif
    return VG_LITE_SUCCESS;
}

vg_lite_error_t vg_lite_draw(vg_lite_buffer_t * target,
                             vg_lite_path_t * path,
                             vg_lite_fill_t fill_rule,
                             vg_lite_matrix_t * matrix,
                             vg_lite_blend_t blend,
                             vg_lite_color_t color)
{
    uint32_t blend_mode;
    uint32_t format, quality, tiling, fill;
    uint32_t tessellation_size;
    vg_lite_error_t error;
    vg_lite_point_t point_min = {0}, point_max = {0}, temp = {0};
    int x, y, width, height;
    uint8_t ts_is_fullscreen = 0;
    uint32_t return_offset = 0;
    vg_lite_kernel_free_t free_memory;
    vg_lite_kernel_allocate_t memory;

    if(!vg_lite_query_feature(gcFEATURE_BIT_VG_QUALITY_8X) && path->quality == VG_LITE_UPPER){
        return VG_LITE_NOT_SUPPORT;
    }

    error = set_render_target(target);
    if (error != VG_LITE_SUCCESS) {
        return error;
    }

    width = s_context.tsbuffer.tessellation_width_height & 0xFFFF;
    height = s_context.tsbuffer.tessellation_width_height >> 16;

    if ((target->width <= width) && (target->height <= height))
    {
        ts_is_fullscreen = 1;
        point_min.x = 0;
        point_min.y = 0;
        point_max.x = target->width;
        point_max.y = target->height;
    }

    if (ts_is_fullscreen == 0){
        transform(&temp, (vg_lite_float_t)path->bounding_box[0], (vg_lite_float_t)path->bounding_box[1], matrix);
        point_min = point_max = temp;

        transform(&temp, (vg_lite_float_t)path->bounding_box[2], (vg_lite_float_t)path->bounding_box[1], matrix);
        if (temp.x < point_min.x) point_min.x = temp.x;
        if (temp.y < point_min.y) point_min.y = temp.y;
        if (temp.x > point_max.x) point_max.x = temp.x;
        if (temp.y > point_max.y) point_max.y = temp.y;

        transform(&temp, (vg_lite_float_t)path->bounding_box[2], (vg_lite_float_t)path->bounding_box[3], matrix);
        if (temp.x < point_min.x) point_min.x = temp.x;
        if (temp.y < point_min.y) point_min.y = temp.y;
        if (temp.x > point_max.x) point_max.x = temp.x;
        if (temp.y > point_max.y) point_max.y = temp.y;

        transform(&temp, (vg_lite_float_t)path->bounding_box[0], (vg_lite_float_t)path->bounding_box[3], matrix);
        if (temp.x < point_min.x) point_min.x = temp.x;
        if (temp.y < point_min.y) point_min.y = temp.y;
        if (temp.x > point_max.x) point_max.x = temp.x;
        if (temp.y > point_max.y) point_max.y = temp.y;

        if (point_min.x < 0) point_min.x = 0;
        if (point_min.y < 0) point_min.y = 0;
        if (point_max.x > target->width) point_max.x = target->width;
        if (point_max.y > target->height) point_max.y = target->height;

        if (s_context.scissor_enabled) {
            point_min.x = MAX(point_min.x, s_context.scissor[0]);
            point_min.y = MAX(point_min.y, s_context.scissor[1]);
            point_max.x = MIN(point_max.x, s_context.scissor[2]);
            point_max.y = MIN(point_max.y, s_context.scissor[3]);
        }
    }

    /* Convert states into hardware values. */
    blend_mode = convert_blend(blend);
    format = convert_path_format(path->format);
    quality = convert_path_quality(path->quality);
    tiling = (s_context.capabilities.cap.tiled == 2) ? 0x2000000 : 0;
    fill = (fill_rule == VG_LITE_FILL_EVEN_ODD) ? 0x10 : 0;
    tessellation_size = (  s_context.tsbuffer.tessellation_buffer_size[2]
                         ? s_context.tsbuffer.tessellation_buffer_size[2]
                         : s_context.tsbuffer.tessellation_buffer_size[1]
                         );

    /* Setup the command buffer. */
    /* Program color register. */
    VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A00, s_context.capabilities.cap.tiled | blend_mode));
    //VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A00, 0x10000000 | s_context.capabilities.cap.tiled | blend_mode));
    VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A02, color));
    /* Program tessellation control: for TS module. */
    VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A34, 0x01000200 | format | quality | tiling | fill));
    VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A3B, 0x3F800000));      /* Path tessellation SCALE. */
    VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A3C, 0x00000000));      /* Path tessellation BIAS.  */
    /* Program matrix. */
    VG_LITE_RETURN_ERROR(push_state_ptr(&s_context, 0x0A40, (void *) &matrix->m[0][0]));
    VG_LITE_RETURN_ERROR(push_state_ptr(&s_context, 0x0A41, (void *) &matrix->m[0][1]));
    VG_LITE_RETURN_ERROR(push_state_ptr(&s_context, 0x0A42, (void *) &matrix->m[0][2]));
    VG_LITE_RETURN_ERROR(push_state_ptr(&s_context, 0x0A43, (void *) &matrix->m[1][0]));
    VG_LITE_RETURN_ERROR(push_state_ptr(&s_context, 0x0A44, (void *) &matrix->m[1][1]));
    VG_LITE_RETURN_ERROR(push_state_ptr(&s_context, 0x0A45, (void *) &matrix->m[1][2]));

    /* DDRLess does not support uploading path data. */
    if (VLM_PATH_GET_UPLOAD_BIT(*path) == 1)
    {
        if (path->path_changed != 0) {
            if (path->uploaded.handle != NULL) {
                free_memory.memory_handle = path->uploaded.handle;
                VG_LITE_RETURN_ERROR(vg_lite_kernel(VG_LITE_FREE, &free_memory));
                path->uploaded.address = 0;
                path->uploaded.memory = NULL;
                path->uploaded.handle = NULL;
            }
            /* Allocate memory for the path data. */
            memory.bytes = 16 + VG_LITE_ALIGN(path->path_length, 8);
            return_offset = (8 + VG_LITE_ALIGN(path->path_length, 8)) / 4;
            memory.contiguous = 1;
            VG_LITE_RETURN_ERROR(vg_lite_kernel(VG_LITE_ALLOCATE, &memory));
            ((uint64_t *) memory.memory)[(path->path_length + 7) / 8] = 0;
            ((uint32_t *) memory.memory)[0] = VG_LITE_DATA((path->path_length + 7) / 8);
            ((uint32_t *) memory.memory)[1] = 0;
            memcpy((uint8_t *) memory.memory + 8, path->path, path->path_length);
            ((uint32_t *) memory.memory)[return_offset] = VG_LITE_RETURN();
            ((uint32_t *) memory.memory)[return_offset + 1] = 0;

            path->uploaded.handle = memory.memory_handle;
            path->uploaded.memory = memory.memory;
            path->uploaded.address = memory.memory_gpu;
            path->uploaded.bytes  = memory.bytes;
            path->path_changed = 0;
        }
    }

    if (VLM_PATH_GET_UPLOAD_BIT(*path) == 1) {
        vglitemDUMP_BUFFER("path", path->uploaded.address, (uint8_t *)(path->uploaded.memory), 0, path->uploaded.bytes);
    }
    vglitemDUMP("@[memory 0x%08X 0x%08X]", s_context.tsbuffer.tessellation_buffer_gpu[0], s_context.tsbuffer.tessellation_buffer_size[0]);
    /* Setup tessellation loop. */
    for (y = point_min.y; y < point_max.y; y += height) {
        for (x = point_min.x; x < point_max.x; x += width) {
            /* Tessellate path. */
            VG_LITE_RETURN_ERROR(push_stall(&s_context, 15));
            VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A1B, 0x00011000));
            VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A01, x | (y << 16)));
            VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A39, x | (y << 16)));
            VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A3D, tessellation_size / 64));

            if (VLM_PATH_GET_UPLOAD_BIT(*path) == 1) {
                VG_LITE_RETURN_ERROR(push_call(&s_context, path->uploaded.address, path->uploaded.bytes));
#if  (DUMP_COMMAND)
                if (strncmp(filename, "Commandbuffer", 13)) {
                    sprintf(filename, "Commandbuffer_pid%d.txt", getpid());
                }

                fp = fopen(filename, "a");

                if (fp == NULL)
                    printf("error!\n");

                fprintf(fp, "Command buffer: 0x%08x, 0x%08x,\n",
                        ((uint32_t *) memory.memory)[0], 0);

                unsigned char* pt = (unsigned char*) memory.memory;

                for(int i = 8; i <= return_offset * 4 - 1; i = i + 4)
                {
                    if (i % 8 == 0)
                        fprintf(fp, "Command buffer: ");

                    if (i % 4 == 0)
                        fprintf(fp, "0x");

                    for (int j = 3; j >= 0; --j)
                        fprintf(fp, "%02x", pt[i + j]);

                    if ((i / 4 + 1) % 2 == 0)
                        fprintf(fp, ",\n");
                    else
                        fprintf(fp, ", ");
                }

                fprintf(fp, "Command buffer: 0x%08x, 0x%08x,\n",
                        ((uint32_t *) memory.memory)[return_offset], 0);

                fclose(fp);
                fp = NULL;
#endif
            } else {
                push_data(&s_context, path->path_length, path->path);
            }
        }
    }

    /* Finialize command buffer. */
    VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A34, 0));
    return error;
}

vg_lite_error_t vg_lite_close(void)
{
    vg_lite_error_t error;
    vg_lite_kernel_terminate_t terminate;

#if VG_TARGET_FAST_CLEAR
    if (s_context.fcBuffer.handle != NULL) {
        vg_lite_free(&s_context.fcBuffer);
    }
#endif

    /* Termnate the draw context. */
    terminate.context = &s_context.context;
    VG_LITE_RETURN_ERROR(vg_lite_kernel(VG_LITE_TERMINATE, &terminate));

    /* Reset the draw context. */
    _memset(&s_context, 0, sizeof(s_context));

#if DUMP_CAPTURE
    _SetDumpFileInfo();
#endif
    return VG_LITE_SUCCESS;
}

/* Handle tiled & yuv allocation. Currently including NV12, ANV12, YV12, YV16, NV16, YV24. */
static  vg_lite_error_t _allocate_tiled_yuv_planar(vg_lite_buffer_t *buffer)
{
    vg_lite_error_t error = VG_LITE_SUCCESS;
    uint32_t    yplane_size = 0;
    vg_lite_kernel_allocate_t allocate, uv_allocate, v_allocate;

    if ((buffer->format < VG_LITE_NV12) || (buffer->format > VG_LITE_ANV12_TILED)
        || (buffer->format == VG_LITE_AYUY2) || (buffer->format == VG_LITE_YUY2_TILED))
    {
        return error;
    }

    /* For NV12, there are 2 planes (Y, UV);
     For ANV12, there are 3 planes (Y, UV, Alpha).
     Each plane must be aligned by (4, 8).
     Then Y plane must be aligned by (8, 8).
     For YVxx, there are 3 planes (Y, U, V).
     YV12 is similar to NV12, both YUV420 format.
     YV16 and NV16 are YUV422 format.
     YV24 is YUV444 format.
     */
    buffer->width = VG_LITE_ALIGN(buffer->width, 8);
    buffer->height = VG_LITE_ALIGN(buffer->height, 8);
    buffer->stride = VG_LITE_ALIGN(buffer->width, 128);

    switch (buffer->format) {
        case VG_LITE_NV12:
        case VG_LITE_ANV12:
        case VG_LITE_NV12_TILED:
        case VG_LITE_ANV12_TILED:
            buffer->yuv.uv_stride = buffer->stride;
            buffer->yuv.alpha_stride = buffer->stride;
            buffer->yuv.uv_height = buffer->height / 2;
            break;

        case VG_LITE_NV16:
            buffer->yuv.uv_stride = buffer->stride;
            buffer->yuv.uv_height = buffer->height;
            break;

        case VG_LITE_YV12:
            buffer->yuv.uv_stride =
            buffer->yuv.v_stride = buffer->stride / 2;
            buffer->yuv.uv_height =
            buffer->yuv.v_height = buffer->height / 2;
            break;

        case VG_LITE_YV16:
            buffer->yuv.uv_stride =
            buffer->yuv.v_stride = buffer->stride;
            buffer->yuv.uv_height =
            buffer->yuv.v_height = buffer->height / 2;
            break;

        case VG_LITE_YV24:
            buffer->yuv.uv_stride =
            buffer->yuv.v_stride = buffer->stride;
            buffer->yuv.uv_height =
            buffer->yuv.v_height = buffer->height;
            break;

        default:
            return error;
    }

    yplane_size = buffer->stride * buffer->height;

    /* Allocate buffer memory: Y. */
    allocate.bytes = yplane_size;
    allocate.contiguous = 1;
    VG_LITE_RETURN_ERROR(vg_lite_kernel(VG_LITE_ALLOCATE, &allocate));

    /* Save the allocation. */
    buffer->handle  = allocate.memory_handle;
    buffer->memory  = allocate.memory;
    buffer->address = allocate.memory_gpu;

    if ((buffer->format == VG_LITE_NV12) || (buffer->format == VG_LITE_ANV12)
        || (buffer->format == VG_LITE_NV16) || (buffer->format == VG_LITE_NV12_TILED)
        || (buffer->format == VG_LITE_ANV12_TILED)) {
        /* Allocate buffer memory: UV. */
        uv_allocate.bytes = buffer->yuv.uv_stride * buffer->yuv.uv_height;
        VG_LITE_RETURN_ERROR(vg_lite_kernel(VG_LITE_ALLOCATE, &uv_allocate));
        buffer->yuv.uv_handle = uv_allocate.memory_handle;
        buffer->yuv.uv_memory = uv_allocate.memory;
        buffer->yuv.uv_planar = uv_allocate.memory_gpu;

        if ((buffer->format == VG_LITE_ANV12) || (buffer->format == VG_LITE_ANV12_TILED)) {
            uv_allocate.bytes = yplane_size;
            VG_LITE_RETURN_ERROR(vg_lite_kernel(VG_LITE_ALLOCATE, &uv_allocate));
            buffer->yuv.alpha_planar = uv_allocate.memory_gpu;
        }
    } else {
        /* Allocate buffer memory: U, V. */
        uv_allocate.bytes = buffer->yuv.uv_stride * buffer->yuv.uv_height;
        VG_LITE_RETURN_ERROR(vg_lite_kernel(VG_LITE_ALLOCATE, &uv_allocate));
        buffer->yuv.uv_handle = uv_allocate.memory_handle;
        buffer->yuv.uv_memory = uv_allocate.memory;
        buffer->yuv.uv_planar = uv_allocate.memory_gpu;

        v_allocate.bytes = buffer->yuv.v_stride * buffer->yuv.v_height;
        VG_LITE_RETURN_ERROR(vg_lite_kernel(VG_LITE_ALLOCATE, &v_allocate));
        buffer->yuv.v_handle = v_allocate.memory_handle;
        buffer->yuv.v_memory = v_allocate.memory;
        buffer->yuv.v_planar = v_allocate.memory_gpu;
    }

    return error;
}

vg_lite_error_t vg_lite_allocate(vg_lite_buffer_t * buffer)
{
    vg_lite_error_t error = VG_LITE_SUCCESS;
    vg_lite_kernel_allocate_t allocate;

    /* Width should be 16-pixel aligned. */
    buffer->width = ((buffer->width + 15) & ~0xf);

    /* Reset planar. */
    buffer->yuv.uv_planar =
    buffer->yuv.v_planar =
    buffer->yuv.alpha_planar = 0;

    /* Align height in case format is tiled. */
    if (buffer->format >= VG_LITE_YUY2 && buffer->format <= VG_LITE_NV16) {
        buffer->height = VG_LITE_ALIGN(buffer->height, 4);
        buffer->yuv.swizzle = VG_LITE_SWIZZLE_UV;
    }

    if (buffer->format >= VG_LITE_YUY2_TILED && buffer->format <= VG_LITE_AYUY2_TILED) {
        buffer->height = VG_LITE_ALIGN(buffer->height, 4);
        buffer->tiled = VG_LITE_TILED;
        buffer->yuv.swizzle = VG_LITE_SWIZZLE_UV;
    }

    if ((buffer->format >= VG_LITE_NV12 && buffer->format <= VG_LITE_ANV12_TILED
         && buffer->format != VG_LITE_AYUY2 && buffer->format != VG_LITE_YUY2_TILED)) {
        _allocate_tiled_yuv_planar(buffer);
    }
    else {
        /* Driver need compute the stride always with RT500 project. */
        uint32_t mul, div, align;
        get_format_bytes(buffer->format, &mul, &div, &align);
        buffer->stride = VG_LITE_ALIGN((buffer->width * mul / div), align);

        /* Allocate the buffer. */
        allocate.bytes = buffer->stride * buffer->height;
#if VG_TARGET_FAST_CLEAR
        allocate.bytes = VG_LITE_ALIGN(allocate.bytes, 64);
#endif
        allocate.contiguous = 1;
        VG_LITE_RETURN_ERROR(vg_lite_kernel(VG_LITE_ALLOCATE, &allocate));

        /* Save the buffer allocation. */
        buffer->handle  = allocate.memory_handle;
        buffer->memory  = allocate.memory;
        buffer->address = allocate.memory_gpu;

        if ((buffer->format == VG_LITE_AYUY2) || (buffer->format == VG_LITE_AYUY2_TILED)) {
            allocate.bytes = buffer->stride * buffer->height;
            VG_LITE_RETURN_ERROR(vg_lite_kernel(VG_LITE_ALLOCATE, &allocate));
            buffer->yuv.alpha_planar = allocate.memory_gpu;
        }

    }

    return VG_LITE_SUCCESS;
}

vg_lite_error_t vg_lite_free(vg_lite_buffer_t * buffer)
{
    vg_lite_error_t error;
    vg_lite_kernel_free_t free, uv_free, v_free;

    if(buffer == NULL)
        return VG_LITE_INVALID_ARGUMENT;
    if (s_context.rtbuffer == buffer && !(memcmp(s_context.rtbuffer,buffer,sizeof(vg_lite_buffer_t))) ) {
        if (VG_LITE_SUCCESS == submit(&s_context)) {
            VG_LITE_RETURN_ERROR(stall(&s_context, 0, ~0));
        }
        vglitemDUMP("@[swap 0x%08X %dx%d +%u]",
            s_context.rtbuffer->address,
            s_context.rtbuffer->width, s_context.rtbuffer->height,
            s_context.rtbuffer->stride);
        vglitemDUMP_BUFFER(
            "framebuffer",
            s_context.rtbuffer->address,s_context.rtbuffer->memory,
            0,
            s_context.rtbuffer->stride*(s_context.rtbuffer->height));

        s_context.rtbuffer = NULL;
    }

    if (buffer->yuv.uv_planar) {
        /* Free UV(U) planar buffer. */
        uv_free.memory_handle = buffer->yuv.uv_handle;
        VG_LITE_RETURN_ERROR(vg_lite_kernel(VG_LITE_FREE, &uv_free));

        /* Mark the buffer as freed. */
        buffer->yuv.uv_handle = NULL;
        buffer->yuv.uv_memory = NULL;
    }

    if (buffer->yuv.v_planar) {
        /* Free V planar buffer. */
        v_free.memory_handle = buffer->yuv.v_handle;
        VG_LITE_RETURN_ERROR(vg_lite_kernel(VG_LITE_FREE, &v_free));

        /* Mark the buffer as freed. */
        buffer->yuv.v_handle = NULL;
        buffer->yuv.v_memory = NULL;
    }

    /* Make sure we have a valid memory handle. */
    if (buffer->handle == NULL) {
        return VG_LITE_INVALID_ARGUMENT;
    }

    /* Free the buffer. */
    free.memory_handle = buffer->handle;
    VG_LITE_RETURN_ERROR(vg_lite_kernel(VG_LITE_FREE, &free));

    /* Mark the buffer as freed. */
    buffer->handle = NULL;
    buffer->memory = NULL;

    return VG_LITE_SUCCESS;
}

vg_lite_error_t vg_lite_map(vg_lite_buffer_t * buffer)
{
    vg_lite_error_t error;
    vg_lite_kernel_map_t map;

    /* We either need a logical or physical address. */
    if (buffer->memory == NULL && buffer->address == 0) {
        return VG_LITE_INVALID_ARGUMENT;
    }

    /* Check if we need to compute the stride. Usually map a pre-allocated memory, so the stride
       usually should be set*/
    if (buffer->stride == 0) {
        uint32_t mul, div, align;
        get_format_bytes(buffer->format, &mul, &div, &align);
        /* Compute the stride to be aligned. */
        buffer->stride = VG_LITE_ALIGN((buffer->width * mul / div), align);
    }

    /* Map the buffer. */
    map.bytes = buffer->stride * buffer->height;
    map.logical = buffer->memory;
    map.physical = buffer->address;
    VG_LITE_RETURN_ERROR(vg_lite_kernel(VG_LITE_MAP, &map));

    /* Save the buffer allocation. */
    buffer->handle  = map.memory_handle;
    buffer->address = map.memory_gpu;

    return VG_LITE_SUCCESS;
}

vg_lite_error_t vg_lite_unmap(vg_lite_buffer_t * buffer)
{
    vg_lite_error_t error;
    vg_lite_kernel_unmap_t unmap;

    /* Make sure we have a valid memory handle. */
    if (buffer->handle == NULL) {
        return VG_LITE_INVALID_ARGUMENT;
    }

    /* Unmap the buffer. */
    unmap.memory_handle = buffer->handle;
    VG_LITE_RETURN_ERROR(vg_lite_kernel(VG_LITE_UNMAP, &unmap));

    /* Mark the buffer as freed. */
    buffer->handle = NULL;

    return VG_LITE_SUCCESS;
}

vg_lite_error_t vg_lite_get_register(uint32_t address, uint32_t * result)
{
    vg_lite_error_t error;
    vg_lite_kernel_info_t data;

    /* Get input register address. */
    data.addr = address;

    /* Get register info. */
    VG_LITE_RETURN_ERROR(vg_lite_kernel(VG_LITE_CHECK, &data));

    /* Return register info. */
    *result = data.reg;

    return VG_LITE_SUCCESS;
}

void vg_lite_get_info(vg_lite_info_t *info)
{
    if (info != NULL)
    {
        info->api_version = VGLITE_API_VERSION_2_0;
        info->header_version = VGLITE_HEADER_VERSION;
        info->release_version = VGLITE_RELEASE_VERSION;
        info->reserved = 0;
    }
}

uint32_t vg_lite_get_product_info(char *name, uint32_t *chip_id, uint32_t *chip_rev)
{
    const char *product_name = "GCNanoLiteV";
    uint32_t name_len;
    uint32_t rev = 0, id = 0;

    vg_lite_get_register(0x24, &rev);
    vg_lite_get_register(0x20, &id);

    name_len = strlen(product_name) + 1;
    if (name != NULL)
    {
        memcpy(name, product_name, name_len);
    }

    if (chip_id != NULL)
    {
        *chip_id = id;
    }

    if (chip_rev != NULL)
    {
        *chip_rev = rev;
    }
    return name_len;
}

uint32_t vg_lite_query_feature(vg_lite_feature_t feature)
{
    uint32_t result;

    if (feature < gcFEATURE_COUNT)
        result = s_ftable.ftable[feature];
    else
        result = 0;

    return result;
}

vg_lite_error_t vg_lite_finish()
{
    vg_lite_error_t  error;

    /* Return if there is nothing to submit. */
    if (CMDBUF_OFFSET(s_context) == 0)
        return VG_LITE_SUCCESS;

    /* Flush is moved from each draw to here. */
    VG_LITE_RETURN_ERROR(flush_target());
    VG_LITE_RETURN_ERROR(submit(&s_context));
    VG_LITE_RETURN_ERROR(stall(&s_context, 0, (uint32_t)~0));

#if VG_TARGET_FAST_CLEAR
    /*Only used in cmodel/fpga. In final SOC this SW FC decoder should be removed. */
    if (s_context.rtbuffer != NULL) {
#if VG_TARGET_FC_DUMP
        fc_buf_dump(s_context.rtbuffer, &s_context.fcBuffer);
#endif /* VG_TARGET_FC_DUMP */
    }
#endif

    CMDBUF_SWAP(s_context);
    /* Reset command buffer. */
    CMDBUF_OFFSET(s_context) = 0;

    return VG_LITE_SUCCESS;
}

vg_lite_error_t vg_lite_flush()
{
    vg_lite_error_t error;

    /* Return if there is nothing to submit. */
    if (CMDBUF_OFFSET(s_context) == 0)
        return VG_LITE_SUCCESS;

    /* Wait if GPU has not completed previous CMD buffer */
    if (submit_flag)
    {
        VG_LITE_RETURN_ERROR(stall(&s_context, 0, (uint32_t)~0));
    }

    /* Submit the current command buffer. */
    VG_LITE_RETURN_ERROR(flush_target());
    VG_LITE_RETURN_ERROR(submit(&s_context));
    CMDBUF_SWAP(s_context);
    /* Reset command buffer. */
    CMDBUF_OFFSET(s_context) = 0;

    return VG_LITE_SUCCESS;
}

vg_lite_error_t vg_lite_init_path(vg_lite_path_t * path,
                       vg_lite_format_t data_format,
                       vg_lite_quality_t quality,
                       uint32_t path_length,
                       void *   path_data,
                       vg_lite_float_t min_x, vg_lite_float_t min_y,
                       vg_lite_float_t max_x, vg_lite_float_t max_y)
{
    if(path == NULL)
        return VG_LITE_INVALID_ARGUMENT;
    path->format = data_format;
    path->quality = quality;
    path->bounding_box[0] = min_x;
    path->bounding_box[1] = min_y;
    path->bounding_box[2] = max_x;
    path->bounding_box[3] = max_y;

    path->path_length = path_length;
    path->path         = path_data;

    path->path_changed = 1;
    path->uploaded.address = 0;
    path->uploaded.bytes = 0;
    path->uploaded.handle = NULL;
    path->uploaded.memory = NULL;

    return VG_LITE_SUCCESS;
}

vg_lite_error_t vg_lite_clear_path(vg_lite_path_t * path)
{
    vg_lite_error_t error;
    if (path->uploaded.handle != NULL)
    {
        vg_lite_kernel_free_t free_cmd;
        free_cmd.memory_handle = path->uploaded.handle;
        VG_LITE_RETURN_ERROR(vg_lite_kernel(VG_LITE_FREE, &free_cmd));
    }

    path->uploaded.address = 0;
    path->uploaded.bytes = 0;
    path->uploaded.handle = NULL;
    path->uploaded.memory = NULL;

    return VG_LITE_SUCCESS;
}

vg_lite_error_t vg_lite_set_CLUT(uint32_t count,
                                 uint32_t * colors)
{
    vg_lite_error_t error =  VG_LITE_SUCCESS;

    uint32_t addr = 0x0B00;

    if(!s_ftable.ftable[gcFEATURE_BIT_VG_IM_INDEX_FORMAT])
        return VG_LITE_NOT_SUPPORT;

    switch (count) {
        case 256:
            addr = 0x0B00;
            break;

        case 16:
            addr = 0x0AA0;
            break;

        case 4:
            addr = 0x0A9C;
            break;

        case 2:
            addr = 0x0A98;
            break;

        default:
            error = VG_LITE_INVALID_ARGUMENT;
            return error;
            break;
    }

    VG_LITE_RETURN_ERROR(push_states(&s_context, addr, count, colors));

    return error;
}

vg_lite_error_t vg_lite_draw_pattern(vg_lite_buffer_t * target,
                                     vg_lite_path_t * path,
                                     vg_lite_fill_t fill_rule,
                                     vg_lite_matrix_t * matrix0,
                                     vg_lite_buffer_t * source,
                                     vg_lite_matrix_t * matrix1,
                                     vg_lite_blend_t blend,
                                     vg_lite_pattern_mode_t pattern_mode,
                                     vg_lite_color_t  pattern_color,
                                     vg_lite_filter_t filter)
{
    vg_lite_error_t error = VG_LITE_SUCCESS;
    uint32_t imageMode;
    uint32_t blend_mode;
    uint32_t conversion = 0;
    uint32_t tiled_source;
    vg_lite_matrix_t * matrix = matrix1;
    uint32_t pattern_tile = 0;
    uint32_t transparency_mode = 0;

    /* The following code is from "draw path" */
    uint32_t format, quality, tiling, fill;
    uint32_t tessellation_size;

    vg_lite_kernel_allocate_t memory;
    vg_lite_kernel_free_t free_memory;
    uint32_t return_offset = 0;

    vg_lite_point_t point_min = {0}, point_max = {0}, temp = {0};
    int x, y, width, height;
    uint8_t ts_is_fullscreen = 0;

    if(source->format == VG_LITE_A4 || source->format == VG_LITE_A8) {
        return VG_LITE_NOT_SUPPORT;
    }

    if(!vg_lite_query_feature(gcFEATURE_BIT_VG_QUALITY_8X) && path->quality == VG_LITE_UPPER){
        return VG_LITE_NOT_SUPPORT;
    }

    error = set_render_target(target);
    if (error != VG_LITE_SUCCESS) {
        return error;
    }

    transparency_mode = (source->transparency_mode == VG_LITE_IMAGE_TRANSPARENT ? 0x8000:0);
    width = s_context.tsbuffer.tessellation_width_height & 0xFFFF;
    height = s_context.tsbuffer.tessellation_width_height >> 16;
    if ((target->width <= width) && (target->height <= height))
    {
        ts_is_fullscreen = 1;
        point_min.x = 0;
        point_min.y = 0;
        point_max.x = target->width;
        point_max.y = target->height;
    }

    /* If target is L8 and source is in YUV or RGB (not L8 or A8) then we have to convert RGB into L8. */
    if ((target->format == VG_LITE_L8) && ((source->format != VG_LITE_L8) && (source->format != VG_LITE_A8))) {
        conversion = 0x80000000;
    }
    /* Determine image mode (NORMAL or MULTIPLY) depending on the color. */
    imageMode = (source->image_mode == VG_LITE_NONE_IMAGE_MODE) ? 0 : (source->image_mode == VG_LITE_MULTIPLY_IMAGE_MODE) ? 0x00002000 : 0x00001000;
    tiled_source = (source->tiled != VG_LITE_LINEAR) ? 0x10000000 : 0 ;

    if (pattern_mode == VG_LITE_PATTERN_COLOR)
    {
        uint8_t a,r,g,b;
        pattern_tile = 0;
        a = pattern_color >> 24;
        r = pattern_color >> 16;
        g = pattern_color >> 8;
        b = pattern_color;
        pattern_color = (a << 24) | (b << 16) | (g << 8) | r;
    }
    else if (pattern_mode == VG_LITE_PATTERN_PAD)
    {
        pattern_tile = 0x1000;
    }
    else
    {
        return VG_LITE_INVALID_ARGUMENT;
    }

    /* Setup the command buffer. */

    VG_LITE_RETURN_ERROR(set_interpolation_steps(target, source->width, source->height, matrix, NULL, NULL));

    if(source->transparency_mode == VG_LITE_IMAGE_OPAQUE){
        VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A25, convert_source_format(source->format) |
                                                            filter | pattern_tile | conversion | 0x01000100));
    } else {
        VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A25, convert_source_format(source->format) |
                                                            filter | pattern_tile | conversion | 0x00000100));
    }
    VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A27, pattern_color));
    VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A29, source->address));

    VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A2B, source->stride | tiled_source));
    VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A2D, 0));
    VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A2F, source->width | (source->height << 16)));

    /* Work on path states. */
    matrix = matrix0;

    if (ts_is_fullscreen == 0){
        transform(&temp, (vg_lite_float_t)path->bounding_box[0], (vg_lite_float_t)path->bounding_box[1], matrix);
        point_min = point_max = temp;

        transform(&temp, (vg_lite_float_t)path->bounding_box[2], (vg_lite_float_t)path->bounding_box[1], matrix);
        if (temp.x < point_min.x) point_min.x = temp.x;
        if (temp.y < point_min.y) point_min.y = temp.y;
        if (temp.x > point_max.x) point_max.x = temp.x;
        if (temp.y > point_max.y) point_max.y = temp.y;

        transform(&temp, (vg_lite_float_t)path->bounding_box[2], (vg_lite_float_t)path->bounding_box[3], matrix);
        if (temp.x < point_min.x) point_min.x = temp.x;
        if (temp.y < point_min.y) point_min.y = temp.y;
        if (temp.x > point_max.x) point_max.x = temp.x;
        if (temp.y > point_max.y) point_max.y = temp.y;

        transform(&temp, (vg_lite_float_t)path->bounding_box[0], (vg_lite_float_t)path->bounding_box[3], matrix);
        if (temp.x < point_min.x) point_min.x = temp.x;
        if (temp.y < point_min.y) point_min.y = temp.y;
        if (temp.x > point_max.x) point_max.x = temp.x;
        if (temp.y > point_max.y) point_max.y = temp.y;

        point_min.x = MAX(point_min.x, 0);
        point_min.y = MAX(point_min.y, 0);
        point_max.x = MIN(point_max.x, target->width);
        point_max.y = MIN(point_max.y, target->height);

        if (s_context.scissor_enabled) {
            point_min.x = MAX(point_min.x, s_context.scissor[0]);
            point_min.y = MAX(point_min.y, s_context.scissor[1]);
            point_max.x = MIN(point_max.x, s_context.scissor[2]);
            point_max.y = MIN(point_max.y, s_context.scissor[3]);
        }
    }

    /* Convert states into hardware values. */
    blend_mode = convert_blend(blend);
    format = convert_path_format(path->format);
    quality = convert_path_quality(path->quality);
    tiling = (s_context.capabilities.cap.tiled == 2) ? 0x2000000 : 0;
    fill = (fill_rule == VG_LITE_FILL_EVEN_ODD) ? 0x10 : 0;
    tessellation_size = (  s_context.tsbuffer.tessellation_buffer_size[2]
                         ? s_context.tsbuffer.tessellation_buffer_size[2]
                         : s_context.tsbuffer.tessellation_buffer_size[1]
                         );

    /* Setup the command buffer. */
    /* Program color register. */
    //VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A00, s_context.capabilities.cap.tiled | 0x00000002 | imageMode | blend_mode | rotation));
    VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A00, 0x10000000 | s_context.capabilities.cap.tiled | 0x00000002 | imageMode | blend_mode | transparency_mode));
    VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A34, 0x01000400 | format | quality | tiling | fill));
    VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A3B, 0x3F800000));      /* Path tessellation SCALE. */
    VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A3C, 0x00000000));      /* Path tessellation BIAS.  */
    /* Program matrix. */
    VG_LITE_RETURN_ERROR(push_state_ptr(&s_context, 0x0A40, (void *) &matrix->m[0][0]));
    VG_LITE_RETURN_ERROR(push_state_ptr(&s_context, 0x0A41, (void *) &matrix->m[0][1]));
    VG_LITE_RETURN_ERROR(push_state_ptr(&s_context, 0x0A42, (void *) &matrix->m[0][2]));
    VG_LITE_RETURN_ERROR(push_state_ptr(&s_context, 0x0A43, (void *) &matrix->m[1][0]));
    VG_LITE_RETURN_ERROR(push_state_ptr(&s_context, 0x0A44, (void *) &matrix->m[1][1]));
    VG_LITE_RETURN_ERROR(push_state_ptr(&s_context, 0x0A45, (void *) &matrix->m[1][2]));

    if (VLM_PATH_GET_UPLOAD_BIT(*path) == 1)
    {
        if (path->path_changed != 0) {
            if (path->uploaded.handle != NULL) {
                free_memory.memory_handle = path->uploaded.handle;
                vg_lite_kernel(VG_LITE_FREE, &free_memory);
                path->uploaded.address = 0;
                path->uploaded.memory = NULL;
                path->uploaded.handle = NULL;
            }
            /* Allocate memory for the path data. */
            memory.bytes = 16 + VG_LITE_ALIGN(path->path_length, 8);
            return_offset = (8 + VG_LITE_ALIGN(path->path_length, 8)) / 4;
            memory.contiguous = 1;
            VG_LITE_RETURN_ERROR(vg_lite_kernel(VG_LITE_ALLOCATE, &memory));
            ((uint64_t *) memory.memory)[(path->path_length + 7) / 8] = 0;
            ((uint32_t *) memory.memory)[0] = VG_LITE_DATA((path->path_length + 7) / 8);
            ((uint32_t *) memory.memory)[1] = 0;
            memcpy((uint8_t *) memory.memory + 8, path->path, path->path_length);
            ((uint32_t *) memory.memory)[return_offset] = VG_LITE_RETURN();
            ((uint32_t *) memory.memory)[return_offset + 1] = 0;

            path->uploaded.handle = memory.memory_handle;
            path->uploaded.memory = memory.memory;
            path->uploaded.address = memory.memory_gpu;
            path->uploaded.bytes  = memory.bytes;
            path->path_changed = 0;
        }
    }

    if (VLM_PATH_GET_UPLOAD_BIT(*path) == 1) {

        vglitemDUMP_BUFFER("path", path->uploaded.address, (uint8_t *)(path->uploaded.memory), 0, path->uploaded.bytes);
    }

    vglitemDUMP("@[memory 0x%08X 0x%08X]", s_context.tsbuffer.tessellation_buffer_gpu[0], s_context.tsbuffer.tessellation_buffer_size[0]);

    /* Setup tessellation loop. */
    for (y = point_min.y; y < point_max.y; y += height) {
        for (x = point_min.x; x < point_max.x; x += width) {
            /* Tessellate path. */
            VG_LITE_RETURN_ERROR(push_stall(&s_context, 15));
            VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A1B, 0x00011000));
            VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A01, x | (y << 16)));
            VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A39, x | (y << 16)));
            VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A3D, tessellation_size / 64));

            if (VLM_PATH_GET_UPLOAD_BIT(*path) == 1) {
                VG_LITE_RETURN_ERROR(push_call(&s_context, path->uploaded.address, path->uploaded.bytes));
#if  (DUMP_COMMAND && VG_COMMAND_CALL)
                if (strncmp(filename, "Commandbuffer", 13)) {
                    sprintf(filename, "Commandbuffer_pid%d.txt", getpid());
                }

                fp = fopen(filename, "a");

                if (fp == NULL)
                    printf("error!\n");

                fprintf(fp, "Command buffer: 0x%08x, 0x%08x,\n",
                        ((uint32_t *) memory.memory)[0], 0);

                unsigned char* pt = (unsigned char*) memory.memory;

                for(int i = 8; i <= return_offset * 4 - 1; i = i + 4)
                {
                    if (i % 8 == 0)
                        fprintf(fp, "Command buffer: ");

                    if (i % 4 == 0)
                        fprintf(fp, "0x");

                    for (int j = 3; j >= 0; --j)
                        fprintf(fp, "%02x", pt[i + j]);

                    if ((i / 4 + 1) % 2 == 0)
                        fprintf(fp, ",\n");
                    else
                        fprintf(fp, ", ");
                }

                fprintf(fp, "Command buffer: 0x%08x, 0x%08x,\n",
                        ((uint32_t *) memory.memory)[return_offset], 0);

                fclose(fp);
                fp = NULL;
#endif
            } else {
                push_data(&s_context, path->path_length, path->path);
            }
        }
    }

    /* Finialize command buffer. */
    VG_LITE_RETURN_ERROR(push_state(&s_context, 0x0A34, 0));

    vglitemDUMP_BUFFER("image", source->address, source->memory, 0, (source->stride)*(source->height));
#if DUMP_IMAGE
    dump_img(source->memory, source->width, source->height, source->format);
#endif
    return error;
}

vg_lite_error_t vg_lite_init_grad(vg_lite_linear_gradient_t *grad)
{
    vg_lite_error_t error = VG_LITE_SUCCESS;

    /* Set the member values according to driver defaults. */
    grad->image.width = VLC_GRADBUFFER_WIDTH;
    grad->image.height = 1;
    grad->image.stride = 0;
    grad->image.format = VG_LITE_BGRA8888;

    /* Allocate the image for gradient. */
    error = vg_lite_allocate(&grad->image);

    grad->count = 0;

    return error;
}

vg_lite_error_t vg_lite_set_grad(vg_lite_linear_gradient_t *grad,
                                 uint32_t count,
                                 uint32_t * colors,
                                 uint32_t * stops)
{
    uint32_t i;

    grad->count = 0;    /* Opaque B&W gradient */
    if (!count || count > VLC_MAX_GRAD || colors == NULL || stops == NULL)
        return VG_LITE_SUCCESS;
    /* Check stops validity */
    for (i = 0; i < count; i++)
        if (stops[i] <= 255) {
            if (!grad->count || stops[i] > grad->stops[grad->count - 1]) {
                grad->stops[grad->count] = stops[i];
                grad->colors[grad->count] = colors[i];
                grad->count++;
            } else if (stops[i] == grad->stops[grad->count - 1]) {
                /* Equal stops : use the color corresponding to the last stop
                in the sequence */
                grad->colors[grad->count - 1] = colors[i];
            }
        }
    return VG_LITE_SUCCESS;
}

vg_lite_error_t vg_lite_update_grad(vg_lite_linear_gradient_t *grad)
{
    vg_lite_error_t error = VG_LITE_SUCCESS;
    int32_t r0, g0, b0, a0;
    int32_t r1, g1, b1, a1;
    int32_t lr, lg, lb, la;
    uint32_t i;
    int32_t j;
    int32_t ds, dr, dg, db, da;
    uint32_t *buffer = (uint32_t *)grad->image.memory;

    if (grad->count == 0) {
        /* If no valid stops have been specified (e.g., due to an empty input
        * array, out-of-range, or out-of-order stops), a stop at 0 with color
        * 0xFF000000 (opaque black) and a stop at 255 with color 0xFFFFFFFF
        * (opaque white) are implicitly defined. */
        grad->stops[0] = 0;
        grad->colors[0] = 0xFF000000;   /* Opaque black */
        grad->stops[1] = 255;
        grad->colors[1] = 0xFFFFFFFF;   /* Opaque white */
        grad->count = 2;
    } else if (grad->count && grad->stops[0] != 0) {
        /* If at least one valid stop has been specified, but none has been
        * defined with an offset of 0, an implicit stop is added with an
        * offset of 0 and the same color as the first user-defined stop. */
        for (i = 0; i < grad->stops[0]; i++)
            buffer[i] = grad->colors[0];
    }
    a0 = A(grad->colors[0]);
    r0 = R(grad->colors[0]);
    g0 = G(grad->colors[0]);
    b0 = B(grad->colors[0]);

    /* Calculate the colors for each pixel of the image. */
    for (i = 0; i < grad->count - 1; i++) {
        buffer[grad->stops[i]] = grad->colors[i];
        ds = grad->stops[i + 1] - grad->stops[i];
        a1 = A(grad->colors[i + 1]);
        r1 = R(grad->colors[i + 1]);
        g1 = G(grad->colors[i + 1]);
        b1 = B(grad->colors[i + 1]);

        da = a1 - a0;
        dr = r1 - r0;
        dg = g1 - g0;
        db = b1 - b0;

        for (j = 1; j < ds; j++) {
            la = a0 + da * j / ds;
            lr = r0 + dr * j / ds;
            lg = g0 + dg * j / ds;
            lb = b0 + db * j / ds;

            buffer[grad->stops[i] + j] = ARGB(la, lr, lg, lb);
        }

        a0 = a1;
        r0 = r1;
        g0 = g1;
        b0 = b1;
    }
    /* If at least one valid stop has been specified, but none has been defined
    * with an offset of 255, an implicit stop is added with an offset of 255
    * and the same color as the last user-defined stop. */
    for (i = grad->stops[grad->count - 1]; i < 255; i++)
        buffer[i] = grad->colors[grad->count - 1];
    /* Last pixel */
    buffer[i] = grad->colors[grad->count - 1];
    return error;
}

vg_lite_error_t vg_lite_clear_grad(vg_lite_linear_gradient_t *grad)
{
    vg_lite_error_t error = VG_LITE_SUCCESS;

    grad->count = 0;
    /* Release the image resource. */
    if (grad->image.handle != NULL)
    {
        error = vg_lite_free(&grad->image);
    }

    return error;
}

vg_lite_matrix_t * vg_lite_get_grad_matrix(vg_lite_linear_gradient_t *grad)
{
    return &grad->matrix;
}

vg_lite_error_t vg_lite_draw_gradient(vg_lite_buffer_t * target,
                                      vg_lite_path_t * path,
                                      vg_lite_fill_t fill_rule,
                                      vg_lite_matrix_t * matrix,
                                      vg_lite_linear_gradient_t * grad,
                                      vg_lite_blend_t blend)
{
    return vg_lite_draw_pattern(target, path, fill_rule, matrix,
        &grad->image, &grad->matrix, blend, VG_LITE_PATTERN_PAD, 0, VG_LITE_FILTER_LINEAR);
}

vg_lite_error_t vg_lite_set_command_buffer_size(uint32_t size)
{
    if(command_buffer_size == 0)
        return VG_LITE_INVALID_ARGUMENT;

    command_buffer_size = size;
    return VG_LITE_SUCCESS;
}
vg_lite_error_t vg_lite_set_scissor(int32_t x, int32_t y, int32_t right, int32_t bottom)
{
    vg_lite_error_t error = VG_LITE_SUCCESS;

    if(!vg_lite_query_feature(gcFEATURE_BIT_VG_SCISSOR))
        return VG_LITE_NOT_SUPPORT;

    /* Save scissor Box States. */
    s_context.scissor[0] = x;
    s_context.scissor[1] = y;
    s_context.scissor[2] = right;
    s_context.scissor[3] = bottom;

    /* Scissor dirty. */
    s_context.scissor_dirty = 1;

    return error;
}

vg_lite_error_t vg_lite_enable_scissor(void)
{
    if(!vg_lite_query_feature(gcFEATURE_BIT_VG_SCISSOR))
        return VG_LITE_NOT_SUPPORT;

    /* Enable scissor Mode. */
    s_context.scissor_enabled = 1;

    /* Scissor dirty. */
    s_context.scissor_dirty = 1;

    return VG_LITE_SUCCESS;
}

vg_lite_error_t vg_lite_disable_scissor(void)
{
    if(!vg_lite_query_feature(gcFEATURE_BIT_VG_SCISSOR))
        return VG_LITE_NOT_SUPPORT;

    /* disable scissor Mode. */
    s_context.scissor_enabled = 0;

    /* Scissor dirty. */
    s_context.scissor_dirty = 1;

    return VG_LITE_SUCCESS;
}

vg_lite_error_t vg_lite_mem_avail(uint32_t *size)
{
    vg_lite_error_t error = VG_LITE_SUCCESS;
    vg_lite_kernel_mem_t mem;
    VG_LITE_RETURN_ERROR(vg_lite_kernel(VG_LITE_QUERY_MEM,&mem));
    *size = mem.bytes;

    return error;
}
