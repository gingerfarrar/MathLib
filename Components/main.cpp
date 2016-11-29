#include "sfwdraw.h"
#include "GameState.h"
#include "constdecl.h"
#include "Splash.h"
#include "Lose.h"
#include "Depart.h"
#include "Win.h"
using namespace sfw;

void main()
{
	
	initContext(800,600);
	unsigned font = loadTextureMap("../res/fontmap.png", 16, 16);

	Splash splash;
	GameState game;
	Lose lose;
	Depart dep;
	Win win;

	splash.init(font);
	game.init(font);
	lose.init(font);
	dep.init(font);
	win.init(font);

	APP_STATE state = ENTER_SPLASH;
	while (stepContext())
	{
		float dt = getDeltaTime();
		switch (state)
		{
		case ENTER_SPLASH:
			splash.play();
		case SPLASH:
			splash.step();
			splash.draw();
			state = splash.next();
			break;
		case ENTER_DEPART:			
		case DEPART:	
			dep.draw();
			state = dep.next();
			break;
		case ENTER_GAMESTATE:
			game.play();
		case GAMESTATE:		
			game.update(dt);
			game.draw();
			state = game.next();
			break;
		case ENTER_WIN:
		case WIN:
			win.draw();
			state = win.next();
			break;
		case ENTER_LOSE:
			lose.play();
		case LOSE:
			lose.step();
			lose.draw();
			state = lose.next();
			break;

		}

	}
	sfw::termContext();
}