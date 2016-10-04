#pragma once
#include "vec2.h"
#include "Transform.h"
class Rigidbody
{
public:
	Rigidbody();
	vec2 velocity;
	float angularVelocity; // change in rotation
	vec2 acceleration;
	float angularAcceleration;

	void integrate(Transform &trans, float deltaTime);
};