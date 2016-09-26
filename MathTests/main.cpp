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
	return 0;
}