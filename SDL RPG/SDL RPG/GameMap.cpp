#include "GameMap.h"
#include <iostream>

void GameMap::render()
{
	for (unsigned int i = 0; i < mapLayers.size(); i++) //
	{
		//std::cout << "maplayers: " << mapLayers.size() << "\n";
		mapLayers[i]->render();
	}
}

void GameMap::update()
{
	for (unsigned int i = 0; i < mapLayers.size(); i++)
	{
		mapLayers[i]->update();
	}
}

std::vector<Layer*> GameMap::getMapLayers()
{
	return mapLayers;
}
