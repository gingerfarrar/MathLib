#include "Rigidbody.h"
Rigidbody::Rigidbody()
{
	velocity = vec2{ 0,0 };
	angularVelocity = 0.0f;
	acceleration = vec2{ 0,0 };
	
}
void Rigidbody::integrate(Transform &trans, float deltaTime)
{
	velocity = velocity + acceleration * deltaTime;
	angularVelocity = angularVelocity + angularAcceleration * deltaTime;
	trans.position = trans.position + velocity * deltaTime;
	trans.facing = trans.facing + angularVelocity *deltaTime;
}