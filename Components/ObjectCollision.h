#pragma once
#include "Asteroid.h"
#include "PlayerShip.h"
#include "bullet.h"

void PlayerAsteroidCollision(PlayerShip &player, Asteroid &as);

void AsteroidCollision(Asteroid &as1, Asteroid &as2);

void BulletAsteroidCollision(Bullet &bullet, Asteroid &asteroid);