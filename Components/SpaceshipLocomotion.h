#pragma once
#include "Rigidbody.h"
class SpaceshipLocomotion
{
	float vertThrust;		
	float horzThrust;
	float stopAction;
	
	float breakPower;
	float speed;
	float maxSpeed;
	float turnspeed;

public:
	SpaceshipLocomotion();

	void doThrust(float value);
	void doTurn(float value);

	void doStop(float value);

	void update(const Transform &trans, Rigidbody &rigidbody);
};