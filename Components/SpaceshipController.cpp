#include "SpaceshipController.h"
#include "sfwdraw.h"

using namespace sfw;

SpaceshipController::SpaceshipController(unsigned CTR_LEFT, unsigned CTR_RIGHT,
	unsigned CTR_UP, unsigned CTR_DOWN, unsigned CTR_BREAK)
{

}
void SpaceshipController::update(SpaceshipLocomotion & loco)
{
	float hInput = 0.0f;
	hInput += getKey('A');
	hInput -= getKey('D');

	float vInput = 0.0f;
	vInput -= getKey('S');
	vInput += getKey('W');
	
	float bInput = getKey(' ');
	loco.doStop(bInput);
	loco.doTurn(hInput);
	loco.doThrust(vInput);
}