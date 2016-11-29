#include "Depart.h"
#include "sfwdraw.h"
#include <iostream>
using namespace sfw;

void Depart::init(int a_font)
{
	font = a_font;
}

void Depart::draw()
{
	char buffer[64];
	drawString(font, "DANK TANK", 300, 500, 20, 20);
	drawString(font, "IN SPACE", 320, 450, 20, 20);
	drawString(font, "DESTROY ASTROY", 260, 400, 20, 20);
	drawString(font, "Press P to Play", 50, 100, 20, 20);
}

APP_STATE Depart::next()
{
	if (getKey('P'))
	{
		return ENTER_GAMESTATE;
	}
	return DEPART;
}
