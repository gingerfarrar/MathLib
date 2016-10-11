#pragma once
#include "vec3.h"
union mat3
{
	float m[9];
	float mm[3][3];
	vec3 c[3];

	vec3 operator[](unsigned idx) const;
	vec3 &operator[](unsigned idx);
};

mat3 mat3Identity();
bool operator==(const mat3 & A, const mat3 & B);
bool operator!=(const mat3 & A, const mat3 & B);
mat3 operator+(const mat3 & A, const mat3 & B);
mat3 operator-(const mat3 & A, const mat3 & B);
mat3 operator-(const mat3 & A);
mat3 transpose(const mat3 &A);

vec3 operator*(const mat3 & A, const vec3 & B);
mat3 operator*(const mat3 & A, float s);
mat3 operator*(float s, const mat3 & A);
mat3 operator*(const mat3 & A, const mat3 & B);

float determinant(const mat3 & A);
mat3 inverse(const mat3 &A);