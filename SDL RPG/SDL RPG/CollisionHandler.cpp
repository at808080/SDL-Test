#include "CollisionHandler.h"
#include "Game.h"

CollisionHandler* CollisionHandler::instance = nullptr;

CollisionHandler::CollisionHandler()
{
    //this is an example of where I've used (TileLayer*) to make it a tilelayer and not just a layer
    collisionLayer = (TileLayer*)Game::getInstance()->getGameMap()->getMapLayers().front(); //depending on whihc layer of the map contains collision informaiton
    collisionTileMap = collisionLayer->getTileMap();

}

CollisionHandler* CollisionHandler::getInstance()
{
    if (instance == nullptr)
    {
        instance = new CollisionHandler();
    }
    return instance;
}

bool CollisionHandler::checkCollision(SDL_Rect a_, SDL_Rect b_)
{
    bool x_overlaps = (a_.x < (b_.x + b_.w)) && ((a_.x + a_.w > b_.x));
    bool y_overlaps = (a_.y < (b_.y + b_.w)) && ((a_.y + a_.w > b_.y));
    return (x_overlaps && y_overlaps);
}

bool CollisionHandler::mapCollision(SDL_Rect a_)
{
    int tilesize = 32;
    int rows = 30;
    int columns = 20;

    int lefttile = a_.x / tilesize;
    int righttile = (a_.x + a_.w) / tilesize;

    int toptile = a_.x / tilesize;
    int bottomtile = (a_.y + a_.h) / tilesize;

    if (lefttile < 0)
        lefttile = 0;
    if (righttile > columns)
        righttile = columns;
    if (toptile < 0)
        toptile = 0;
    if (bottomtile > rows)
        bottomtile = rows;

    for (int i = lefttile; i <= righttile; i++)
    {
        for (int j = toptile; j <= bottomtile; j++)
        {
            if (collisionTileMap[j][i] > 0)
            {
                return true;
            }
        }
    }
    return false;
}

