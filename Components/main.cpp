#include "sfwdraw.h"
#include "vec2.h"
#include "Transform.h"
#include "flops.h"
#include "Rigidbody.h"
#include "SpaceshipLocomotion.h"
#include "SpaceshipController.h"
using namespace sfw;

void main()
{
	initContext();
	Transform playerTransform(400,300);
	Rigidbody playerRigidbody;
	SpaceshipLocomotion playerLoco;
	SpaceshipController playerCtrl;
	playerRigidbody.velocity = vec2{ 0,0 };
	float W = 800, H = 600;

	while (stepContext())
	{	
		float deltaTime = getDeltaTime();
	
		if (playerTransform.m_position.x < 0)		playerTransform.m_position.x = W;
		else if (playerTransform.m_position.x > W)	playerTransform.m_position.x = 0;
		if (playerTransform.m_position.y < 0)		playerTransform.m_position.y = H;
		else if (playerTransform.m_position.y > H)	playerTransform.m_position.y = 0;

		playerCtrl.update(playerLoco);
		playerLoco.update(playerTransform, playerRigidbody);
		playerRigidbody.integrate(playerTransform, deltaTime);
		playerTransform.debugDraw();
		playerRigidbody.debugDraw(playerTransform);
	  }
	sfw::termContext();
}