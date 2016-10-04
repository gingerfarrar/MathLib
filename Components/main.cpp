#include "sfwdraw.h"
#include "vec2.h"
#include "Transform.h"
#include "flops.h"
#include "Rigidbody.h"
using namespace sfw;

void main()
{
	initContext();
	Transform playerTransform(400,300);
	Rigidbody playerRigidbody;
	playerRigidbody.velocity = vec2{ 0,0 };
	float W = 800, H = 600;

	while (stepContext())
	{
		

		float deltaTime = getDeltaTime();

		if (getKey('W'))		playerRigidbody.acceleration.y += 5.0f;
		if (getKey('A'))		playerRigidbody.acceleration.x -= 5.0f;
		if (getKey('S'))		playerRigidbody.acceleration.y -= 5.0f;
		if (getKey('D'))		playerRigidbody.acceleration.x += 5.0f;


		if (getKey('Q'))		playerRigidbody.angularAcceleration += 1.0f;
		if (getKey('E'))		playerRigidbody.angularAcceleration -= 1.0f;
		if (playerTransform.position.x < 0)		playerTransform.position.x = W;
		else if (playerTransform.position.x > W)	playerTransform.position.x = 0;
		if (playerTransform.position.y < 0)		playerTransform.position.y = H;
		else if (playerTransform.position.y > H)	playerTransform.position.y = 0;

		playerRigidbody.integrate(playerTransform, deltaTime);
		playerTransform.debugDraw();
		/*for (int i = 0; i < 100; ++i)
		{
			float x1 = i / 100.f;
			float y1 = HardAngle(x1);

			float x2 = (i + 1) / 100.f;
			float y2 = HardAngle(x2);
			x1 *= 400;
			x2 *= 400;
			y1 *= 400;
			y2 *= 400;
			drawLine(x1, y1, x2, y2);
		}*/
		
	  }
	sfw::termContext();
}