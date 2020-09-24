#ifndef H_GameMap
#define H_GameMap

#include "Layer.h"
#include <vector>


class GameMap 
{
public:
	void render();

	void update();

	std::vector<Layer*> getMapLayers();
	

private:
	friend class TileMapParser;
	std::vector<Layer*> mapLayers;
	
};

#endif