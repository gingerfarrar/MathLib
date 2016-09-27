#include <cassert>
#include <cstdio>
#include "Test.h"
#include "vec2.h"
int main()
{
	assert(doNothing(0) == 5);
	assert(doNothing(-1) == 4);
	assert(doNothing(1) == 8);

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
	assert((1.f /vec2{ 1,1 } == vec2{ 1,1 }));

	assert((-vec2{ 1,1 } == vec2{ -1,-1 }));
	assert((+vec2{ 1,1 } == vec2{ +1,+1 }));
	return 0;
}