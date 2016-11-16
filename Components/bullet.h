#pragma once
#include "Transform.h"
#include "Collider.h"
#include "Rigidbody.h"

class Bullet
{
public:
	Transform			transform;
	Collider			collider;
	Rigidbody			rigidbody;

	float timer;
	bool isAlive;

	Bullet();

	void update(float deltaTime,class GameState &gs);

	void draw(const mat3 &camera);
};