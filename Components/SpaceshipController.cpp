#include "SpaceshipController.h"
#include "sfwdraw.h"
using namespace sfw;
void SpaceshipController::update(SpaceshipLocomotion & loco)
{
	float hInput = 0.0f;
	hInput -= getKey('A');
	hInput += getKey('D');

	float vInput = 0.0f;
	vInput -= getKey('S');
	vInput += getKey('W');

	loco.doTurn(hInput);
	loco.doThrust(vInput);
}