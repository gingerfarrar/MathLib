#include <cassert>
#include <cstdio>
#include <cmath>
#include "Test.h"
#include "vec2.h"
#include "vec3.h"
#include "flops.h"
#include "mat2.h"
#include "mat3.h"
#include "shapes.h"
#include "collision.h"
int main()
{
	
	////vector tests

	//assert((vec2{ 0,0 } == vec2{ 0,0 }));
	//assert((vec2{ 1,1 } +vec2{ -1,0 } == vec2{ 0, 1 }));
	//assert((vec2{ 1,1 } -vec2{ 1,1 } == vec2{ 0, 0 }));
	//assert((vec2{ 1,1 } *vec2{ 1,1 } == vec2{ 1, 1 }));
	//assert((vec2{ 1,1 } / vec2{ 1,1 } == vec2{ 1, 1 }));

	//assert((vec2{ 1,1 } *1.f == vec2{ 1,1 }));
	//assert((1.f * vec2{ 1,1 } == vec2{ 1,1 }));
	//assert((vec2{ 1,1 } / 1.f == vec2{ 1,1 }));

	//assert((-vec2{ 1,1 } == vec2{ -1,-1 }));
	//assert((+vec2{ 1,1 } == vec2{ +1,+1 }));
	//assert(fequals(dot(vec2{ 5,4 }, vec2{ 1,0 }), 5));
	//assert(fequals(dot(vec2{ 5,4 }, vec2{ 0,1 }), 4));
	//assert(fequals(1, .9999999f));

	//assert((fequals(angleBetween(vec2{ 1,1 }, vec2{ 0,1 }), angle(vec2{ 1,1 }))));

	//assert((fromAngle(0) == vec2{ 1,0 }));

	//assert((cross(vec3{ 1,0,0 }, vec3{ 0,1,0 }) == vec3{ 0,0,1 }));
	//assert((cross(vec3{ 0,1,0 }, vec3{ 1,0,0 }) == vec3{ 0,0,-1 }));

	//assert(fequals(lerp(0, 1, .5f), .5f));

	//assert(fequals(quadBezier(15, 40, 21, 0), 15));
	//assert(fequals(quadBezier(15, 40, 21, 1), 21));


	// TODO : Hermite might have a bug.
	/*assert(fequals(hermiteSpline(15, 40, 21, 10, 0), 15));
	assert(fequals(hermiteSpline(15, 40, 21, 10, 1), 21));

	assert(fequals(cardinalSpline(15, 40, 21, .2f, 0), 15));
	assert(fequals(cardinalSpline(15, 40, 21, .1f, 1), 21));

	assert(fequals(catRomSpline(15, 40, 21, 0), 15));
	assert(fequals(catRomSpline(15, 40, 21, 1), 21));*/
	////////////////////////////////////////////////////////////////////
	///////////////////matrix tests////////////////////////////////////

	//mat2 m0 = mat2{ 0,0,0,0 };
	//mat2 mI = mat2Identity();
	//mat2 t0 = mat2{ 4,3,2,1 };

	//assert(m0 == m0);
	//assert(mI * 2 == 2 * mI);
	//assert((mI * 2 == mat2{ 2,0,0,2 }));
	//assert(mI + m0 == mI);
	//assert(mI - mI == m0);
	//assert(mI * -1 == -mI);

	//assert(mI * mI == mI);
	//assert((mat2{ 1,2,3,4 }) * mI == (mat2{ 1,2,3,4 }));

	//assert(transpose(mI) == mI);
	//assert(inverse(mI) == mI);
	//assert(t0 * inverse(t0) == mI);

	//vec3 j = { 2,5,1 };
	//vec3 r = translate(0, 3)*j;
	//assert((scale(5, 1)* j == vec3{ 10,5,1 }));
	//assert((rotation(deg2rad(90))*j == vec3{ -5,2,1 }));
	//assert((translate(0, 3)*j == vec3{ 2,8,1 }));
	//vec3 test = rotation(deg2rad(-90)) * translate(10, 0) * rotation(deg2rad(45)) * translate(4, 0) *rotation(deg2rad(45)) * translate(6, 4) * translate(-6, 0) * vec3 { 0, 0, 1 };
	//assert((test == vec3{ 2 * sqrtf(2), -6 - 2 * sqrtf(2), 1 }));
	//vec2 WP[] = { {12, -8}, {15, 8}, {5,8}, {-22, -5}, {4, -2}, {-6, 9}, {18,88},{-22,-90} };
	//mat3 RES = translate(12, -8) * rotation(80);


	/*Circle c = { 10, 0, 5 };
	assert((translate(4, 0) * c == Circle{ 4,0,5 }));

	assert((scale(2, 1) * c == Circle{ 4,0,10 }));
	assert((scale(2, 2) * c == Circle{ 4,0,10 }));
	assert((scale(1, 2) * c == Circle{ 4,0,10 }));

	assert((scale(-1, 1) * c == Circle{ 4,0,5 }));

	AABB testA = { 1,2,3,4 };
	assert((testA.min() == vec2{ -2,-2 }));
	assert((testA.max() == vec2{ 4,6 }));
*/
	//AABB testB = { 0,0,2,1 };
	//mat3 rot = rotation(deg2rad(90));
	//assert((rot*testB == AABB{ 0,0,1,2 }));
	
	
	assert(collisionDetection1D(0, 2, 1, 3).penetrationDepth == 1);
	assert(collisionDetection1D(0, 2, 1, 3).result == true);

	assert(sweptDetection1D(0, 1, 5, 3, 4, 0).entryTime == .4f);

	AABB A = { 0,0,2,4 };
	AABB B = { 2,2,2,4 };

	assert(boxCollision(A, B).penetrationDepth == 2);
	assert((boxCollision(A, B).collisionNormal == vec2{ 1,0 }));
	assert((boxCollision(B, A).collisionNormal == vec2{ -1,0 }));


	AABB As = { 0,0,1,1 };
	AABB Bs = { 0,10,1,1 };
	assert(fequals(boxCollisionSwept(As, vec2{ 0,1 }, Bs, vec2{ 0,-1 }).entryTime, 4));
	assert(fequals(boxCollisionSwept(As, vec2{ 0,-1 }, Bs, vec2{ 0,1 }).exitTime, -4));

	AABB Bp = { 0,0,4,4 };

	Plane P1 = { 0,0,0,1 };
	Plane P2 = { 0,-10,0,1 };
	Plane P3 = { 0, 10,0,1 };

	Plane P4 = { vec2{6,6}, normal(vec2{-1,1}) };
	Plane P5 = { vec2{ 6,6 }, normal(vec2{ -1,-1 }) };

	Plane P6 = { 10,0,-1,0 };
	assert(PlaneBoxCollision(P1, Bp).result());
	assert(!PlaneBoxCollision(P2, Bp).result());
	assert(PlaneBoxCollision(P3, Bp).result());
	assert(PlaneBoxCollision(P4, Bp).result());
	assert(!PlaneBoxCollision(P5, Bp).result());


	assert(fequals(planeBoxCollisionSwept(P6, Bp, vec2{ 1,0 }).entryTime, 6.f));


	vec2 verts[] = { {0,1},{1,1},{1,0},{0,0} };
	vec2 verts2[] = { {-1,-1},{-1,1},{0,0} };

	Hull myHull(verts, 4);
	Hull otherHull(verts2, 3);

	assert((myHull.normals[0] == vec2{ 0,1 }));
	assert((myHull.normals[1] == vec2{ 1,0 }));
	assert((myHull.normals[2] == vec2{ 0,-1 }));
	assert((myHull.normals[3] == vec2{ -1,0 }));

	Hull tHull = translate(1, 0) * myHull;

	assert((tHull.vertices[0] == vec2{ 1,1 }));
	assert((tHull.vertices[1] == vec2{ 2,1 }));
	assert((tHull.vertices[2] == vec2{ 2,0 }));
	assert((tHull.vertices[3] == vec2{ 1,0 }));

	assert(fequals(HullCollision(myHull, otherHull).penetrationDepth, 0));
	assert(fequals(HullCollision(otherHull, tHull).penetrationDepth, -1));

	return 0;
}