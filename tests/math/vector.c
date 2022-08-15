#include <stdio.h>
#include <Tlib/math.h>
#include <Tlib/inttypes.h>


#define TEST_VEC2(FUNCTION, A_X, A_Y, B_X, B_Y, D_X, D_Y)                   \
{                                                                           \
    char string[100] = #FUNCTION;                                           \
    printf("testing %s: ", string);                                         \
    T_vec2 a,b,c,d;                                                         \
    a.x = A_X;                                                              \
    a.y = A_Y;                                                              \
    b.x = B_X;                                                              \
    b.y = B_Y;                                                              \
    d.x = D_X;                                                              \
    d.y = D_Y;                                                              \
    c = FUNCTION(a, b);                                                     \
    if(c.x == d.x && c.y == d.y)                                            \
    {                                                                       \
        printf("pass\n");                                                   \
    }                                                                       \
    else                                                                    \
    {                                                                       \
        printf("fail\n");                                                   \
    }                                                                       \
}

#define TEST_VEC3(FUNCTION, A_X, A_Y, A_Z, B_X, B_Y, B_Z, D_X, D_Y, D_Z)    \
{                                                                           \
    char string[100] = #FUNCTION;                                           \
    printf("testing %s: ", string);                                         \
    T_vec3 a,b,c,d;                                                         \
    a.x = A_X;                                                              \
    a.y = A_Y;                                                              \
    a.z = A_Z;                                                              \
    b.x = B_X;                                                              \
    b.y = B_Y;                                                              \
    b.z = B_Z;                                                              \
    d.x = D_X;                                                              \
    d.y = D_Y;                                                              \
    d.z = D_Z;                                                              \
    c = FUNCTION(a, b);                                                     \
    if(c.x == d.x && c.y == d.y && c.z == d.z)                              \
    {                                                                       \
        printf("pass\n");                                                   \
    }                                                                       \
    else                                                                    \
    {                                                                       \
        printf("fail\n");                                                   \
    }                                                                       \
}

#define TEST_VEC4(FUNCTION,                                                 \
    A_X, A_Y, A_Z, A_W, B_X, B_Y, B_Z, B_W, D_X, D_Y, D_Z, D_W)             \
{                                                                           \
    char string[100] = #FUNCTION;                                           \
    printf("testing %s: ", string);                                         \
    T_vec4 a,b,c,d;                                                         \
    a.x = A_X;                                                              \
    a.y = A_Y;                                                              \
    a.z = A_Z;                                                              \
    a.w = A_W;                                                              \
    b.x = B_X;                                                              \
    b.y = B_Y;                                                              \
    b.z = B_Z;                                                              \
    b.w = B_W;                                                              \
    d.x = D_X;                                                              \
    d.y = D_Y;                                                              \
    d.z = D_Z;                                                              \
    d.w = D_W;                                                              \
    c = FUNCTION(a, b);                                                     \
    if(c.x == d.x && c.y == d.y && c.z == d.z && c.w == d.w)                \
    {                                                                       \
        printf("pass\n");                                                   \
    }                                                                       \
    else                                                                    \
    {                                                                       \
        printf("fail\n");                                                   \
    }                                                                       \
}

#define TEST_VEC_MUL_FLOAT(FUNCTION, TYPE, A, B, C)                         \
{                                                                           \
    char string[100] = #FUNCTION;                                           \
    printf("testing %s: ", string);                                         \
    TYPE d;                                                                 \
    d = FUNCTION(a, b);                                                     \
    bool pass = true;                                                       \
    for(int i = 0; i < sizeof(TYPE)/sizeof(f32); i++)                       \
    {                                                                       \
        if(d.array[i] != c.array[i])                                        \
        {                                                                   \
            pass = false;                                                   \
        }                                                                   \
    }                                                                       \
    if(pass)                                                                \
    {                                                                       \
        printf("pass\n");                                                   \
    }                                                                       \
    else                                                                    \
    {                                                                       \
        printf("fail\n");                                                   \
    }                                                                       \
}

int main(void)
{
    //vec2
    TEST_VEC2(T_v2_add, 1.0f, 2.0f, 1.0f, 2.0f, 2.0f, 4.0f);
    TEST_VEC2(T_v2_sub, 1.0f, 2.0f, 1.0f, 2.0f, 0.0f, 0.0f);
    {
        T_vec2 a = {1.0f, 1.0f};
        T_vec2 c = {2.0f, 2.0f};
        f32 b = 2.0f;
        TEST_VEC_MUL_FLOAT(T_v2_mul_f, T_vec2, a, b, c);
    }

    //vec3
    TEST_VEC3(T_v3_add, 1.0f, 2.0f, 3.0f, 1.0f, 2.0f, 3.0f, 2.0f, 4.0f, 6.0f);
    TEST_VEC3(T_v3_sub, 1.0f, 2.0f, 3.0f, 1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f);
    {
        T_vec3 a = {1.0f, 1.0f, 1.0f};
        T_vec3 c = {2.0f, 2.0f, 2.0f};
        f32 b = 2.0f;
        TEST_VEC_MUL_FLOAT(T_v3_mul_f, T_vec3, a, b, c);
    }

    //vec4
    TEST_VEC4(T_v4_add,
        1.0f, 2.0f, 3.0f, 4.0f, 1.0f, 2.0f, 3.0f, 4.0f, 2.0f, 4.0f, 6.0f, 8.0f);
    TEST_VEC4(T_v4_sub,
        1.0f, 2.0f, 3.0f, 4.0f, 1.0f, 2.0f, 3.0f, 4.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    {
        T_vec4 a = {1.0f, 1.0f, 1.0f, 1.0f};
        T_vec4 c = {2.0f, 2.0f, 2.0f, 2.0f};
        f32 b = 2.0f;
        TEST_VEC_MUL_FLOAT(T_v4_mul_f, T_vec4, a, b, c);
    } 
    return 0;
}