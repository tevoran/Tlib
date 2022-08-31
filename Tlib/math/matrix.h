#ifndef TLIB_MATH_MATRIX
#define TLIB_MATH_MATRIX

#include "floattypes.h"
#include "../inttypes.h"
#include "vector.h"
#include <stdio.h>

/*
    In Tlib matrices are defined like this:
    A is a matrix with the first entry in the array field being
    the number of rows of the matrix. The second entry is the number of rows.
    This way A.array[3][2] would point to the entry in the
    fourth row and in the the third column. Since in C the first
    entry has the index zero.

    The vectors are treated as column vectors. They have only one column with
    a different amount of rows. A T_vec2 vector has 1 column and 2 rows in
    that column. 
*/

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

#define MAT_GET_CONTENT(TYPE, FUNCNAME, DIMENSION_COL, DIMENSION_ROW)           \
    static inline void FUNCNAME(TYPE mat, char *string, u16 num_elements)       \
    {                                                                           \
        if(num_elements < DIMENSION_ROW * DIMENSION_COL * 12)                   \
        {                                                                       \
            return;                                                             \
        }                                                                       \
                                                                                \
        u16 offset = 0;                                                         \
        for(u32 iy = 0; iy < DIMENSION_ROW; iy++)                               \
        {                                                                       \
            for(u32 ix = 0; ix < DIMENSION_COL; ix++)                           \
            {                                                                   \
                offset += sprintf(&string[offset], "%f ", mat.array[iy][ix]);   \
            }                                                                   \
            offset += sprintf(&string[offset], "\n");                           \
        }                                                                       \
    }

#define MAT_IDENTITY(TYPE, FUNCNAME, DIMENSION_COL, DIMENSION_ROW)              \
    static inline TYPE FUNCNAME()                                               \
    {                                                                           \
        TYPE mat;                                                               \
        for(u32 iy = 0; iy < DIMENSION_ROW; iy++)                               \
        {                                                                       \
            for(u32 ix = 0; ix < DIMENSION_COL; ix++)                           \
            {                                                                   \
                if(ix == iy)                                                    \
                {                                                               \
                    mat.array[iy][ix] = 1.0f;                                   \
                }                                                               \
                else                                                            \
                {                                                               \
                    mat.array[iy][ix] = 0.0f;                                   \
                }                                                               \
            }                                                                   \
        }                                                                       \
        return mat;                                                             \
    }

#define MAT_MULTIPLY(TYPE, FUNCNAME, DIMENSION)                                 \
    static inline TYPE FUNCNAME(TYPE a, TYPE b)                                 \
    {                                                                           \
        TYPE mat;                                                               \
        for(u8 iy = 0; iy < DIMENSION; iy++)                                    \
        {                                                                       \
            for(u8 ix = 0; ix < DIMENSION; ix++)                                \
            {                                                                   \
                f32 value = 0.0f;                                               \
                for(u8 i = 0; i < DIMENSION; i++)                               \
                {                                                               \
                    value += a.array[iy][i] * b.array[i][ix];                   \
                }                                                               \
                mat.array[iy][ix] = value;                                      \
            }                                                                   \
        }                                                                       \
        return mat;                                                             \
    }

#define MAT_VEC_MUL(TYPE_MAT, TYPE_VEC, FUNCNAME, DIMENSION)                    \
    static inline TYPE_VEC FUNCNAME(TYPE_MAT mat, TYPE_VEC vec)                 \
    {                                                                           \
        TYPE_VEC vec_out;                                                       \
        for(u8 i = 0; i < DIMENSION; i++)                                       \
        {                                                                       \
            vec_out.array[i] = 0.0f;                                            \
            for(u8 j = 0; j < sizeof(TYPE_VEC)/sizeof(f32); j++)                \
            {                                                                   \
                vec_out.array[i] += mat.array[i][j] * vec.array[j];             \
            }                                                                   \
        }                                                                       \
        return vec_out;                                                         \
    }

//mat2
MAT_GET_CONTENT(T_mat2, T_m2_get_string, 2, 2);
MAT_IDENTITY(T_mat2, T_m2_make_identity, 2, 2);
MAT_MULTIPLY(T_mat2, T_m2_mul, 2);
MAT_VEC_MUL(T_mat2, T_vec2, T_m2_v2_mul, 2);

//mat3
MAT_GET_CONTENT(T_mat3, T_m3_get_string, 3, 3);
MAT_IDENTITY(T_mat3, T_m3_make_identity, 3, 3);
MAT_MULTIPLY(T_mat3, T_m3_mul, 3);
MAT_VEC_MUL(T_mat3, T_vec3, T_m3_v3_mul, 3);

//mat4
MAT_GET_CONTENT(T_mat4, T_m4_get_string, 4, 4);
MAT_IDENTITY(T_mat4, T_m4_make_identity, 4, 4);
MAT_MULTIPLY(T_mat4, T_m4_mul, 4);
MAT_VEC_MUL(T_mat4, T_vec4, T_m4_v4_mul, 4);

#endif /* TLIB_MATH_MATRIX */