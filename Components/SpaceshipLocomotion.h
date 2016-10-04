#pragma once
#include "Rigidbody.h"
class SpaceshipLocomotion
{
	float vertThrust;		
	float horzThrust;
	
	float speed;
	float maxSpeed;

public:
	SpaceshipLocomotion();

	void doThrust(float value);
	void doTurn(float value);
	void update(Rigidbody &rigidbody, float deltaTime);
};