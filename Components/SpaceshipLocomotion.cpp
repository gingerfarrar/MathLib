#include "SpaceshipLocomotion.h"
#include "sfwdraw.h"
#include "Rigidbody.h"
using namespace sfw;
SpaceshipLocomotion::SpaceshipLocomotion()
{
	vertThrust = 0.0f;
	horzThrust = 0.0f;

	speed = 500.0f;
	maxSpeed = 1000.0f;
}
void SpaceshipLocomotion::doThrust(float value)
{
	vertThrust = value;
}
void SpaceshipLocomotion::doTurn(float value)
{
	horzThrust = value;
}
void SpaceshipLocomotion::update(Rigidbody &rigidbody, float deltaTime)
{
	
	rigidbody.acceleration.x = horzThrust*speed;
	rigidbody.acceleration.y = vertThrust *speed;

	if (magnitude(rigidbody.velocity) > maxSpeed)
	{
		vec2 dir = normal(rigidbody.velocity);
		rigidbody.velocity = dir * maxSpeed;
	}

	vertThrust = 0.0f;
	horzThrust = 0.0f;
}