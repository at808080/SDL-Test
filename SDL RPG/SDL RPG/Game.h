#ifndef H_Game
#define H_Game

#include <SDL.h>
#include <SDL_main.h>
#include <iostream>
#include <SDL_image.h>

#include "Player.h"
#include "Enemy.h"
#include "TextureManager.h"
#include "Vector2f.h"
#include "GameMap.h"

class Game
{
public:
	static Game* getInstance();

	bool initialiseGame();
	bool cleanGame();
	bool quitGame();

	void handleGameEvents();
	void updateGame();
	void renderGame();

	bool isGameRunning();
	SDL_Renderer* getTheRenderer();

	GameMap* getGameMap();

private:
	Game();

	bool running;

	SDL_Window* theWindow;
	SDL_Renderer* theRenderer;

	const int screenWidth = 640;
	const int screenHeight = 480;

	static Game* instance;

	GameMap* gameMap;
};

#endif