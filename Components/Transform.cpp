#include "Transform.h"
#include "sfwdraw.h"
using namespace sfw;

Transform::Transform(float x, float y, float w, float h, float a) 
	
{
	position.x = x;
	position.y = y;

	scale.x = w;
	scale.y = h;
	facing = a;
}
vec2 Transform::getUp() const
{
	return -perp(getDirection());
}

vec2 Transform::getDirection() const
{
	return fromAngle(facing);
}
void Transform::setDirection(const vec2 &dir)
{
	facing = angle(dir);
}
void Transform::debugDraw() const
{
	drawCircle(position.x, position.y, 12, 12, 0x888888FF);
	vec2 dirEnd = position + getDirection()*19;
	vec2 upEnd = position - perp(getDirection()) * 35;
	drawLine(position.x, position.y, dirEnd.x, dirEnd.y,MAGENTA);
}