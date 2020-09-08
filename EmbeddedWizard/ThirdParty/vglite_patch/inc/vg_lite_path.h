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

#ifndef vg_lite_path_h
#define vg_lite_path_h

#include "vg_lite.h"

#if !DDRLESS /* DDRLess does not allow path uploading. */
/*!
 @abstract Upload a path to GPU memory.

 @discussion
 In normal cases, the VGLite driver will copy any path data into a command buffer structure during runtime. This does
 take some time if there are many paths to be rendered. Also, in an embedded system the path data wont change - so it
 makes sense to upload the path data into GPU memory in such a form the GPU can directly access it.

 This function will allocate a buffer that will contain the path data and the required command buffer header and footer
 data for the GPU to access the data directly.

 @param path
 Pointer to a <code>vg_lite_path_t</code> structure that contains the path to be uploaded. Some fields in this structure
 will be modified to point to a command buffer instead of the native path data.

 @result
 A pointer to a <code>vg_lite_buffer_t</code> structure that contains the command buffer and path data after uploading
 it to GPU memory. <code>NULL</code> is returned if there is an error.
 */
vg_lite_error_t vg_lite_upload_path(vg_lite_path_t *path);
#endif /* #if !DDRLESS */

#endif /* vg_lite_path_h */
