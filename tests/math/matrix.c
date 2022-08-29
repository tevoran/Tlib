#include <Tlib/math.h>

#define BUFFER_SIZE 1024
int main(void)
{
	//mat2
	T_mat2 mat2;
	mat2 = T_m2_make_identity();
	char mat2_str[BUFFER_SIZE];
	T_m2_get_string(mat2, mat2_str, BUFFER_SIZE);
	printf("%s\n", mat2_str);

	//mat3
	T_mat3 mat3;
	mat3 = T_m3_make_identity();
	char mat3_str[BUFFER_SIZE];
	T_m3_get_string(mat3, mat3_str, BUFFER_SIZE);
	printf("%s\n", mat3_str);

	//mat4
	T_mat4 mat4;
	mat4 = T_m4_make_identity();
	char mat4_str[BUFFER_SIZE];
	T_m4_get_string(mat4, mat4_str, BUFFER_SIZE);
	printf("%s\n", mat4_str);
}