#pragma once

int doNothing(int x);
//problem a
float test_quad(float x);
//problem b
struct quad_results
{
	float left_root, right_root;
	int roots;
};

quad_results quad(float a, float b, float c);

//problem c
float lerp(float start, float end, float t);

//problem d
struct Point { float x, y; };
float distance(Point p1, Point p2);

//problem e
struct Point3D { float x, y, z; };
float inner(Point3D p, Point3D q);

//f
struct P { float a, b, c, d; };
struct X { float x, y, z; };
float PP(P p, X x);
//g
Point3D bezier(float t, const Point3D &p1, const Point3D &p2, const Point3D &p3, const Point3D &p4);