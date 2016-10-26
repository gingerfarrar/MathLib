#include "collision.h"
#include <cmath>
CollisionData1D collisionDetection1D(float Amin, float Amax, 
									 float Bmin, float Bmax)
{
	CollisionData1D retval;
	float Dr = Amax - Bmin;
	float Dl = Bmax - Amin;
	retval.penetrationDepth = fmin(Dr,Dl);
	
	retval.collisionNormal = copysignf(1,Dl - Dr);
	
	retval.result = retval.penetrationDepth >= 0;
	retval.MTV    = retval.penetrationDepth * retval.collisionNormal;

	return retval;
}

SweptCollisionData1D sweptDetection1D(float Amin, float Amax, float Avel, 
									  float Bmin, float Bmax, float Bvel)
{
	SweptCollisionData1D retval;

	float Tl = (Amin - Bmax) / (Bvel - Avel);
	float Tr = (Bmin - Amax) / (Avel - Bvel);
	
	retval.entryTime = fminf(Tl, Tr);
	retval.exitTime = fmaxf(Tl, Tr);
	
	retval.collisionNormal = copysignf(1, Tl - Tr);

	return retval;
}


bool SweptCollisionData1D::result() const
{
	return entryTime >= 0 && entryTime <= 1;
}

CollisionData boxCollision(const AABB & A, const AABB & B)
{
	CollisionData retval;
	CollisionData1D XCD = collisionDetection1D(A.min().x,A.max().x,
												B.min().x, B.max().x);
	CollisionData1D YCD = collisionDetection1D(A.min().y, A.max().y,
												B.min().y, B.max().y);
	if (XCD.penetrationDepth < YCD.penetrationDepth)
	{
		retval.penetrationDepth = XCD.penetrationDepth;
		retval.collisionNormal = vec2{ 1,0 } *XCD.collisionNormal;
	}
	else
	{
		retval.penetrationDepth = YCD.penetrationDepth;
		retval.collisionNormal = vec2{ 0,1 } *YCD.collisionNormal;
	}
	return retval;
}

bool CollisionData::result() const
{
	return penetrationDepth >=0;
}

vec2 CollisionData::MTV() const
{
	return collisionNormal*penetrationDepth;
}
