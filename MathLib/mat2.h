#pragma once
#include "vec2.h"

union mat2
{
	float m[4];
	float mm[2][2];
	vec2 c[2];

	vec2 operator[](unsigned idx) const;
	vec2 &operator[](unsigned idx);
};

mat2 mat2Identity();
bool operator==(const mat2 & A, const mat2 & B);
bool operator!=(const mat2 & A, const mat2 & B);
mat2 operator+(const mat2 & A, const mat2 & B);
mat2 operator-(const mat2 & A, const mat2 & B);
mat2 operator-(const mat2 & A);
mat2 transpose(const mat2 &A);

vec2 operator*(const mat2 & A, const vec2 & B);
mat2 operator*(const mat2 & A, float s);
mat2 operator*(float s, const mat2 & A);
mat2 operator*(const mat2 & A, const mat2 & B);

float determinant(const mat2 & A);
mat2 inverse(const mat2 &A);