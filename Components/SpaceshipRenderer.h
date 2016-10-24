#pragma once
#include "Transform.h"

class SpaceshipRenderer
{
public:
	unsigned color;

	SpaceshipRenderer();

	void draw(const mat3 &T, const Transform &ship);
};