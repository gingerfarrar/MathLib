#include "shapes.h"
#include "flops.h"

Circle operator*(const mat3 & T, const Circle & C)
{
	Circle retval;
	
	float mX = magnitude(T * vec3{ C.rad, 0, 0 });
	float mY = magnitude(T * vec3{0,C.rad, 0 });

	retval.pos = (T *vec3{ C.pos.x, C.pos.y, 1 }).xy;

	retval.rad = mX > mY ? mX : mY;
	return retval;
}

bool operator==(const Circle & A, const Circle & B)
{
	return A.pos == B.pos && A.rad == B.rad;
}
vec2 AABB::min() const
{
	return pos - he;
}
vec2 AABB::max() const
{
	return pos + he;
}
AABB operator*(const mat3 &T, const AABB &A)
{
	AABB retval = A;

	 vec3 tP[4];
	 tP[0] = (T * vec3{ A.min().x,A.min().y,1 });
	 tP[1] = (T * vec3{ A.min().x,A.max().y,1 });
	 tP[2] = (T * vec3{ A.max().x,A.min().y,1 });
	 tP[3] = (T * vec3{ A.max().x,A.max().y,1 });

	 vec2 minv = tP[0].xy, 
		 maxv = tP[0].xy;
	
	 for (int i = 0; i < 4; ++i)
	 {
		 if (tP[i].x < minv.x)
		 {
			 minv.x = tP[i].x;
		 }
		 if (tP[i].x > maxv.x)
		 {
			 maxv.x = tP[i].x;
		 }
		 if (tP[i].y < minv.y)
		 {
			 minv.y = tP[i].y;
		 }
		 if (tP[i].y > maxv.y)
		 {
			 maxv.y = tP[i].y;
		 }
	 }

	 retval.pos = (T*vec3{ A.pos.x, A.pos.y,1 }).xy;
	 float halfx = (maxv.x - minv.x)/2;
	 float halfy = (maxv.y - minv.y)/2;

	 retval.he = { halfx, halfy };

	return retval;
}
Plane operator*(const mat3 &T, const Plane &P)
{
	Plane retval;
	retval.pos = (T*vec3{ P.pos.x, P.pos.y,1 }).xy;
	retval.dir = normal(T*vec3{ P.dir.x,P.dir.y,0 }).xy;
	return retval;
}
bool operator==(const Plane &A, const Plane &B)
{
	return A.pos == B.pos && A.dir == B.dir;
}

Ray operator*(const mat3 &T, const Ray &R)
{
	return Ray();
}
Hull operator*(const mat3 &T, const Hull &H)
{
	return Hull();
}