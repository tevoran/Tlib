#include <stdio.h>
#include <Tlib/math.h>

#define TEST_VEC2(FUNCTION, A_X, A_Y, B_X, B_Y, D_X, D_Y)	\
{															\
	char string[100] = #FUNCTION;							\
	printf("testing %s: ", string);							\
	T_vec2 a,b,c,d;											\
	a.x = A_X;												\
	a.y = A_Y;												\
	b.x = B_X;												\
	b.y = B_Y;												\
	d.x = D_X;												\
	d.y = D_Y;												\
	c = FUNCTION(a, b);										\
	if(c.x == d.x && c.y == d.y)							\
	{														\
		printf("pass\n");									\
	}														\
	else													\
	{														\
		printf("fail\n");									\
	}														\
}

#define TEST_VEC3(FUNCTION, A_X, A_Y, A_Z, B_X, B_Y, B_Z, D_X, D_Y, D_Z)    \
{                                                                           \
    char string[100] = #FUNCTION;                                           \
    printf("testing %s: ", string);                                         \
    T_vec3 a,b,c,d;                                                         \
    a.x = A_X;                                                              \
    a.y = A_Y;                                                              \
    b.x = B_X;                                                              \
    b.y = B_Y;                                                              \
    d.x = D_X;                                                              \
    d.y = D_Y;                                                              \
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


int main(void)
{
	//vec2
	TEST_VEC2(T_v2_add, 1.0f, 2.0f, 1.0f, 2.0f, 2.0f, 4.0f);
    TEST_VEC2(T_v2_sub, 1.0f, 2.0f, 1.0f, 2.0f, 0.0f, 0.0f);
	return 0;
}