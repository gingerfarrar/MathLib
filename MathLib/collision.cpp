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


CollisionDataSwept boxCollisionSwept(const AABB & A, const vec2 & dA, const AABB & B, const vec2 & dB)
{
	CollisionDataSwept retval;
	CollisionData1D Xd = collisionDetection1D(A.min().x, A.max().x,
											  B.min().x, B.max().x);
	CollisionData1D Yd = collisionDetection1D(A.min().y, A.max().y,
											  B.min().y, B.max().y);
	bool xswept = (dA.x - dB.x != 0);
	bool yswept = (dA.y - dB.y != 0);

	
	SweptCollisionData1D Xs = sweptDetection1D(A.min().x, A.max().x, dA.x,
											   B.min().x, B.max().x,dB.x);
	
	SweptCollisionData1D Ys = sweptDetection1D(A.min().y, A.max().y, dA.y,
											   B.min().y, B.max().y, dB.y);
	
	if (Ys.entryTime < Xs.entryTime && xswept)
	{
		retval.collisionNormal = vec2{ 1,0 } *Xs.collisionNormal;
		retval.entryTime = Xs.entryTime;
	}
	else if(yswept)
	{
		retval.collisionNormal = vec2{ 0,1 } *Ys.collisionNormal;
		retval.entryTime = Ys.entryTime;
	}
	if (Ys.exitTime < Xs.exitTime || isinf(Xs.exitTime))
	{
		retval.exitTime = Ys.exitTime;
	}
	else
		retval.exitTime = Xs.exitTime;
	return retval;
}

CollisionData PlaneBoxCollision(const Plane & P, const AABB & B)
{
	CollisionData retval;
	
	vec2 Bc = { B.min().x, B.min().y };
	vec2 Ba = { B.min().x, B.max().y };
	vec2 Bd = { B.max().x, B.min().y };
	vec2 Bb = { B.max().x, B.max().y };

	float fBa = dot(P.dir, Ba);
	float fBb = dot(P.dir, Bb);
	float fBc = dot(P.dir, Bc);
	float fBd = dot(P.dir, Bd);

	float PMAX = dot(P.dir, P.pos);

	float FTR = dot(P.dir, Ba);
	float FTL = dot(P.dir, Bb);
	float FBR = dot(P.dir, Bc);
	float FBL = dot(P.dir, Bd);

	float Amin = fminf(fminf(FTR, FTL), fminf(FBR, FBL));
	float Amax = fmaxf(fmaxf(FTR, FTL), fminf(FBR, FBL));

	retval.penetrationDepth = PMAX - Amin;
	retval.collisionNormal = P.dir;

	return retval;
}

CollisionDataSwept planeBoxCollisionSwept(const Plane & P, const AABB & B, const vec2 & vel)
{
	CollisionDataSwept retval;
	vec2 TR = { B.max().x, B.max().y };
	vec2 TL = { B.min().x, B.max().y };
	vec2 BR = { B.max().x, B.min().y };
	vec2 BL = { B.min().x, B.min().y };

	float Bvel = dot(P.dir, vel);
	float PMAX = dot(P.dir, P.pos);

	float FTR = dot(P.dir, TR);
	float FTL = dot(P.dir, TL);
	float FBR = dot(P.dir, BR);
	float FBL = dot(P.dir, BL);

	float Amin = fminf(fminf(FTR, FTL), fminf(FBR, FBL));
	float Amax = fmaxf(fmaxf(FTR, FTL), fminf(FBR, FBL));

	retval.entryTime = (Amin - PMAX) / (0 - Bvel);
	retval.exitTime = (Amax - PMAX) / (0 - Bvel);;

	return retval;
}
