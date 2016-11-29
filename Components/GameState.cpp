#include "GameState.h"
#include "ObjectCollision.h"
#include "sfwdraw.h"
#include <iostream>
using namespace sfw;
void GameState::init(int a_font)
{
	font = a_font;
}
void GameState::play()
{
	player.transform.m_position = vec2{ 400,300 };
	player.transform.m_facing = 0;
	
	asteroid[0].transform.m_position = vec2{ 100,100 };
	asteroid[0].rigidbody.addImpulse(vec2{ 100,100 });
	asteroid[0].rigidbody.addTorque(24);

	asteroid[1].transform.m_position = vec2{ 400,400 };
	asteroid[1].rigidbody.addImpulse(vec2{ -250,-250 });
	asteroid[1].rigidbody.addTorque(-24);
	timer = 10.f;
	
	bullet.timer = 0;
}

void GameState::update(float deltaTime)
{
	player.update(deltaTime, *this);
	camera.update(deltaTime, *this);
	bullet.update(deltaTime, *this);
	timer -= getDeltaTime();

	for (int i = 0; i < 2; ++i)
		asteroid[i].update(deltaTime, *this);

 	for (int i = 0; i < 2; ++i)
		PlayerAsteroidCollision(player, asteroid[i]);

	for (int i = 0; i < 2 - 1; ++i)
		for (int j = i + 1; j < 2; ++j)
			AsteroidCollision(asteroid[i], asteroid[j]);

	for (int i = 0; i < 2; ++i)
		BulletAsteroidCollision(bullet, asteroid[i]);
}

void GameState::draw()
{
	char buffer[64];
	sprintf_s(buffer, "Time: %f", timer);
	drawString(font, "Time", 100, 500, 20, 20);
	drawLine(100, 550, 100 + 500 * (timer / 10.f), 550);

	mat3 cam = camera.getCameraMatrix();
	player.draw(cam);
	bullet.draw(cam);
	for (int i = 0; i < 2; ++i)
	{
		asteroid[i].draw(cam);
	}
}

APP_STATE GameState::next()
{
	if (!asteroid[0].isAlive && !asteroid[1].isAlive )
	{
		return ENTER_WIN;
	}
	if (timer < 0 )
	{
		return ENTER_LOSE;
	}
	return GAMESTATE;
}
