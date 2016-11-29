#include "Asteroid.h"

Asteroid::Asteroid()
{
	timer = 100;

	vec2 hullVrts[] = { { -1, 0 },{ 0,1 },{ 1,0 } };
	collider = Collider(hullVrts, 3);

	transform.m_scale = vec2{ 7,7 };
	rigidbody.drag = 0.0f;
	rigidbody.angulardrag = 0.0f;
	rigidbody.mass = 10;

}

void Asteroid::update(float deltaTime, GameState & gs)
{
	timer -= deltaTime;
	isAlive = timer > 0;

	if (!isAlive) return;
	rigidbody.integrate(transform, deltaTime);
}

void Asteroid::draw(const mat3 & camera)
{
    if (!isAlive) return;

	transform.debugDraw(camera);
	collider.DebugDraw(camera, transform);
	rigidbody.debugDraw(camera, transform);
}