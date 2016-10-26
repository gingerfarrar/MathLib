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
