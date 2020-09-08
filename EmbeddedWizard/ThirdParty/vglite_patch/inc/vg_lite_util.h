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

#ifndef _vg_lite_util_h_
#define _vg_lite_util_h_

#include "vg_lite.h"
#include "vg_lite_matrix.h"
#include "vg_lite_path.h"

#ifdef __cplusplus
extern "C" {
#endif

/*!
 @abstract Load a PNG file into a buffer.

 @discussion
 Using the PNG library, a PNG file will be read into memory and a <code>vg_lite_buffer_t</code> structure will be filled
 in with the information about this PNG file.

 Normal kernel allocation will happen for the PNG file bits, so the buffer can later be freed by the {@link
 vg_lite_free} function when it is no longer required.

 @param buffer
 A pointer to a <code>vg_lite_buffer_t</code> structure that will be filled in on success.

 @param name
 The name of the PNG file.

 @result
 A boolean value indicating success (1) or failure (0).
 */
int vg_lite_load_png(vg_lite_buffer_t *buffer, const char *name);

/*!
 @abstract Load a RAW file into a buffer.

 @param buffer
 A pointer to a <code>vg_lite_buffer_t</code> structure that will be filled in on success.

 @param name
 The name of the RAW file.

 @result
 A boolean value indicating success (1) or failure (0).
 */
int vg_lite_load_raw(vg_lite_buffer_t *buffer, const char *name);

/*!
 @abstract Load a RAW file into a buffer with line by line way.

 @param buffer
 A pointer to a <code>vg_lite_buffer_t</code> structure that will be filled in on success.

 @param name
 The name of the RAW file.

 @result
 A boolean value indicating success (1) or failure (0).
 */
int vg_lite_load_raw_byline(vg_lite_buffer_t *buffer, const char *name);

/*!
 @abstract Save a buffer to a PNG file.

 @discussion
 Using the PNG library, the specified buffer will be written into a PNG.

 @param name
 The name of the PNG file.

 @param buffer
 A pointer to a <code>vg_lite_buffer_t</code> structure that holds the image that needs to written.

 @result
 A boolean value indicating success (1) or failure (0).
 */
int vg_lite_save_png(const char *name, vg_lite_buffer_t *buffer);

/*!
 @abstract Save a buffer to a RAW file.

 @param name
 The name of the RAW file.

 @param buffer
 A pointer to a <code>vg_lite_buffer_t</code> structure that holds the image that needs to written.

 @result
 A boolean value indicating success (1) or failure (0).
 */
int vg_lite_save_raw(const char *name, vg_lite_buffer_t *buffer);

/*!
 @abstract Save a buffer to a RAW file.

 @param name
 The name of the RAW file.

 @param buffer
 A pointer to a <code>vg_lite_buffer_t</code> structure that holds the image that needs to written.

 @result
 A boolean value indicating success (1) or failure (0).
 */
int vg_lite_save_raw_byline(const char *name, vg_lite_buffer_t *buffer);

/*!
 @abstract Get a buffer pointing to the frame buffer if any.

 @discussion
 On most devices their will be a frame buffer attachment. This function wraps the complexities of using the frame buffer
 device as an output. The buffer returned holds the information about the frame buffer. When the frame buffer is no
 longer needed,
 {@link vg_lite_fb_close} should be called with the buffer returned by this function.

 If the device doesn't support a frame buffer, <code>NULL</code> will be returned.

 @result
 Returns a pointer to a <code>vg_lite_buffer_t</code> structure which can be used as a normal buffer on success. On
 failure <code>NULL</code> will be returned.
 */
vg_lite_buffer_t *vg_lite_fb_open(void);

/*!
 @abstract Get a buffer pointing to the frame buffer if any.

 @discussion
 On most devices their will be a frame buffer attachment. This function wraps the complexities of using the frame buffer
 device as an output. The buffer returned holds the information about the frame buffer. When the frame buffer is no
 longer needed,
 {@link vg_lite_fb_close} should be called with the buffer returned by this function.

 If the device doesn't support a frame buffer, <code>NULL</code> will be returned.

 @result
 Returns a pointer to a <code>vg_lite_buffer_t</code> structure which can be used as a normal buffer on success. On
 failure <code>NULL</code> will be returned.
 */
void vg_lite_fb_close(vg_lite_buffer_t *buffer);

#ifdef __cplusplus
}
#endif
#endif /* _vg_lite_util_h_ */
