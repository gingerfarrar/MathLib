#pragma once
#include "PlayerShip.h"
#include "Camera.h"
#include "Asteroid.h"
class GameState
{
public:
	PlayerShip player;
	Camera camera;
	Asteroid asteroid[2];

	void play();
	void update(float deltaTime);
	void draw();
};