#include "SpaceshipLocomotion.h"
#include "sfwdraw.h"
#include "Rigidbody.h"
using namespace sfw;
SpaceshipLocomotion::SpaceshipLocomotion()
{
	vertThrust = 0.0f;
	horzThrust = 0.0f;
	stopAction = 0.0f;
	breakPower = 10.0f;

	turnspeed = 5.0f;
	speed = 500.0f;
	maxSpeed = 1000.0f;
}
void SpaceshipLocomotion::doThrust(float value)
{
	vertThrust += value;
}
void SpaceshipLocomotion::doTurn(float value)
{
	horzThrust += value;
}
void SpaceshipLocomotion::doStop(float value)
{
	stopAction += value;
}

void SpaceshipLocomotion::update(const Transform &trans, Rigidbody &rigidbody)
{
	rigidbody.addForce(trans.getUp() * speed * vertThrust);
	rigidbody.addTorque(turnspeed*horzThrust);

	//float currentSpeed = magnitude(rigidbody.velocity);

	rigidbody.addForce(-rigidbody.velocity * breakPower * stopAction);
	rigidbody.addTorque(-rigidbody.angularVelocity * breakPower * stopAction);

	horzThrust = vertThrust = stopAction = 0;
}