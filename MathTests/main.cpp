#include <cassert>
#include <cstdio>
#include "Test.h"
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
	return 0;
}