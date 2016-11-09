#pragma once
#include "vec2.h"
#include "shapes.h"
struct CollisionData1D
{
	bool result;
	float penetrationDepth;
	float collisionNormal; 
	float MTV; 
};

CollisionData1D collisionDetection1D( float Amin, float Amax,
									 float Bmin, float Bmax);

struct SweptCollisionData1D
{
	bool result() const;
	float entryTime, exitTime;
	float collisionNormal;
};

SweptCollisionData1D sweptDetection1D(float Amin, float Amax, float Avel,
									 float Bmin, float Bmax, float Bvel);

struct CollisionData
{
	float penetrationDepth;
	vec2 collisionNormal;

	bool result() const;
	vec2 MTV() const;
};

CollisionData boxCollision(const AABB &A,
						   const AABB &B);

struct CollisionDataSwept
{
	float entryTime, exitTime;
	float penetrationDepth;
	vec2 collisionNormal;

	bool result;
	
};

CollisionDataSwept boxCollisionSwept(const AABB &A, const vec2 &dA,
								const AABB &B, const vec2 &dB);

CollisionData PlaneBoxCollision(const Plane &P, const AABB &B);


CollisionDataSwept planeBoxCollisionSwept
						(const Plane &P, const AABB &B, const vec2 &Bvel);

CollisionData HullCollision(const Hull &A, const Hull &B);