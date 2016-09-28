#include "sfwdraw.h"
#include "vec2.h"
#include "Transform.h"
#include "flops.h"
using namespace sfw;

void main()
{
	initContext();
	Transform trans(400,300);

	int j = int(4);
	int k(4);
	int l = (4);
	int n{ 4 };

	Transform tl = Transform(400, 300);
	Transform tn = { 400,300 };
	Transform tm( 400,300 );
	Transform tq{ 400,300 };

	//trans.position = vec2{ 400,300 };
	trans.facing = deg2rad(45);
	trans.scale = vec2{ 24,8 };

	vec2 basis = { 40,0 };
	float ang_vec = 0;
	while (stepContext())
	{
		vec2 incident = fromAngle(ang_vec) * 40;
		float proj = dot(basis, normal(incident));
		drawLine(400, 300, 400 + basis.x, 300 + basis.y, BLACK);
		trans.facing -= getDeltaTime();
		trans.debugDraw();
	}
	termContext();
}