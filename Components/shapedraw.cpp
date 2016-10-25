#include "shapedraw.h"
#include "sfwdraw.h"
using namespace sfw;
void drawCircle(const Circle & c, unsigned color)
{
	drawCircle(c.pos.x, c.pos.y, c.rad, 12, color);
}

void drawAABB(const AABB & B, unsigned color)
{
	
}
