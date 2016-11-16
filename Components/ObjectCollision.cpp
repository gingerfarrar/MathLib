#include "ObjectCollision.h"
void PlayerAsteroidCollision(PlayerShip & player, Asteroid & as)
{
	CollisionData result =
		DynamicCollision(player.transform, player.rigidbody, player.collider,
			as.transform, as.rigidbody, as.collider);

	if (result.penetrationDepth >= 0)
	{
		
		//player.transform.m_scale *= .9f;
	}
}


void AsteroidCollision(Asteroid & as1, Asteroid & as2)
{
	DynamicCollision(as1.transform, as1.rigidbody, as1.collider,
		as2.transform, as2.rigidbody, as2.collider);
}

void BulletAsteroidCollision(Bullet & b, Asteroid & a)
{
	if (!b.isAlive) return;

	
	CollisionData result =
		DynamicCollision(b.transform, b.rigidbody, b.collider,
			a.transform, a.rigidbody, a.collider);


	if (result.penetrationDepth >= 0)
	{
		
		b.timer = 0;
	}
}
