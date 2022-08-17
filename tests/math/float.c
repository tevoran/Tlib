#include <stdio.h>
#include <Tlib/math.h>

#define TEST_F(FUNCTION, A, B, C)                   \
{                                                   \
    char string[100] = #FUNCTION;                   \
    printf("testing %s: ", string);                 \
    f32 a = A;                                      \
    f32 b = B;                                      \
    if(C == FUNCTION(a, b))                         \
    {                                               \
        printf("pass\n");                           \
    }                                               \
    else                                            \
    {                                               \
        printf("fail\n");                           \
    }                                               \
}

int main(void)
{
    TEST_F(T_f_min, 1.0f, 2.0f, 1.0f);
    TEST_F(T_f_max, 1.0f, 2.0f, 2.0f);
    return 0;
}