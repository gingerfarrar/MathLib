#include "sfwdraw.h"
#include "vec2.h"
#include "Transform.h"
#include "flops.h"
#include "Rigidbody.h"
#include "SpaceshipLocomotion.h"
#include "SpaceshipController.h"
#include "PlanetaryMotor.h"
#include "PlanetaryRenderer.h"
#include "SpaceshipRenderer.h"
#include "shapedraw.h"
using namespace sfw;

void main()
{

	float W = 800, H = 600;

	sfw::initContext(W, H);

	Transform playerTransform(400,300);
	playerTransform.m_scale = vec2{ 20,30 };
	Rigidbody playerRigidbody;
    SpaceshipController playerCtrl;
	SpaceshipLocomotion playerLoco;
	SpaceshipRenderer playerRender;
	Plane plane;
	//sun
	Transform sunTransform;	
	sunTransform.m_position = vec2{ 800 / 2, 600 / 2 };	
	Rigidbody sunRbody;
	PlanetaryMotor sunMotor;
	sunMotor.m_rotationSpeed = 5;
	PlanetaryRenderer sunRenderer(YELLOW, 100);

	//planet
	Transform plan1;
	plan1.m_position = vec2{ 150, 0 };
	plan1.m_parent = &sunTransform;
	Rigidbody plan1RB;
	PlanetaryMotor plan1motor;
	plan1motor.m_rotationSpeed = 5;
	PlanetaryRenderer plan1renderer(GREEN, 20);

	//moon
	Transform moon1;
	moon1.m_position = vec2{ 50, 0 };
	moon1.m_parent = &plan1;
	Rigidbody moon1RB;
	PlanetaryMotor moon1motor;
	moon1motor.m_rotationSpeed = 5;
	PlanetaryRenderer moon1renderer(WHITE, 7);

	vec2 cameraPosition = vec2{ 0,0 };
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

		sunMotor.update(sunRbody);
		plan1motor.update(plan1RB);
		moon1motor.update(moon1RB);

		playerRigidbody.integrate(playerTransform, deltaTime);
		moon1RB.integrate(moon1, deltaTime);
		plan1RB.integrate(plan1, deltaTime);
		sunRbody.integrate(sunTransform, deltaTime);

		//camera shit
		vec2 gp = playerTransform.getGlobalPosition();
		cameraPosition = lerp(cameraPosition, gp, 1); // TODO: add smoothing.
		
		mat3 proj = translate(W / 2, H / 2) * scale(1, 1); 
		mat3 view = inverse(translate(cameraPosition.x, cameraPosition.y));		

		mat3 camera = proj * view;

		playerTransform.debugDraw(camera);
		sunTransform.debugDraw(camera);
		plan1.debugDraw(camera);
		moon1.debugDraw(camera);

		playerRigidbody.debugDraw(camera, playerTransform);
		
		sunRenderer.draw(camera, sunTransform);
		plan1renderer.draw(camera, plan1);
		moon1renderer.draw(camera, moon1);		
		playerRender.draw(camera, playerTransform);
		drawPlane(camera * playerTransform.getGlobalTransform() * Plane { 0, 0, 1, 0 }, WHITE);
	  }
	sfw::termContext();
}