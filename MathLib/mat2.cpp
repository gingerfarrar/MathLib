#include "mat2.h"
#include "flops.h"

bool operator==(const mat2 & A, const mat2 & B)
{
	return A[0] == B[0] &&	A[1] == B[1];
		   
}
bool operator!=(const mat2 & A, const mat2 & B)
{
	return!(A == B);
}
mat2 operator+(const mat2 & A, const mat2 & B)
{
	return mat2{ A.m[0] + B.m[0],A.m[1] + B.m[1],
				 A.m[2] + B.m[2],A.m[3] + B.m[3] };
}
mat2 operator-(const mat2 & A, const mat2 & B)
{
	return mat2{ A.m[0] - B.m[0],A.m[1] - B.m[1],
				 A.m[2] - B.m[2],A.m[3] - B.m[3] };
}
mat2 operator-(const mat2 & A)
{
	return mat2{ -A.m[0], -A.m[1],-A.m[2],-A.m[3] };
}

mat2 mat2Identity() { return mat2{ 1,0,0,1 }; }
mat2 transpose(const mat2 &A)
{
	mat2 retval = A;
	retval.mm[1][0] = A.mm[0][1];
	retval.mm[0][1] = A.mm[1][0];
	return A;
}
vec2 operator*(const mat2 & A, const vec2 & B)
{
	vec2 retval;
	mat2 At = transpose(A);

	retval.x = dot(At[0], B);
	retval.y = dot(At[1], B);
	return retval;
}
mat2 operator*(const mat2 & A, float s)
{
	return mat2{ A.m[0] * s,
				 A.m[1] * s,
				 A.m[2] * s,
				 A.m[3] * s };

}
mat2 operator*(float s, const mat2 & A)
{
	return A*s;
}
mat2 operator*(const mat2 & A, const mat2 & B)
{
	return mat2{ A.m[0] * B.m[0] + A.m[2] * B.m[1],A.m[1] * B.m[0] + A.m[3] * B.m[1],
		         A.m[0] * B.m[2] + A.m[2] * B.m[3],A.m[1] * B.m[2] + A.m[3] * B.m[3] };
}
float determinant(const mat2 & A)
{
	return  A.m[0] * A.m[2] - A.m[1] * A.m[3];
}
mat2 inverse(const mat2 &A)
{
	return mat2{1 / (A.m[0]*A.m[3] - A.m[2]*A.m[1])};
}

vec2 mat2::operator[](unsigned idx) const
{
	return c[idx];
}
vec2 &mat2::operator[](unsigned idx)
{
	return c[idx];
}