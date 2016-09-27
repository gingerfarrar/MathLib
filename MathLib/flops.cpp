#include "flops.h"
#include <cmath>
bool fequals(float lhs, float rhs)
{
	if(lhs < 0.0000001f && rhs < 0.0000001f)return true;
	
}

float deg2rad(float deg)
{
	return deg*3.14 / 180;
}
float rad2deg(float rad)
{
	return rad * 180 / 3.14;
}