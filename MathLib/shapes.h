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

struct Ray  
{

};
Ray operator*(const mat3 &T, const Ray &R);

struct Hull 
{	
	vec2 vertices[16];
	vec2 normals[16];
	unsigned int size;
	Hull();
	Hull(const vec2 *a_vertices, unsigned vsize);
};
Hull operator*(const mat3 &T, const Hull &H);
bool operator==(const Hull &A, const Hull &B);

Circle operator*(const mat3 &T, const Circle &C);
bool operator==(const Circle &A, const Circle &B);

AABB operator*(const mat3 &T, const AABB &A);
Plane operator*(const mat3 &T, const Plane &P);