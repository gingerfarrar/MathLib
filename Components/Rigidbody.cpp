#include "Rigidbody.h"
#include "sfwdraw.h"
using namespace sfw;
Rigidbody::Rigidbody()
{
	mass = 1;
	drag = 2.f;
	force = vec2{ 0,0 };
	impulse = vec2{ 0,0 };
	velocity = vec2{ 0,0 };
	angularVelocity = 0.0f;
	angulardrag = 2.f;
	acceleration = vec2{ 0,0 };
	angularAcceleration = 0.0f;
	torque = 0;
}
void Rigidbody::addForce(const vec2 &a_force)
{
	force += a_force;
}
void Rigidbody::addImpulse(const vec2 &a_impulse)
{
	impulse += a_impulse;
}
void Rigidbody::addTorque(float a_torque)
{
	torque += a_torque;
}
void Rigidbody::integrate(Transform &trans, float deltaTime)
{
	acceleration = force / mass;
	velocity += acceleration * deltaTime + impulse / mass;
	trans.m_position += velocity * deltaTime;
	force = impulse = { 0,0 };

	force = -velocity * drag;

	angularAcceleration = torque / mass;
	angularVelocity += angularAcceleration * deltaTime;
	trans.m_facing += angularVelocity *deltaTime;	
	torque = 0;
	torque = -angularVelocity * angulardrag;
}

void Rigidbody::debugDraw(const mat3 &T, const Transform & trans)
{
	vec2 p = (T * trans.getGlobalTransform())[2].xy;
	vec2 v = p + velocity;
	vec2 a = acceleration + p;

	drawLine(p.x, p.y, v.x, v.y, MAGENTA);
	drawLine(p.x, p.y, a.x, a.y, CYAN);
}