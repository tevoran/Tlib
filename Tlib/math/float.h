#ifndef TLIB_MATH_FLOAT
#define TLIB_MATH_FLOAT

static inline f32 T_f_min(f32 a, f32 b)
{
	f32 c;
	if(a < b)
	{
		c = a;
	}
	else
	{
		c = b;
	}
	return c;
}

static inline f32 T_f_max(f32 a, f32 b)
{
	f32 c;
	if(a > b)
	{
		c = a;
	}
	else
	{
		c = b;
	}
	return c;
}

#endif /* TLIB_MATH_FLOAT */