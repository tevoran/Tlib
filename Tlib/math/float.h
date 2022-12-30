#ifndef TLIB_MATH_FLOAT
#define TLIB_MATH_FLOAT

static inline f32 T_f_min(f32 a, f32 b)
{
	if(a < b)
	{
		return a;
	}
	return b;
}

static inline f32 T_f_max(f32 a, f32 b)
{
	if(a > b)
	{
		return a;
	}
	return b;
}

#endif /* TLIB_MATH_FLOAT */
