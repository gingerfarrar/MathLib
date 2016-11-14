#include "Collider.h"
#include "shapedraw.h"
#include <cmath>
Collider::Collider(const vec2 * verts, int size) 
				: hull(verts,size)
{
	float minx = INFINITY;
	float miny = INFINITY;
	float maxx = -INFINITY;
	float maxy = -INFINITY;


	for (int i = 0; i < size; i++)
	{
		if (verts[i].x < minx)
		{
			minx = verts[i].x;
		}
		if (verts[i].y < miny)
		{
			miny = verts[i].y;
		}
		if (verts[i].x > maxx)
		{
			maxx = verts[i].x;
		}
		if (verts[i].y > maxy)
		{
			maxy = verts[i].y;
		}
	}

	vec2 min = { minx, miny };
	vec2 max = { maxx, maxy };
	box.pos = (min + max) / 2;
	box.he = (max - min) / 2;
}

void Collider::DebugDraw(const mat3 & T, const Transform & trans)
{
	mat3 glob = T * trans.getGlobalTransform();
	drawAABB(glob * box, 0x888888ff);
	drawHull(glob *hull, 0x888888ff);

}

CollisionData ColliderCollision(const Transform & AT, const Collider & AC, 
								const Transform & BT, const Collider & BC)
{
	CollisionData retval;
	retval = boxCollision(AT.getGlobalTransform() * AC.box,
						  BT.getGlobalTransform() * BC.box);
	if (retval.penetrationDepth >= 0)
	{
		retval = HullCollision(AT.getGlobalTransform() * AC.hull,
							   BT.getGlobalTransform() * BC.hull);
	}
	
	return retval;
}
