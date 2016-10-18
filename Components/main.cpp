#include "sfwdraw.h"
#include "vec2.h"
#include "Transform.h"
#include "flops.h"
#include "Rigidbody.h"
#include "SpaceshipLocomotion.h"
#include "SpaceshipController.h"
#include "PlanetaryMotor.h"
using namespace sfw;

void main()
{
	initContext();
	Transform playerTransform(400,300);
	Transform ST1(50, 0);
	Transform ST2(50, 0);
	Transform ST3(50, 0);

	Transform sunTransform;
	Rigidbody sunRbody;
	sunTransform.m_position = vec2{ 800 / 2, 600 / 2 };
	ST1.m_parent = &playerTransform;
	ST2.m_parent = &ST1;
	ST3.m_parent = &ST2;

	Rigidbody playerRigidbody;
	SpaceshipLocomotion playerLoco;
	SpaceshipController playerCtrl;
	PlanetaryMotor sunMotor;
	sunMotor.m_rotationSpeed;

	playerRigidbody.velocity = vec2{ 0,0 };
	float W = 800, H = 600;

	while (stepContext())
	{	
		float deltaTime = getDeltaTime();
	
		if (playerTransform.m_position.x < 0)		playerTransform.m_position.x = W;
		else if (playerTransform.m_position.x > W)	playerTransform.m_position.x = 0;
		if (playerTransform.m_position.y < 0)		playerTransform.m_position.y = H;
		else if (playerTransform.m_position.y > H)	playerTransform.m_position.y = 0;

		sunMotor.update(sunRbody);
		sunRbody.integrate(sunTransform, deltaTime);
		sunTransform.debugDraw();

		/*playerCtrl.update(playerLoco);
		playerLoco.update(playerTransform, playerRigidbody);
		playerRigidbody.integrate(playerTransform, deltaTime);
		

		ST1.debugDraw();
		ST2.debugDraw();
		ST3.debugDraw();
		
		playerRigidbody.debugDraw(playerTransform);*/
	  }
	sfw::termContext();
}