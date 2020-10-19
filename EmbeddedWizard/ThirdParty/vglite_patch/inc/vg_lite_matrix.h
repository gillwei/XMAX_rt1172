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

#ifndef vg_lite_matrix_h
#define vg_lite_matrix_h

#include "vg_lite.h"

/*!
 @abstract Load an identity matrix.

 @discussion
 Load an identity matrix into a matrix variable.

 @param matrix
 Pointer to a <code>vg_lite_matrix_t</code> structure that will be loaded with an identity matrix.
 */
void vg_lite_identity(vg_lite_matrix_t *matrix);

/*!
 @abstract Translate a matrix.

 @discussion
 Translate a matrix to a new position.

 @param x
 X location of the transformation.

 @param y
 Y location of the transformation.

 @param matrix
 Pointer to a <code>vg_lite_matrix_t</code> structure that will be translated.
 */
void vg_lite_translate(vg_lite_float_t x, vg_lite_float_t y, vg_lite_matrix_t *matrix);

/*!
 @abstract Scale a matrix.

 @discussion
 Scale a matrix in both x and y directions.

 @param scale_x
 Horizontal scale.

 @param scale_y
 Vertical scale.

 @param matrix
 Pointer to a <code>vg_lite_matrix_t</code> structure that will be scaled.
 */
void vg_lite_scale(vg_lite_float_t scale_x, vg_lite_float_t scale_y, vg_lite_matrix_t *matrix);

/*!
 @abstract Rotate a matrix.

 @discussion
 Rotate a matrix a certain number of degrees.

 @param degrees
 Number of degrees to rotate the matrix around. Positive numbers rotate counter clock wise.

 @param matrix
 Pointer to a <code>vg_lite_matrix_t</code> structure that will be rotated.
 */
void vg_lite_rotate(vg_lite_float_t degrees, vg_lite_matrix_t *matrix);

/*!
 @abstract projective transformation.

 @discussion
 set perspective matrix.

 @param degrees
 px: indicate w0 of perspective transformation matrix
 py: indicate w1 of perspective transformation matrix
 @param matrix
 Pointer to a <code>vg_lite_matrix_t</code> structure that will be rotated.
 */
void vg_lite_perspective(vg_lite_float_t px, vg_lite_float_t py, vg_lite_matrix_t *matrix);

#endif /* vg_lite_matrix_h */
