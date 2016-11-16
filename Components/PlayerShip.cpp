#include "PlayerShip.h"
#include "GameState.h"

PlayerShip::PlayerShip()
{
	vec2 hullverts[] = { { -2.5,-3 },{ -2.5,3 },{ -2,-3 },{ -2,3 },{-1,4},{0,5}, {1,4}, { 2,3 },
							{2,-3},{2.5,3},{2.5,-3 } };
	collider = Collider(hullverts,11);
	
	transform.m_scale = vec2{ 10,10 };
}

void PlayerShip::update(float deltaTime, GameState & gs)
{
	controler.update(locomotion);
	locomotion.update(transform, rigidbody);
	rigidbody.integrate(transform, deltaTime);

	if (sfw::getKey('F') && !gs.bullet.isAlive)
	{

		gs.bullet.timer = 2.f;

		
		gs.bullet.transform.m_position = transform.m_position;
		gs.bullet.transform.m_facing = transform.m_facing;

		
		gs.bullet.rigidbody.velocity = vec2{ 0,0 };
	
		gs.bullet.rigidbody.addImpulse(transform.getUp() * 3000.f);
	}
}

void PlayerShip::draw(const mat3 &camera)
{
	transform.debugDraw(camera);
	collider.DebugDraw(camera, transform);
	rigidbody.debugDraw(camera, transform);
}
