#include <cassert>
#include <cstdio>
#include <cmath>
#include "Test.h"
#include "vec2.h"
#include "vec3.h"
#include "flops.h"
#include "mat2.h"
#include "mat3.h"
int main()
{
	//assert(test_quad(0.f) == -7);
	//assert(test_quad(-1) == -8);
	//assert(test_quad(1) == -4);
	////b
	//quad_results res = quad(1, 0, 0);
	//assert(quad(4, 1, -5).roots == 2);
	////c
	//assert(lerp(5, 6, 2) == 7);
	////d
	//assert(distance({ 0, 0 }, { 0, 0 }) == 0);
	////e
	//assert(inner({ 0, 0, 0}, { 0, 0, 0}) == 0);
	////f
	//assert(PP({ 0, 0, 1, 1 }, { 0, 2, 0 }) == 1);
	////g
	//assert(bezier(0, { 0,0,0 }, { 1,0,0 }, { 2,0,0 }, {3, 0, 0}).x == 0);
	/////////////////////////////////////////////////////////////////////////
	////vector tests

	assert((vec2{ 0,0 } == vec2{ 0,0 }));
	assert((vec2{ 1,1 } +vec2{ -1,0 } == vec2{ 0, 1 }));
	assert((vec2{ 1,1 } -vec2{ 1,1 } == vec2{ 0, 0 }));
	assert((vec2{ 1,1 } *vec2{ 1,1 } == vec2{ 1, 1 }));
	assert((vec2{ 1,1 } / vec2{ 1,1 } == vec2{ 1, 1 }));

	assert((vec2{ 1,1 } *1.f == vec2{ 1,1 }));
	assert((1.f * vec2{ 1,1 } == vec2{ 1,1 }));
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

	assert(fequals(lerp(0, 1, .5f), .5f));

	assert(fequals(quadBezier(15, 40, 21, 0), 15));
	assert(fequals(quadBezier(15, 40, 21, 1), 21));


	// TODO : Hermite might have a bug.
	/*assert(fequals(hermiteSpline(15, 40, 21, 10, 0), 15));
	assert(fequals(hermiteSpline(15, 40, 21, 10, 1), 21));

	assert(fequals(cardinalSpline(15, 40, 21, .2f, 0), 15));
	assert(fequals(cardinalSpline(15, 40, 21, .1f, 1), 21));

	assert(fequals(catRomSpline(15, 40, 21, 0), 15));
	assert(fequals(catRomSpline(15, 40, 21, 1), 21));*/
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

	vec3 j = { 2,5,1 };
	vec3 r = translate(0, 3)*j;
	assert((scale(5, 1)* j == vec3{ 10,5,1 }));
	assert((rotation(deg2rad(90))*j == vec3{ -5,2,1 }));
	assert((translate(0, 3)*j == vec3{ 2,8,1 }));
	vec3 test = rotation(deg2rad(-90)) * translate(10, 0) * rotation(deg2rad(45)) * translate(4, 0) *rotation(deg2rad(45)) * translate(6, 4) * translate(-6, 0) * vec3 { 0, 0, 1 };
	assert((test == vec3{ 2 * sqrtf(2), -6 - 2 * sqrtf(2), 1 }));
	vec2 WP[] = { {12, -8}, {15, 8}, {5,8}, {-22, -5}, {4, -2}, {-6, 9}, {18,88},{-22,-90} };
	mat3 RES = translate(12, -8) * rotation(80);
	for (int i = 0; i < 7; i++)
	{
		vec2 bet = WP[i + 1] - WP[i];
		//mat3 R = rotation(angle(bet) - angle(RES[0].xy));
		mat3 T = translate(magnitude(bet), 0);
		/*??? RES = T * R * RES ???*/
		//assert((RES[2].xy == WP[i + 1]));
	}

	return 0;
}