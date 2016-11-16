#include "sfwdraw.h"
#include "GameState.h"
using namespace sfw;

void main()
{
	float W = 800, H = 600;

	initContext(W, H);
	
	GameState game;

	while (stepContext())
	{	


		float dt = getDeltaTime();
		game.update(dt);
		game.draw();

	}
	sfw::termContext();
}