#ifndef TLIB_MATH_BARYCENTRIC_COORDINATES
#define TLIB_MATH_BARYCENTRIC_COORDINATES

#include "floattypes.h"
#include "vector.h"

static inline T_vec3 T_get_barycentric_coords(
	T_vec2 v1,
	T_vec2 v2,
	T_vec2 v3,
	T_vec2 current)
{
	T_vec3 out;
	f32 div =
		1.0f / ((v2.x - v1.x) * (v3.y - v2.y)
		- (v2.y - v1.y) * (v3.x - v2.x));
	out.array[0] =
		((v2.x - current.x) * (v3.y - current.y)
		- (v3.x - current.x) * (v2.y - current.y))
		*div;
	out.array[1] =
		((v3.x - current.x) * (v1.y - current.y)
		- (v1.x - current.x) * (v3.y - current.y))
		*div;
	out.array[2] = 1.0f - out.array[1] - out.array[0];
	return out;
}

#endif /* TLIB_MATH_BARYCENTRIC_COORDINATES */
