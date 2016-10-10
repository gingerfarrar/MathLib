#pragma once
#include "vec2.h"

union mat2
{
	float m[4];
	float mm[2][2];
	vec2 c[2];
};

mat2 operator+()