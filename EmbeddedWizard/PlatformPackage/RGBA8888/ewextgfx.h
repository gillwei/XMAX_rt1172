/*******************************************************************************
*
* E M B E D D E D   W I Z A R D   P R O J E C T
*
*                                                Copyright (c) TARA Systems GmbH
*                                    written by Paul Banach and Manfred Schweyer
*
********************************************************************************
*
* This software and related documentation ("Software") are intellectual
* property owned by TARA Systems and are copyright of TARA Systems.
* Any modification, copying, reproduction or redistribution of the Software in
* whole or in part by any means not in accordance with the End-User License
* Agreement for Embedded Wizard is expressly prohibited. The removal of this
* preamble is expressly prohibited.
*
********************************************************************************
*
* DESCRIPTION:
*   This header file contains Graphics Engine configuration parameters and the
*   adaptation for the VGLite graphics subsystem running in the RGBA8888 color
*   format.
*
*******************************************************************************/

#ifndef EWEXTGFX_H
#define EWEXTGFX_H


#ifdef __cplusplus
  extern "C"
  {
#endif


/* Following macros allow to enable/disable the redirection to VGLite API.
   These are essentoal to workaround the errors in VGLite API:

   EW_USE_VGLITE - If 1, the VGLite functionality is used. If 0, all drawing
     operations are performed via SW except the final blit, which is executed
     by VGLite.

   EW_USE_COPY_MODE - If 1, the rotation/perspective warp operations with
     disabled alpha-blending are performed via VGLite. If 0, the operations are
     executed by SW. */
#ifndef EW_USE_VGLITE
  #define EW_USE_VGLITE                   1
#endif

#ifndef EW_USE_COPY_MODE
  #define EW_USE_COPY_MODE                1
#endif


/* The following macros override the default color channel allocation to the
   order (bit31) A..R..G..B (bit0). If your graphics hardware supports other
   color channel order, you can define the following macros in your make file. */
#ifndef EW_COLOR_CHANNEL_BIT_OFFSET_RED
  #define EW_COLOR_CHANNEL_BIT_OFFSET_RED    16
#endif

#ifndef EW_COLOR_CHANNEL_BIT_OFFSET_GREEN
  #define EW_COLOR_CHANNEL_BIT_OFFSET_GREEN   8
#endif

#ifndef EW_COLOR_CHANNEL_BIT_OFFSET_BLUE
  #define EW_COLOR_CHANNEL_BIT_OFFSET_BLUE    0
#endif

#ifndef EW_COLOR_CHANNEL_BIT_OFFSET_ALPHA
  #define EW_COLOR_CHANNEL_BIT_OFFSET_ALPHA  24
#endif


/* Only RGBA or BGRA pixel storage is supported */
#if EW_COLOR_CHANNEL_BIT_OFFSET_ALPHA != 24
  #error Wrong color channels order. VGLite supports RGBA or BGRA only.
#endif

#if EW_COLOR_CHANNEL_BIT_OFFSET_GREEN != 8
  #error Wrong color channels order. VGLite supports RGBA or BGRA only.
#endif


/* The following macros override the default color channel allocation to the
   order (bit15) R..G..B (bit0). If your graphics hardware supports other
   color channel order, you can define the following macros in your make file. */
#ifndef EW_RGB565_COLOR_CHANNEL_BIT_OFFSET_RED
  #define EW_RGB565_COLOR_CHANNEL_BIT_OFFSET_RED    11
#endif

#ifndef EW_RGB565_COLOR_CHANNEL_BIT_OFFSET_GREEN
  #define EW_RGB565_COLOR_CHANNEL_BIT_OFFSET_GREEN   5
#endif

#ifndef EW_RGB565_COLOR_CHANNEL_BIT_OFFSET_BLUE
  #define EW_RGB565_COLOR_CHANNEL_BIT_OFFSET_BLUE    0
#endif


/* VGLite GPU operates with premultiplied colors */
#define EW_PREMULTIPLY_COLOR_CHANNELS         1


/* The following macros exist for debugging purpose only. Please avoid the
   usage of these macros in the release version. They are intended to simplify
   the bring up phase on a new target system.

   EW_PRINT_GFX_TASK_DETAILS determines whether this VGLite driver should
   log the performed operations and their parameters or not. If set 0, nothing
   is logged. This is typical for the release version. If set 1, all performed
   drawing operations are logged.
*/
#ifndef EW_PRINT_GFX_TASK_DETAILS
  #define EW_PRINT_GFX_TASK_DETAILS    0
#endif


/* If not explicitly specified, assume following default number of tasks,
   which can wait for execution in a so-called 'issue'. Large number of
   tasks can promote the automatic elimination of drawing tasks. */
#ifndef EW_MAX_ISSUE_TASKS
  #define EW_MAX_ISSUE_TASKS 250
#endif


/*******************************************************************************
* FUNCTION:
*   VGLiteInitGfx
*
* DESCRIPTION:
*   The function VGLiteInitGfx is called from the Graphics Engine during the
*   initialization in order to make target specific configurations of the
*   Graphics Engine
*
* ARGUMENTS:
*   aArgs - Optional argument passed to the Graphics Engine init function.
*
* RETURN VALUE:
*   If successful, returns != 0.
*
*******************************************************************************/
int VGLiteInitGfx
(
  void*             aArgs
);


/*******************************************************************************
* FUNCTION:
*   VGLiteInitViewport
*
* DESCRIPTION:
*   The function VGLiteInitViewport is called from the Graphics Engine,
*   to create a new viewport on the target. The function uses the given
*   buffers passed in the arguments aDisplay1, aDisplay2 and aDisplay3.
*
* ARGUMENTS:
*   aWidth,
*   aHeight       - Size of the viewport in pixel.
*   aExtentX,
*   aExtentY,
*   aExtentWidth,
*   aExtentHeight - not used.
*   aOrient       - not used.
*   aOpacity      - not used.
*   aDisplay1     - Address of the VGLite framebuffer object.
*   aDisplay2     - not used.
*   aDisplay3     - not used.
*
* RETURN VALUE:
*   Handle of the surface descriptor (viewport).
*
*******************************************************************************/
unsigned long VGLiteInitViewport
(
  int               aWidth,
  int               aHeight,
  int               aExtentX,
  int               aExtentY,
  int               aExtentWidth,
  int               aExtentHeight,
  int               aOrient,
  int               aOpacity,
  void*             aDisplay1,
  void*             aDisplay2,
  void*             aDisplay3
);


/*******************************************************************************
* FUNCTION:
*   VGLiteDoneViewport
*
* DESCRIPTION:
*   The function VGLiteDoneViewport is called from the Graphics Engine, to
*   release a previously created viewport on the VGLite target.
*
* ARGUMENTS:
*   aHandle - Handle of the surface descriptor (viewport).
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void VGLiteDoneViewport
(
  unsigned long     aHandle
);


/*******************************************************************************
* FUNCTION:
*   VGLiteBeginUpdate
*
* DESCRIPTION:
*   The function VGLiteBeginUpdate is called from the Graphics Engine, to
*   initiate the screen update cycle.
*
* ARGUMENTS:
*   aHandle - Handle of the surface descriptor (viewport).
*
* RETURN VALUE:
*   Handle of the destination surface, used for all drawing operations.
*
*******************************************************************************/
unsigned long VGLiteBeginUpdate
(
  unsigned long     aHandle
);


/*******************************************************************************
* FUNCTION:
*   VGLiteEndUpdate
*
* DESCRIPTION:
*   The function VGLiteEndUpdate is called from the Graphics Engine, to
*   finalize the screen update cycle.
*
* ARGUMENTS:
*   aHandle - Handle of the surface descriptor (viewport).
*   aX,
*   aY,
*   aWidth,
*   aHeight - Position and size of the area affected from the screen update
*     (dirty rectangle).
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void VGLiteEndUpdate
(
  unsigned long     aHandle,
  int               aX,
  int               aY,
  int               aWidth,
  int               aHeight
);


/* Redirect the following operations to the functions within this module */
#define EwGfxInit            VGLiteInitGfx
#define EwGfxInitViewport    VGLiteInitViewport
#define EwGfxDoneViewport    VGLiteDoneViewport
#define EwGfxBeginUpdate     VGLiteBeginUpdate
#define EwGfxEndUpdate       VGLiteEndUpdate


/*******************************************************************************
* FUNCTION:
*   VGLiteCreateSurface
*
* DESCRIPTION:
*   The function VGLiteCreateSurface() reserves pixel memory for a new surface
*   with the given size and color format. The function returns a handle to the
*   new surface.
*
* ARGUMENTS:
*   aFormat  - Color format of the surface. (See EW_PIXEL_FORMAT_XXX).
*   aWidth,
*   aHeight  - Size of the surface in pixel to create.
*
* RETURN VALUE:
*   The function returns a handle to the created surface. This can be a pointer
*   to a dynamically allocated data structure, an index in a list of surfaces,
*   or a handle returned by the lower level API.
*
*   If the creation is failed, the function should return 0.
*
*******************************************************************************/
unsigned long VGLiteCreateSurface
(
  int               aFormat,
  int               aWidth,
  int               aHeight
);


/*******************************************************************************
* FUNCTION:
*   VGLiteDestroySurface
*
* DESCRIPTION:
*   The function VGLiteDestroySurface() frees the resources of the given surface.
*   This function is a counterpart to VGLiteCreateSurface().
*
* ARGUMENTS:
*   aHandle - Handle to the surface to free.
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void VGLiteDestroySurface
(
  unsigned long     aHandle
);


/*******************************************************************************
* FUNCTION:
*   VGLiteLockSurface
*
* DESCRIPTION:
*   The function VGLiteLockSurface() provides a direct access to the pixel
*   memory of the given surface. The function returns a lock object containing
*   pointers to memory, where the caller can read/write the surface pixel
*   values. Additional pitch values also returned in the object allow the caller
*   to calculate the desired pixel addresses.
*
*   When finished the access cycle, the function VGLiteUnlockSurface() should be
*   used in order to release the lock, update the affected surface, flush CPU
*   caches, etc.
*
* ARGUMENTS:
*   aSurfaceHandle - Handle to the surface to obtain the direct memory access.
*   aX, aY,
*   aWidth,
*   aHeight     - Area within the surface affected by the access operation.
*     (Relative to the top-left corner of the surface). This is the area, the
*     caller wish to read/write the pixel data.
*   aIndex,
*   Count       - Optional start index and number of entries within the CLUT,
*     the caller wish to read/write. These paramaters are used for surfaces
*     with the index8 color format only.
*   aReadPixel  - Is != 0, if the caller intends to read the pixel information
*     from the surface memory. If == 0, the memory content may remain undefined
*     depending on the underlying graphics sub-system and its video-memory
*     management.
*   aWritePixel - Is != 0, if the caller intends to modify the pixel information
*     within the surface memory. If == 0, any modifications within the memory
*     may remain ignored depending on the underlying graphics sub-system and its
*     video-memory management.
*   aReadClut   - Is != 0, if the caller intends to read the CLUT information.
*     If == 0, the CLUT content may remain undefined.
*   aWriteClut  - Is != 0, if the caller intends to modify the CLUT information.
*     If == 0, any modifications within the memory may remain ignored depending
*     on the underlying graphics sub-system and its video-memory management.
*   aMemory     - Pointer to an object, where the desired surface pointers
*     should be stored.
*
* RETURN VALUE:
*   If successful, the function should return a kind of a lock object. This
*   object can contain additional information needed when the surface is
*   unlocked again. If you don't want to return additional information, return
*   any value != 0.
*
*   If there was not possible to lock the surface, or the desired access mode
*   is just not supported by the underlying graphics sub-system, the function
*   fails and returns zero. (e.g. VGLite based sub-systems usually allow the
*   write access to surfaces (textures) only. Read access may fail in this
*   case).
*
*******************************************************************************/
unsigned long VGLiteLockSurface
(
  unsigned long     aSurfaceHandle,
  int               aX,
  int               aY,
  int               aWidth,
  int               aHeight,
  int               aIndex,
  int               aCount,
  int               aReadPixel,
  int               aWritePixel,
  int               aReadClut,
  int               aWriteClut,
  XSurfaceMemory*   aMemory
);


/*******************************************************************************
* FUNCTION:
*   VGLiteUnlockSurface
*
* DESCRIPTION:
*   The function VGLiteUnlockSurface() has the job to unlock the given surface
*   and if necessary free any temporary used resources. This function is a
*   counterpart to VGLiteLockSurface().
*
* ARGUMENTS:
*   aSurfaceHandle - Handle to the surface to release the direct memory access.
*   aLockHandle    - value returned by the corresponding LockSurface() call.
*     If LockSurface() has allocated memory for the lock object, you will need
*     to free it now.
*   aX, aY,
*   aWidth,
*   aHeight     - Area within the surface affected by the access operation.
*     (Relative to the top-left corner of the surface). This is the area, the
*     caller wished to read/write the pixel data.
*   aIndex,
*   Count       - Optional start index and number of entries within the CLUT,
*     the caller wished to read/write. These paramaters are used for surfaces
*     with the index8 color format only.
*   aWritePixel - Is != 0, if the caller has modified the pixel information
*     within the surface memory. If == 0, no modification took place, so no
*     surface updates are needed.
*   aWriteClut  - Is != 0, if the caller has modified the CLUT information.
*     If == 0, no modification took place, so no surface updates are needed.
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void VGLiteUnlockSurface
(
  unsigned long     aSurfaceHandle,
  unsigned long     aLockHandle,
  int               aX,
  int               aY,
  int               aWidth,
  int               aHeight,
  int               aIndex,
  int               aCount,
  int               aWritePixel,
  int               aWriteClut
);


/* Macros to redirect the Graphics Engine operations to the above functions. */
#define EwGfxCreateNativeSurface      VGLiteCreateSurface
#define EwGfxDestroyNativeSurface     VGLiteDestroySurface
#define EwGfxLockNativeSurface        VGLiteLockSurface
#define EwGfxUnlockNativeSurface      VGLiteUnlockSurface
#define EwGfxCreateAlpha8Surface      VGLiteCreateSurface
#define EwGfxDestroyAlpha8Surface     VGLiteDestroySurface
#define EwGfxLockAlpha8Surface        VGLiteLockSurface
#define EwGfxUnlockAlpha8Surface      VGLiteUnlockSurface
#define EwGfxCreateIndex8Surface      VGLiteCreateSurface
#define EwGfxDestroyIndex8Surface     VGLiteDestroySurface
#define EwGfxLockIndex8Surface        VGLiteLockSurface
#define EwGfxUnlockIndex8Surface      VGLiteUnlockSurface
#define EwGfxCreateRGB565Surface      VGLiteCreateSurface
#define EwGfxDestroyRGB565Surface     VGLiteDestroySurface
#define EwGfxLockRGB565Surface        VGLiteLockSurface
#define EwGfxUnlockRGB565Surface      VGLiteUnlockSurface


/*******************************************************************************
* FUNCTION:
*   VGLiteLineDriver
*
* DESCRIPTION:
*  The function VGLiteLineDriver() will be called when a line should be drawn.
*  The function draws the line by using VGLite functionality.
*
* ARGUMENTS:
*   aDstHandle - Handle to the surface to fill the area.
*   aDstX1, aDstY1 - Startposition of the line to draw.
*   aDstX2, aDstY2 - Endposition of the line to draw.
*   aClipX, aClipY,
*   aClipWidth, aClipHeight - Clipping to limit the drawing operation.
*   aBlend - != 0 if the operation should be performed with alpha-blending.
*   aColors - Colors to draw the line.
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void VGLiteLineDriver
(
  unsigned long     aDstHandle,
  int               aDstX1,
  int               aDstY1,
  int               aDstX2,
  int               aDstY2,
  int               aClipX,
  int               aClipY,
  int               aClipWidth,
  int               aClipHeight,
  int               aBlend,
  unsigned long*    aColors
);

/* Redirect the line drawing to this VGLite module */
#if EW_USE_VGLITE
  #define EwGfxDrawLineGradient      VGLiteLineDriver
  #define EwGfxDrawLineGradientBlend VGLiteLineDriver
#endif


/*******************************************************************************
* FUNCTION:
*   VGLiteFillDriver
*
* DESCRIPTION:
*  The function VGLiteFillDriver() will be called to fill an area of the surface
*  represented by aDstHandle with a color. The operation is done by VGLite.
*
* ARGUMENTS:
*   aDstHandle - Handle to the surface to fill the area.
*   aDstX, aDstY,
*   aWidth, aHeight - Area to fill.
*   aBlend - != 0 if the operation should be performed with alpha-blending.
*   aColors - Colors to fill the area.
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void VGLiteFillDriver
(
  unsigned long     aDstHandle,
  int               aDstX,
  int               aDstY,
  int               aWidth,
  int               aHeight,
  int               aBlend,
  unsigned long*    aColors
);


/* Redirect the fill area operations to this VGLite module */
#if EW_USE_VGLITE
  #define EwGfxFillLinearGradient           VGLiteFillDriver
  #define EwGfxFillLinearGradientBlend      VGLiteFillDriver
#endif


/*******************************************************************************
* FUNCTION:
*   VGLiteCopyDriver
*
* DESCRIPTION:
*  The function VGLiteCopyDriver() will be called to copy an area from the
*  aSrcHandle surface to the surface aDstHandle. The operation is done by
*  VGLite.
*
* ARGUMENTS:
*   aDstHandle - Handle to the destination surface.
*   aSrcHandle - Handle to the source surface.
*   aDstX, aDstY - Position within the destination surface where to copy the
*     source surface.
*   aSrcX, aSrcY,
*   aWidth, aHeight - Area within the source surface to copy.
*   aBlend - != 0 if the operation should be performed with alpha-blending.
*   aColors - Colors to additionally modulate the copied source pixel.
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void VGLiteCopyDriver
(
  unsigned long     aDstHandle,
  unsigned long     aSrcHandle,
  int               aDstX,
  int               aDstY,
  int               aSrcX,
  int               aSrcY,
  int               aWidth,
  int               aHeight,
  int               aBlend,
  unsigned long*    aColors
);


/* Redirect the copy surface operations to this VGLite module */
#if EW_USE_VGLITE
  #define EwGfxCopyNative                 VGLiteCopyDriver
  #define EwGfxCopyNativeBlend            VGLiteCopyDriver
  #define EwGfxCopyNativeSolid            VGLiteCopyDriver
  #define EwGfxCopyNativeSolidBlend       VGLiteCopyDriver
  #define EwGfxCopyIndex8                 VGLiteCopyDriver
  #define EwGfxCopyIndex8Blend            VGLiteCopyDriver
  #define EwGfxCopyIndex8Solid            VGLiteCopyDriver
  #define EwGfxCopyIndex8SolidBlend       VGLiteCopyDriver
  #define EwGfxCopyAlpha8Solid            VGLiteCopyDriver
  #define EwGfxCopyAlpha8SolidBlend       VGLiteCopyDriver
  #define EwGfxCopyRGB565                 VGLiteCopyDriver
  #define EwGfxCopyRGB565Solid            VGLiteCopyDriver
  #define EwGfxCopyRGB565SolidBlend       VGLiteCopyDriver
#endif


/*******************************************************************************
* FUNCTION:
*   VGLiteWarpDriver
*
* DESCRIPTION:
*  The function VGLiteWarpDriver() will be called to warp a source surface area.
*  The operation is done by VGLite.
*
* ARGUMENTS:
*   aDstHandle - Handle to the destination surface.
*   aSrcHandle - Handle to the source surface.
*   aDstX1, aDstY2, aDstW1 ..
*   aDstX4, aDstY4, aDstW4 - The coordinates of the four corners to project
*     the source surface area.
*   aSrcX, aSrcY,
*   aSrcWidth, aSrcHeight - Area within the source surface to use.
*   aClipX, aClipY,
*   aClipWidth, aClipHeight - Clipping to limit the drawing operation.
*   aBlend - != 0 if the operation should be performed with alpha-blending.
*   aFilter - != 0 if the operation should be performed with bi-linear filter.
*   aColors - Colors to additionally modulate the copied source pixel.
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void VGLiteWarpDriver
(
  unsigned long     aDstHandle,
  unsigned long     aSrcHandle,
  float             aDstX1,
  float             aDstY1,
  float             aDstW1,
  float             aDstX2,
  float             aDstY2,
  float             aDstW2,
  float             aDstX3,
  float             aDstY3,
  float             aDstW3,
  float             aDstX4,
  float             aDstY4,
  float             aDstW4,
  int               aSrcX,
  int               aSrcY,
  int               aSrcWidth,
  int               aSrcHeight,
  int               aClipX,
  int               aClipY,
  int               aClipWidth,
  int               aClipHeight,
  int               aBlend,
  int               aFilter,
  unsigned long*    aColors
);


/* Redirect the warp surface operations to this VGLite module */
#if EW_USE_VGLITE
  #if EW_USE_COPY_MODE
    #define EwGfxWarpPerspNative                      VGLiteWarpDriver
    #define EwGfxWarpPerspNativeFilter                VGLiteWarpDriver
  #endif
  #define EwGfxWarpPerspNativeBlend                   VGLiteWarpDriver
  #define EwGfxWarpPerspNativeFilterBlend             VGLiteWarpDriver

  #if EW_USE_COPY_MODE
    #define EwGfxWarpPerspNativeSolid                 VGLiteWarpDriver
    #define EwGfxWarpPerspNativeFilterSolid           VGLiteWarpDriver
  #endif
  #define EwGfxWarpPerspNativeSolidBlend              VGLiteWarpDriver
  #define EwGfxWarpPerspNativeFilterSolidBlend        VGLiteWarpDriver

  #if EW_USE_COPY_MODE
    #define EwGfxWarpPerspIndex8                      VGLiteWarpDriver
    #define EwGfxWarpPerspIndex8Filter                VGLiteWarpDriver
  #endif
  #define EwGfxWarpPerspIndex8Blend                   VGLiteWarpDriver
  #define EwGfxWarpPerspIndex8FilterBlend             VGLiteWarpDriver

  #if EW_USE_COPY_MODE
    #define EwGfxWarpPerspIndex8Solid                 VGLiteWarpDriver
    #define EwGfxWarpPerspIndex8FilterSolid           VGLiteWarpDriver
  #endif
  #define EwGfxWarpPerspIndex8SolidBlend              VGLiteWarpDriver
  #define EwGfxWarpPerspIndex8FilterSolidBlend        VGLiteWarpDriver

  #if EW_USE_COPY_MODE
    #define EwGfxWarpPerspAlpha8Solid                 VGLiteWarpDriver
    #define EwGfxWarpPerspAlpha8FilterSolid           VGLiteWarpDriver
  #endif
  #define EwGfxWarpPerspAlpha8SolidBlend              VGLiteWarpDriver
  #define EwGfxWarpPerspAlpha8FilterSolidBlend        VGLiteWarpDriver

  #define EwGfxWarpPerspRGB565                        VGLiteWarpDriver
  #define EwGfxWarpPerspRGB565Filter                  VGLiteWarpDriver

  #if EW_USE_COPY_MODE
    #define EwGfxWarpPerspRGB565Solid                 VGLiteWarpDriver
    #define EwGfxWarpPerspRGB565FilterSolid           VGLiteWarpDriver
  #endif
  #define EwGfxWarpPerspRGB565SolidBlend              VGLiteWarpDriver
  #define EwGfxWarpPerspRGB565FilterSolidBlend        VGLiteWarpDriver

  #if EW_USE_COPY_MODE
    #define EwGfxWarpAffineNative                     VGLiteWarpDriver
    #define EwGfxWarpAffineNativeFilter               VGLiteWarpDriver
  #endif
  #define EwGfxWarpAffineNativeBlend                  VGLiteWarpDriver
  #define EwGfxWarpAffineNativeFilterBlend            VGLiteWarpDriver

  #if EW_USE_COPY_MODE
    #define EwGfxWarpAffineNativeSolid                VGLiteWarpDriver
    #define EwGfxWarpAffineNativeFilterSolid          VGLiteWarpDriver
  #endif
  #define EwGfxWarpAffineNativeSolidBlend             VGLiteWarpDriver
  #define EwGfxWarpAffineNativeFilterSolidBlend       VGLiteWarpDriver

  #if EW_USE_COPY_MODE
    #define EwGfxWarpAffineIndex8                     VGLiteWarpDriver
    #define EwGfxWarpAffineIndex8Filter               VGLiteWarpDriver
  #endif

  #define EwGfxWarpAffineIndex8Blend                  VGLiteWarpDriver
  #define EwGfxWarpAffineIndex8FilterBlend            VGLiteWarpDriver

  #if EW_USE_COPY_MODE
    #define EwGfxWarpAffineIndex8Solid                VGLiteWarpDriver
    #define EwGfxWarpAffineIndex8FilterSolid          VGLiteWarpDriver
  #endif
  #define EwGfxWarpAffineIndex8SolidBlend             VGLiteWarpDriver
  #define EwGfxWarpAffineIndex8FilterSolidBlend       VGLiteWarpDriver

  #if EW_USE_COPY_MODE
    #define EwGfxWarpAffineAlpha8Solid                VGLiteWarpDriver
    #define EwGfxWarpAffineAlpha8FilterSolid          VGLiteWarpDriver
  #endif
  #define EwGfxWarpAffineAlpha8SolidBlend             VGLiteWarpDriver
  #define EwGfxWarpAffineAlpha8FilterSolidBlend       VGLiteWarpDriver

  #define EwGfxWarpAffineRGB565                       VGLiteWarpDriver
  #define EwGfxWarpAffineRGB565Filter                 VGLiteWarpDriver
  #define EwGfxWarpAffineRGB565Solid                  VGLiteWarpDriver
  #define EwGfxWarpAffineRGB565FilterSolid            VGLiteWarpDriver

  #define EwGfxScaleNative                            VGLiteWarpDriver
  #define EwGfxScaleNativeFilter                      VGLiteWarpDriver
  #define EwGfxScaleNativeSolid                       VGLiteWarpDriver
  #define EwGfxScaleNativeFilterSolid                 VGLiteWarpDriver
  #define EwGfxScaleIndex8                            VGLiteWarpDriver
  #define EwGfxScaleIndex8Filter                      VGLiteWarpDriver
  #define EwGfxScaleIndex8Solid                       VGLiteWarpDriver
  #define EwGfxScaleIndex8FilterSolid                 VGLiteWarpDriver
  #define EwGfxScaleAlpha8Solid                       VGLiteWarpDriver
  #define EwGfxScaleAlpha8FilterSolid                 VGLiteWarpDriver
  #define EwGfxScaleRGB565Solid                       VGLiteWarpDriver
  #define EwGfxScaleRGB565FilterSolid                 VGLiteWarpDriver
#endif


/*******************************************************************************
* FUNCTION:
*   VGLitePolygonDriver
*
* DESCRIPTION:
*  The function VGLitePolygonDriver() will be called to fill polygon area within
*  the surface aDstHandle with a color. The operation is done by VGLite.
*
* ARGUMENTS:
*   aDstHandle - Handle to the destination surface.
*   aPaths - The content of the path (a serie of coordinates).
*   aDstX, aDstY,
*   aWidth, aHeight - Clipping to limit the drawing operation.
*   aBlend - != 0 if the operation should be performed with alpha-blending.
*   aAntialiased - != 0 if the operation should be performed with active anti
*     aliasing filter.
*   aNonZeroWinding - if != 0, the polygon is filled with the non-zero-winding
*     rule.
*   aColors - Colors to additionally modulate the copied source pixel.
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void VGLitePolygonDriver
(
  unsigned long     aDstHandle,
  int*              aPaths,
  int               aDstX,
  int               aDstY,
  int               aWidth,
  int               aHeight,
  int               aBlend,
  int               aAntialiased,
  int               aNonZeroWinding,
  unsigned long*    aColors
);


/* Redirect the fill polygon area operations to this VGLite module */
#if EW_USE_VGLITE
  #define EwGfxPolygonLinearGradient                   VGLitePolygonDriver
  #define EwGfxPolygonAntialiasedLinearGradient        VGLitePolygonDriver
  #define EwGfxPolygonLinearGradientBlend              VGLitePolygonDriver
  #define EwGfxPolygonAntialiasedLinearGradientBlend   VGLitePolygonDriver
#endif


#ifdef __cplusplus
  }
#endif

#endif /* EWEXTGFX_H */


/* pba */
