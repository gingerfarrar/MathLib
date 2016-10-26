#include "SpaceshipRenderer.h"
#include "sfwdraw.h"
#include "shapedraw.h"
#include "Transform.h"
using namespace sfw;
SpaceshipRenderer::SpaceshipRenderer()
{
	color = MAGENTA;
}

void SpaceshipRenderer::draw(const mat3 & T, const Transform & ship)
{
	mat3 glob = T* ship.getGlobalTransform();
	vec3 F = glob * vec3{ -1, 1, 1 };
	vec3 L = glob * vec3{ -1, -1, 1 };
	vec3 R = glob * vec3{ 2, 0, 1 };

	drawLine(L.x, L.y, F.x, F.y, color);
	drawLine(F.x, F.y, R.x, R.y, color);
	drawLine(R.x, R.y, L.x, L.y, color);

	drawCircle(glob * Circle{ 0,0,1.5 }, 0x888888FF);
	drawAABB(glob * AABB{ 0,0,2,2 }, 0x888888FF);
}
