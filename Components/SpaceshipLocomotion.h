#pragma once
#include "Rigidbody.h"
class SpaceshipLocomotion
{
	SpaceshipLocomotion();
	float thrust;		
	float maxThrust;
	float thrustSpeed;

	float turn;
	float maxTurn;
	float turnSpeed;

	float speed;

public:
	void doThrust(float deltaTime);
	void doTurn(float deltaTime);
	void integrate(Rigidbody &rigidbody);
};