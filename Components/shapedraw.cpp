#include "shapedraw.h"
#include "shapes.h"
#include "sfwdraw.h"
using namespace sfw;
void drawCircle(const Circle & c, unsigned color)
{
	drawCircle(c.pos.x, c.pos.y, c.rad, 12, color);
}

void drawAABB(const AABB & B, unsigned color)
{
	drawLine(B.min().x, B.min().y,B.max().x,B.min().y,color);
	drawLine(B.min().x, B.min().y,B.min().x, B.max().y,color);
	drawLine(B.max().x, B.max().y,B.max().x, B.min().y,color);
	drawLine(B.max().x, B.max().y,B.min().x, B.max().y,color);
}

void drawPlane(const Plane & P, unsigned color)
{
	drawCircle(P.pos.x, P.pos.y, 12, 12, color);
	drawLine(P.pos.x, P.pos.y, P.pos.x + P.dir.x * 10, P.pos.y + P.dir.y * 10,color);
	
	vec2 left = perp(P.dir);
	vec2 right = -perp(P.dir);
	drawLine(P.pos.x, P.pos.y, P.pos.x +left.x * 80, P.pos.y + left.y * 80, color);

	drawLine(P.pos.x, P.pos.y, P.pos.x + right.x * 80, P.pos.y + right.y * 80, color);

}


