#ifndef TLIB_MATH_MATRIX
#define TLIB_MATH_MATRIX

#include "floattypes.h"
#include "../inttypes.h"
#include "stdio.h"

/*
    In Tlib matrices are defined like this.
    A is a matrix with the first entry in the array field being
    the column of the matrix. The second entry is the row.
    This way A.array[3][2] would point to the entry in the
    fourth row and in the the third column. Since in C the first
    entry has the index zero.
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

//mat2
MAT_GET_CONTENT(T_mat2, T_m2_get_string, 2, 2);
MAT_IDENTITY(T_mat2, T_m2_make_identity, 2, 2);

//mat3
MAT_GET_CONTENT(T_mat3, T_m3_get_string, 3, 3);
MAT_IDENTITY(T_mat3, T_m3_make_identity, 3, 3);

//mat4
MAT_GET_CONTENT(T_mat4, T_m4_get_string, 4, 4);
MAT_IDENTITY(T_mat4, T_m4_make_identity, 4, 4);

#endif /* TLIB_MATH_MATRIX */