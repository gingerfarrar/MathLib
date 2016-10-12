#include "flops.h"
#include <cmath>
bool fequals(float lhs, float rhs)
{
	// if the values are SOOOO close, or their difference is SOOO tiny
	// then treat them as basically the same.
	if(abs(lhs-rhs) < 0.0001f)
		return true;
	else 
		return false;
}

float deg2rad(float deg)
{
	return deg*3.14159265359 / 180;
}
float rad2deg(float rad)
{
	return rad * 180 / 3.14159265359;
}

float linearHalf(float x)
{
	return 0.5f*x;
}
float growFast(float x)
{
	return x*x;
}
float growSlow(float x)
{
	return log(x + 1);
}
float HardAngle(float x)
{
	return x < 0.5 ? 2 * x : -2 * (x - 1);
}
float bounce(float x)
{
	return abs(cos(x * 10)*(1 - x));
}
//real shit
float lerp(float start, float end, float alpha)
{
	return (1 - alpha)*start + alpha *end;
}
float quadBezier(float start, float mid, float end, float alpha)
{
	float mid1 = lerp(start, mid, alpha);
	float mid2 = lerp(mid, end, alpha);
	return lerp(mid1, mid2, alpha);
}
float hermiteSpline(float start, float s_tan, float end, float e_tan, float alpha)
{
	float tsq = alpha*alpha;
	float tcub = tsq * alpha;
	float h00 = 2 * tcub + 3 * tsq + 1;
	float h01 = -2 * tcub + 3 * tsq;
	float h10 = tcub - 2 * tsq + alpha;
	float h11 = tcub - tsq;
	float point = h00*start + h10*s_tan + h01*end + h11 *e_tan;
	return point;
}
float cardinalSpline(float start, float mid, float end, float tight, float alpha)
{
	float tan0 = (mid - start)*tight;
	float tan1 = (end - mid) * tight;
	float tsq = alpha*alpha;
	float tcub = tsq * alpha;
	float h00 = 2 * tcub + 3 * tsq + 1;
	float h01 = -2 * tcub + 3 * tsq;
	float h10 = tcub - 2 * tsq + alpha;
	float h11 = tcub - tsq;
	float point = h00*start + h10*tan0 + h01 *mid + h11 * tan1;
	return point;
}
float  catRomSpline(float start, float mid,float end, float alpha)
{
	float tan0 = (mid - start)*.5;
	float tan1 = (end - mid) * .5;
	float tsq = alpha*alpha;
	float tcub = tsq * alpha;
	float h00 = 2 * tcub + 3 * tsq + 1;
	float h01 = -2 * tcub + 3 * tsq;
	float h10 = tcub - 2 * tsq + alpha;
	float h11 = tcub - tsq;
	float point = h00*start + h10*tan0 + h01 *mid + h11 * tan1;
	return point;
}