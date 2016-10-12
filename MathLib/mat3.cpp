#include "flops.h"
#include "mat3.h"
#include <cmath>

bool operator==(const mat3 & A, const mat3 & B)
{
	return A[0] == B[0] && A[1] == B[1] && A[2] == B[2];

}
bool operator!=(const mat3 & A, const mat3 & B)
{
	return!(A == B);
}
mat3 operator+(const mat3 & A, const mat3 & B)
{
	return mat3{ A.m[0] + B.m[0],A.m[1] + B.m[1],
				 A.m[2] + B.m[2],A.m[3] + B.m[3],
				 A.m[4] + B.m[4],A.m[5] + B.m[5],
				 A.m[6] + B.m[6],A.m[7] + B.m[7],
				 A.m[8] + B.m[8] };
}
mat3 operator-(const mat3 & A, const mat3 & B)
{
	return mat3{ A.m[0] - B.m[0],A.m[1] - B.m[1],
				 A.m[2] - B.m[2],A.m[3] - B.m[3], 
				 A.m[4] - B.m[4],A.m[5] - B.m[5],
				 A.m[6] - B.m[6],A.m[7] - B.m[7],
				 A.m[8] - B.m[8] };
}
mat3 operator-(const mat3 & A)
{
	return mat3{ -A.m[0], -A.m[1],-A.m[2],-A.m[3], -A.m[4],-A.m[5], -A.m[6], 
				 -A.m[7], -A.m[8] };
}

mat3 mat3Identity() { return mat3{ 1,0,0,0,1,0,0,0,1 }; }
mat3 transpose(const mat3 &A)
{
	mat3 temp;
	for (unsigned i = 0; i < 3; ++i)
		for (unsigned j = 0; j < 3; ++j)
			temp[i][j] = A[j][i];
	
	return temp;
}
vec3 operator*(const mat3 & A, const vec3 & B)
{
	return vec3{ ((A.m[0] * B.x) + (A.m[3] * B.y) + (A.m[6] * B.z)),
				 ((A.m[1] * B.x) + (A.m[4] * B.y) + (A.m[7] * B.z)),
				 ((A.m[2] * B.x) + (A.m[5] * B.y) + (A.m[8] * B.z)) };
}
mat3 operator*(const mat3 & A, float s)
{
	return mat3{ A.m[0] * s, A.m[1] * s, A.m[2] * s,A.m[3] * s,
		         A.m[4] * s, A.m[5] * s, A.m[6] * s,A.m[7] * s, A.m[8] * s };

}
mat3 operator*(float s, const mat3 & A)
{
	return A*s;
}
mat3 operator*(const mat3 & A, const mat3 & B)
{
	return mat3{(A.m[0] * B.m[0]) + (A.m[3] * B.m[1]) + (A.m[6] * B.m[2]), 
				(A.m[1] * B.m[0]) + (A.m[4] * B.m[1]) + (A.m[7] * B.m[2]),
				(A.m[2] * B.m[0]) + (A.m[5] * B.m[1]) + (A.m[8] * B.m[2]),

				(A.m[0] * B.m[3]) + (A.m[3] * B.m[4]) + (A.m[6] * B.m[5]),
				(A.m[1] * B.m[3]) + (A.m[4] * B.m[4]) + (A.m[7] * B.m[5]),
				(A.m[2] * B.m[3]) + (A.m[5] * B.m[4]) + (A.m[8] * B.m[5]),

				(A.m[0] * B.m[6]) + (A.m[3] * B.m[7]) + (A.m[6] * B.m[8]), 							
				(A.m[1] * B.m[6]) + (A.m[4] * B.m[7]) + (A.m[7] * B.m[8]),
				(A.m[2] * B.m[6]) + (A.m[5] * B.m[7]) + (A.m[8] * B.m[8])
				};
}
float determinant(const mat3 & A)
{
	return  (A.m[0] * A.m[4]* A.m[8])+(A.m[3]* A.m[7]* A.m[2])+(A.m[6]* A.m[1]* A.m[5])-
			(A.m[6] * A.m[4]* A.m[2])-(A.m[3]* A.m[1]* A.m[8])-(A.m[0]* A.m[7]* A.m[5]);
}
mat3 inverse(const mat3 &A)
{
	return mat3{ 1 / determinant(A)};
}

vec3 mat3::operator[](unsigned idx) const
{
	return c[idx];
}
vec3 &mat3::operator[](unsigned idx)
{
	return c[idx];
}

mat3 scale(float w, float h)
{
	return mat3{ w,0,0,
				 0,h,0,
				 0,0,1 };
}
mat3 translate(float x, float y)
{

				//
	return mat3{ 1,0,0, 0,1,0, x,y,1 }; // column 3
}
mat3 rotation(float a)
{
	return mat3{ { cos(a),sin(a),0,
				  -sin(a), cos(a),0,
				   0,0,1 } };
}