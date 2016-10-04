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
	
		if (playerTransform.position.x < 0)		playerTransform.position.x = W;
		else if (playerTransform.position.x > W)	playerTransform.position.x = 0;
		if (playerTransform.position.y < 0)		playerTransform.position.y = H;
		else if (playerTransform.position.y > H)	playerTransform.position.y = 0;

		playerCtrl.update(playerLoco);
		playerLoco.update(playerRigidbody, deltaTime);
		playerRigidbody.integrate(playerTransform, deltaTime);
		playerTransform.debugDraw();
		
	  }
	sfw::termContext();
}