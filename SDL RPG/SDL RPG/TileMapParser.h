#ifndef H_TileMapParser
#define H_TileMapParser

#include "External/TinyXML/tinyxml.h"
#include "External/TinyXML/tinystr.h"
#include <map>
#include "GameMap.h"
#include "TileLayer.h"
#include <string>
#include <iostream>

class TileMapParser
{
public:
	static TileMapParser* getInstance();

	bool loadMap();
	bool cleanMap();

	GameMap* getGameMap(std::string id_);

private:
	TileMapParser();
	static TileMapParser* instance;
	std::map<std::string, GameMap*> gameMaps;

	bool parseMap(std::string id_, std::string file_path);
	tileSet parseTileSet(TiXmlElement* xml_tile_set);
	TileLayer* parseTileLayer(TiXmlElement* xml_tile_layer, std::vector<tileSet> tile_sets, int tile_size, int rows_, int columns_);

};

#endif