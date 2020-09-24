#ifndef H_CollisionHandler
#define H_CollisionHandler

#include <SDL.h>
#include <vector>
#include "TileLayer.h"
#include "GameMap.h"

class CollisionHandler
{
public:
	static CollisionHandler* getInstance();

	bool checkCollision(SDL_Rect a_, SDL_Rect b_);
	bool mapCollision(SDL_Rect a_);


private:
	CollisionHandler();
	static CollisionHandler* instance;

	std::vector<std::vector<int> > collisionTileMap;
	TileLayer* collisionLayer;


};

#endif