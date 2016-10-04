#include <cmath>
#include "Test.h"
int doNothing(int x)
{
	return x*x + 2 * x + 5;
}
//a
float test_quad(float x)
{
	return x*x + 2*x - 7;
}
//b
quad_results quad(float a, float b, float c)
{
	quad_results retval;
	retval.left_root = -b + sqrt(b*b - 4 * a*c) / 2 * a;
	retval.right_root = -b - sqrt(b*b - 4 * a*c) / 2 * a;
	float d = b*b - 4 * a*c;
	if (d < 0)
	{
		retval.roots = 0;
	}
	if (d == 0)
	{
		retval.roots = 1;
	}
	else
		retval.roots = 2;
	return retval;
}
//c
//float lerp(float start, float end, float t)
//{
//	return start + t*(end - start);
//}
//d
float distance(Point p1, Point p2)
{
	return (sqrt((p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y)));
}
//e
float inner(Point3D p, Point3D q)
{
	return p.x*q.x + p.y*q.y + p.z*q.z;
}
//f
float PP(P p, X x)
{
	return (p.a*x.x + p.b*x.y + p.c*x.z + p.d) / (sqrt(p.a*p.a + p.b*p.b + p.c*p.c));
}
//g
Point3D bezier(float t, const Point3D &p1, const Point3D &p2, const Point3D &p3, const Point3D &p4)
{
	float ot = 1 - t;
	Point3D r;
	r.x = ot*ot*ot*p1.x + 3 * ot*ot*t*p2.x + 3 * ot*t*t*p3.x + t*t*t*p4.x;
	r.y = ot*ot*ot*p1.y + 3 * ot*ot*t*p2.y + 3 * ot*t*t*p3.y + t*t*t*p4.y;
	r.z = ot*ot*ot*p1.z + 3 * ot*ot*t*p2.z + 3 * ot*t*t*p3.z + t*t*t*p4.z;
	return r;
}