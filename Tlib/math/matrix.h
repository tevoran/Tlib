#ifndef TLIB_MATH_MATRIX
#define TLIB_MATH_MATRIX

#include "floattypes.h"

struct T_mat2
{
	f32 array[2][2];
} typedef T_mat2;

struct T_mat3
{
	f32 array[3][3];
} typedef T_mat3;

struct T_mat4
{
	f32 array[4][4];
} typedef T_mat4;

#endif /* TLIB_MATH_MATRIX */