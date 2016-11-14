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
#include "Collider.h"
using namespace sfw;

void main()
{
	float W = 800, H = 600;

	initContext(W, H);
	
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

	vec2 cameraPosition = vec2{ 0,0 };
	vec2 hullVrts[] = { {-1,1}, {-1,-1}, {2,0}};

	Transform occluderTransform(10, 10);
	occluderTransform.m_scale = vec2{ 20,30 };
	Collider occluderCollider(hullVrts, 3);

	Collider playerCollider(hullVrts, 3);

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
		CollisionData results = ColliderCollision(playerTransform, playerCollider,
													occluderTransform,occluderCollider);

		playerRigidbody.integrate(playerTransform, deltaTime);
		
		sunRbody.integrate(sunTransform, deltaTime);

		if (results.penetrationDepth >= 0)
		{
			vec2 mtv = results.penetrationDepth * results.collisionNormal;
			vec3 mtv3 = { mtv.x, mtv.y,1 };
			
			mtv3 = inverse(playerTransform.getGlobalTransform()) * mtv3;
			mtv = mtv3.xy;
		}


		//camera shit
		vec2 gp = playerTransform.getGlobalPosition();
		cameraPosition = lerp(cameraPosition, gp, 1); // TODO: add smoothing.
		
		mat3 proj = translate(W / 2, H / 2) * scale(1, 1); 
		mat3 view = inverse(translate(cameraPosition.x, cameraPosition.y));		

		mat3 camera = proj * view;

		playerTransform.debugDraw(camera);
		sunTransform.debugDraw(camera);

		playerRigidbody.debugDraw(camera, playerTransform);
		
		sunRenderer.draw(camera, sunTransform);
		occluderTransform.debugDraw(camera);
		occluderCollider.DebugDraw(camera, occluderTransform);
		playerRender.draw(camera, playerTransform);
		drawPlane(camera * playerTransform.getGlobalTransform() * Plane { 0, 0, 1, 0 }, WHITE);
	 
		playerCollider.DebugDraw(camera, playerTransform);
	}
	sfw::termContext();
}