#include "Camera.h"
#include "GameState.h"
Camera::Camera()
{
	projection = translate(800 / 2, 600 / 2) * scale(1, 1);

}

mat3 Camera::getCameraMatrix() const
{
	return projection * inverse(transform.getGlobalTransform());
}

void Camera::update(float deltaTime, GameState & gs)
{
	transform.m_position = gs.player.transform.getGlobalPosition();

}
