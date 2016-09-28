#include "Transform.h"
#include "sfwdraw.h"
using namespace sfw;

Transform::Transform(float x, float y, float w, float h, float a) 
	: position{ x,y }, scale{ w,h }, facing{ a }
{
	position.x = x;
	position.y = y;
}
vec2 Transform::getDirection()
{
	return fromAngle(facing);
}
void Transform::setDirection(const vec2 &dir)
{
	facing = angle(dir);
}
void Transform::debugDraw()
{
	drawCircle(position.x, position.y, 50);
	vec2 dirEnd = position + getDirection()*25;
	vec2 upEnd = position - perp(getDirection()) * 35;
	drawLine(position.x, position.y, dirEnd.x, dirEnd.y,MAGENTA);
	//drawLine(position.x, position.y, upEnd.x, upEnd.y, BLACK);

	/*if (getKey('W'))
	{
		position += getDirection() * 5;
	}
	if (getKey('A'))
	{
		facing += .1;
	}
	if (getKey('D'))
	{
		facing -= .1;
	}*/

}