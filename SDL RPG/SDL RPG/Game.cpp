#include "Game.h"
#include "InputHandler.h"
#include "Clock.h"
#include "TileMapParser.h"
#include <iostream>
#include "Camera.h"


//UP TO MADSY CODE EPISODE 15
//UNSURE HOW TO PROGRESS WITH TILEMAP / IN GAME EDITOR OR USE TILED?

Game* Game::instance = nullptr;
Player* player_1 = nullptr;
Enemy* enemy_1 = nullptr;


Game::Game()
    : running(true), theRenderer(nullptr), theWindow(nullptr), gameMap(nullptr)
{
}

Game* Game::getInstance()
{
    if (instance == nullptr)
    {
        instance = new Game();
    }
    return instance;
}

bool Game::initialiseGame()
{
    std::cout << "Initialising game";
    running = true;
    //INITIALISE SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0)
    {
        running = false;
    }
    //CREATE THE WINDOW
    SDL_WindowFlags windowflags = (SDL_WindowFlags)(SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
    theWindow = SDL_CreateWindow("Tutorial", 100, 100, screenWidth, screenHeight, windowflags);
    if (theWindow == nullptr)
    {
        running = false;
    }
    //CREATE THE RENDERER
    theRenderer = SDL_CreateRenderer(theWindow, -1, SDL_RENDERER_ACCELERATED);
    if (theRenderer == nullptr)
        running = false;

    //tilemap
    if (!TileMapParser::getInstance()->loadMap())
    {
        std::cout << "Failed to load map\n" ;
    }

    gameMap = TileMapParser::getInstance()->getGameMap("map");
    
    TextureManager::getInstance()->parseTextures("");

    player_1 = new Player(new loaderParameters("player", 100, 100, 96, 96));
    enemy_1 = new Enemy(new loaderParameters("enemy", 200, 50, 96, 96));


    //camera
    Camera::getInstance()->setTarget(player_1->getOrigin());

    return running;

    

}

bool Game::cleanGame()
{
    TextureManager::getInstance()->cleanTextures();
    SDL_DestroyRenderer(theRenderer);
    SDL_DestroyWindow(theWindow);
    IMG_Quit();
    return false;
}

bool Game::quitGame()
{
    this->running = false;
    return running;
}

void Game::handleGameEvents()
{
    InputHandler::getInstance()->listenForInput();
}

void Game::updateGame()
{
    float dt = Clock::getInstance()->getDeltaTime();
    gameMap->update();
    player_1->updateObject(dt);
    Camera::getInstance()->updateCamera(dt);
}

void Game::renderGame()
{
    //SDL_SetRenderDrawColor(theRenderer, 255, 0, 255, 125);
    SDL_RenderClear(theRenderer);
    //TextureManager::getInstance()->drawStaticTexture("bmw", 0, 0, 600, 600, 0.5, 0.5, 0.5, SDL_FLIP_NONE);
    gameMap->render();
    player_1->drawObject();
    enemy_1->drawObject();
    SDL_RenderPresent(theRenderer);
}

bool Game::isGameRunning()
{
    return running;
}

SDL_Renderer* Game::getTheRenderer()
{
    return theRenderer;
}

GameMap* Game::getGameMap()
{
    return gameMap;
}
