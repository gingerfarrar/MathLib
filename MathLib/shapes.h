#pragma once
#include "mat3.h"

struct Circle 
{
	vec2 pos;
	float rad;
};
// (x-h)^2 + (y-k)^2 = r^2
struct AABB 
{
	vec2 pos, he;
	vec2 min() const;
	vec2 max() const;
};
struct Plane 
{
	vec2 pos, dir;
};

Plane operator*(const mat3 &T, const Plane &P);
bool operator==(const Plane &A, const Plane &B);

struct Ray   {	};
struct Hull  {	};
Circle operator*(const mat3 &T, const Circle &C);
bool operator==(const Circle &A, const Circle &B);

AABB operator*(const mat3 &T, const AABB &A);
Plane operator*(const mat3 &T, const Plane &P);
Ray operator*(const mat3 &T, const Ray &R);
Hull operator*(const mat3 &T, const Hull &H);
