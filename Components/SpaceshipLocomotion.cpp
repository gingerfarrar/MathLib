#include "SpaceshipLocomotion.h"
#include "sfwdraw.h"
#include "Rigidbody.h"
using namespace sfw;
SpaceshipLocomotion::SpaceshipLocomotion()
{
	vertThrust = 0.0f;
	horzThrust = 0.0f;
	breakPower = 10.0f;

	turnspeed = 5.0f;
	speed = 50.0f;
	maxSpeed = 100.0f;
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
void SpaceshipLocomotion::ST1update(const Transform &trans, Rigidbody &rigidbody)
{

}
void SpaceshipLocomotion::update(const Transform &trans, Rigidbody &rigidbody)
{
	rigidbody.addForce(trans.getDirection() * speed * vertThrust);
	rigidbody.addTorque(turnspeed*horzThrust);

	//float currentSpeed = magnitude(rigidbody.velocity);

	rigidbody.addForce(-rigidbody.velocity * breakPower * stopAction);

	vertThrust = horzThrust = stopAction = 0;
}