#pragma once
#include "constdecl.h"
#include "PlayerShip.h"
#include "Camera.h"
#include "Asteroid.h"
#include "bullet.h"

class GameState
{
	int font;
	float timer;
public:
	PlayerShip player;
	Camera camera;
	Asteroid asteroid[2];
	Bullet bullet;

	void init(int a_font);
	void play();
	void update(float deltaTime);
	void draw();

	APP_STATE next();

};