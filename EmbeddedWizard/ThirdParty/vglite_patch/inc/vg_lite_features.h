/****************************************************************************
 *
 *    The MIT License (MIT)
 *
 *    Copyright (c) 2014 - 2019 Vivante Corporation
 *
 *    Permission is hereby granted, free of charge, to any person obtaining a
 *    copy of this software and associated documentation files (the "Software"),
 *    to deal in the Software without restriction, including without limitation
 *    the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *    and/or sell copies of the Software, and to permit persons to whom the
 *    Software is furnished to do so, subject to the following conditions:
 *
 *    The above copyright notice and this permission notice shall be included in
 *    all copies or substantial portions of the Software.
 *
 *    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *    DEALINGS IN THE SOFTWARE.
 *
 *****************************************************************************/

//
//  vg_lite_features.h
//  VGLite feature definitions.

#ifndef _vg_lite_features_h_
#define _vg_lite_features_h_

#ifndef VG_RESOLVE_ENGINE
#define VG_RESOLVE_ENGINE 0
#endif

#ifndef VG_PE_COLOR_KEY
#define VG_PE_COLOR_KEY 0
#endif

#ifndef VG_IM_INDEX_FORMAT
#define VG_IM_INDEX_FORMAT 1
#endif

#ifndef VG_AYUV_INPUT_OUTPUT
#define VG_AYUV_INPUT_OUTPUT 1
#endif

#ifndef VG_DOUBLE_IMAGE
#define VG_DOUBLE_IMAGE 1
#endif

#ifndef VG_RECTANGLE_STRIP_MODE
#define VG_RECTANGLE_STRIP_MODE 1
#endif

#ifndef VG_MMU
#define VG_MMU 1
#endif

#ifndef VG_IM_FILTER
#define VG_IM_FILTER 1
#endif

#ifndef VG_IM_YUV_PACKET
#define VG_IM_YUV_PACKET 1
#endif

#ifndef VG_IM_YUV_PLANAR
#define VG_IM_YUV_PLANAR 1
#endif

#ifndef VG_PE_YUV_PACKET
#define VG_PE_YUV_PACKET 1
#endif

#ifndef VG_POST_CONVERTER
#define VG_POST_CONVERTER 0
#endif

#ifndef VG_PRE_CONVERTER
#define VG_PRE_CONVERTER 0
#endif

#ifndef VG_RENDER_BY_MESH
#define VG_RENDER_BY_MESH 1
#endif

#ifndef VG_IM_A2R2G2B2_FORMAT
#define VG_IM_A2R2G2B2_FORMAT 1
#endif

#ifndef VG_PE_A2R2G2B2_FORMAT
#define VG_PE_A2R2G2B2_FORMAT 1
#endif

#ifdef VG_RENDER_BY_MESH

#if VG_RENDER_BY_MESH
#define DDRLESS 1
#define DDRLESS_CMODEL 0 /* Enable cmodel specific code in DDRLess. */
#define DDRLESS_FPGA 1   /* Enable fpga specific code in DDRLess. */
#else
#define DDRLESS 0
#define DDRLESS_CMODEL 0 /* Enable cmodel specific code in DDRLess. */
#define DDRLESS_FPGA 0   /* Enable fpga specific code in DDRLess. */
#endif

#else /* #if VG_RENDER_BY_MESH */

#define DDRLESS 0
#define DDRLESS_CMODEL 0 /* Enable cmodel specific code in DDRLess. */
#define DDRLESS_FPGA 0   /* Enable fpga specific code in DDRLess. */

#endif /* #if VG_RENDER_BY_MESH */

#ifndef VG_TARGET_FAST_CLEAR
#define VG_TARGET_FAST_CLEAR 0
#endif

#ifndef VG_BUFFER_NUMBER_OF_TARGET
#define VG_BUFFER_NUMBER_OF_TARGET 2
#endif

#ifndef VG_VIDEO_CONTROL
#define VG_VIDEO_CONTROL 1
#endif

#ifndef VG_VIDEO_CLEAR_CONTROL
#define VG_VIDEO_CLEAR_CONTROL 0
#endif

#ifndef VG_TARGET_TILED
#define VG_TARGET_TILED 1
#endif

#ifndef VG_COMMAND_CALL
#define VG_COMMAND_CALL 0
#endif

#ifndef VG_OFFLINE_MODE
#define VG_OFFLINE_MODE 1
#endif

#ifndef VG_RESOLUTION_2880
#define VG_RESOLUTION_2880 0
#endif
#endif /* vg_lite_features_h */
