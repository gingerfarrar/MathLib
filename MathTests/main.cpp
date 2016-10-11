#include <cassert>
#include <cstdio>
#include "Test.h"
#include "vec2.h"
#include "vec3.h"
#include "flops.h"
#include "mat2.h"
int main()
{
	assert(test_quad(0.f) == -7);
	assert(test_quad(-1) == -8);
	assert(test_quad(1) == -4);
	//b
	quad_results res = quad(1, 0, 0);
	assert(quad(4, 1, -5).roots == 2);
	//c
	assert(lerp(5, 6, 2) == 7);
	//d
	assert(distance({ 0, 0 }, { 0, 0 }) == 0);
	//e
	assert(inner({ 0, 0, 0}, { 0, 0, 0}) == 0);
	//f
	assert(PP({ 0, 0, 1, 1 }, { 0, 2, 0 }) == 1);
	//g
	assert(bezier(0, { 0,0,0 }, { 1,0,0 }, { 2,0,0 }, {3, 0, 0}).x == 0);
	///////////////////////////////////////////////////////////////////////
	//vector tests

	assert((vec2{ 0,0 } == vec2{ 0,0 }));
	assert((vec2{ 1,1 } + vec2{ -1,0 } == vec2{ 0, 1 }));
	assert((vec2{ 1,1 } - vec2{ 1,1 } == vec2{ 0, 0 }));
	assert((vec2{ 1,1 } * vec2{ 1,1 } == vec2{ 1, 1 }));
	assert((vec2{ 1,1 } / vec2{ 1,1 } == vec2{ 1, 1 }));

	assert((vec2{ 1,1 } * 1.f == vec2{ 1,1 }));
	assert(( 1.f * vec2{ 1,1 } == vec2{ 1,1 }));
	assert((vec2{ 1,1 } / 1.f == vec2{ 1,1 }));

	assert((-vec2{ 1,1 } == vec2{ -1,-1 }));
	assert((+vec2{ 1,1 } == vec2{ +1,+1 }));
	assert(fequals(dot(vec2{ 5,4 }, vec2{ 1,0 }), 5));
	assert(fequals(dot(vec2{ 5,4 }, vec2{ 0,1 }), 4));
	assert(fequals(1, .9999999f));

	assert((fequals(angleBetween(vec2{ 1,1 }, vec2{ 0,1 }), angle(vec2{ 1,1 }))));

	assert((fromAngle(0) == vec2{ 1,0 }));

	assert((cross(vec3{ 1,0,0 }, vec3{ 0,1,0 }) == vec3{ 0,0,1 }));
	assert((cross(vec3{ 0,1,0 }, vec3{ 1,0,0 }) == vec3{ 0,0,-1 }));

	assert(fequals(lerp(.23, 124, 0), .23));
	assert(fequals(lerp(0, 1, .5f), .5f));

	assert(fequals(quadBezier(15, 40, 21, 0), 15));
	assert(fequals(quadBezier(15, 40, 21, 1), 21));

	assert(fequals(hermiteSpline(15, 40, 21, 10, 0), 15));
	assert(fequals(hermiteSpline(15, 40, 21, 10, 1), 21));

	assert(fequals(cardinalSpline(15, 40, 21, .2f, 0), 15));
	assert(fequals(cardinalSpline(15, 40, 21, .1f, 1), 21));

	assert(fequals(catRomSpline(15, 40, 21, 0), 15));
	assert(fequals(catRomSpline(15, 40, 21, 1), 21));
	////////////////////////////////////////////////////////////////////
	///////////////////matrix tests////////////////////////////////////

	mat2 m0 = mat2{ 0,0,0,0 };
	mat2 mI = mat2Identity();
	mat2 t0 = mat2{ 4,3,2,1 };

	assert(m0 == m0);
	assert(mI * 2 == 2 * mI);
	assert((mI * 2 == mat2{ 2,0,0,2 }));
	assert(mI + m0 == mI);
	assert(mI - mI == m0);
	assert(mI * -1 == -mI);

	assert(mI * mI == mI);
	assert((mat2{ 1,2,3,4 }) * mI == (mat2{ 1,2,3,4 }));

	assert(transpose(mI) == mI);
	assert(inverse(mI) == mI);
	assert(t0 * inverse(t0) == mI);

	return 0;
}