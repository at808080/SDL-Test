#include "Game.h"
#include "Clock.h"

int main(int argc, char* args[])
{
	Game::getInstance()->initialiseGame();

	while (Game::getInstance()->isGameRunning())
	{
		Game::getInstance()->handleGameEvents();
		Game::getInstance()->updateGame();
		Game::getInstance()->renderGame();
		Clock::getInstance()->tick();
	}

	Game::getInstance()->cleanGame();

	return 0;
}


/*
PROBLEMS:
1. Tileset not working with a second tileset. Only 1 tileset works currently
2. Dt - player speed not constant
3. need to include the Game file in camera to access global screen dimensions variables
4. collision handling is fucked. Need to fix dat

*/