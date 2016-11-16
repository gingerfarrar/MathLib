#include "bullet.h"



Bullet::Bullet()
{
	timer = 0;

	vec2 hullVrts[] = { { -.5f, 0 },{ 0,1 },{ .5f,0 } };
	collider = Collider(hullVrts, 3);
	transform.m_scale = vec2{ 20,20 };
	rigidbody.mass = 10;
}

void Bullet::update(float deltaTime, GameState & gs)
{
	timer -= deltaTime;
	isAlive = timer > 0;

	if (!isAlive) return;

	rigidbody.integrate(transform, deltaTime);
}

void Bullet::draw(const mat3 & camera)
{
	if (!isAlive) return;

	transform.debugDraw(camera);
	collider.DebugDraw(camera, transform);
	rigidbody.debugDraw(camera, transform);
}
