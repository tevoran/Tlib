#ifndef TLIB_MATH_VECTOR
#define TLIB_MATH_VECTOR

#include "floattypes.h"

union T_vec2
{
    struct
    {
        f32 x;
        f32 y;
    };
    struct
    {
        f32 u;
        f32 v;
    };
    struct
    {
        f32 s;
        f32 t;
    };
    struct
    {
        f32 a;
        f32 b;
    };
    struct
    {
        f32 w;
        f32 h;
    };
    struct
    {
        f32 width;
        f32 height;
    };
    f32 array[2];
} typedef T_vec2;

union T_vec3
{
    struct
    {
        f32 x;
        f32 y;
        f32 z;
    };
    struct
    {
        f32 r;
        f32 g;
        f32 b;
    };
    struct
    {
        f32 width;
        f32 height;
        f32 depth;
    };
    f32 array[3];
} typedef T_vec3;

union T_vec4
{
    struct
    {
        f32 x;
        f32 y;
        f32 z;
        f32 w;
    };
    struct
    {
        f32 r;
        f32 g;
        f32 b;
        f32 a;
    };
    f32 array[4];
} typedef T_vec4;

//macros
#define VEC_ADD(TYPE, FUNCNAME)                                         \
    static inline TYPE FUNCNAME(TYPE a, TYPE b)                         \
    {                                                                   \
        TYPE c;                                                         \
        for(int i = 0; i < sizeof(TYPE)/sizeof(f32); i++)               \
        {                                                               \
            c.array[i] = a.array[i] + b.array[i];                       \
        }                                                               \
        return c;                                                       \
    }

#define VEC_SUB(TYPE, FUNCNAME)                                         \
    static inline TYPE FUNCNAME(TYPE a, TYPE b)                         \
    {                                                                   \
        TYPE c;                                                         \
        for(int i = 0; i < sizeof(TYPE)/sizeof(f32); i++)               \
        {                                                               \
            c.array[i] = a.array[i] - b.array[i];                       \
        }                                                               \
        return c;                                                       \
    }
    
//vec2
VEC_ADD(T_vec2, T_v2_add);
VEC_SUB(T_vec2, T_v2_sub);

//vec3
VEC_ADD(T_vec3, T_v3_add);
VEC_SUB(T_vec3, T_v3_sub);

//vec4
VEC_ADD(T_vec4, T_v4_add);
VEC_SUB(T_vec4, T_v4_sub);

#endif /* TLIB_MATH_VECTOR */
