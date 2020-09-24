#include "TileMapParser.h"
#include <fstream>

TileMapParser* TileMapParser::instance = nullptr;

TileMapParser* TileMapParser::getInstance()
{
    if (instance == nullptr)
    {
        instance = new TileMapParser();
    }
    return instance;
}

bool TileMapParser::loadMap()
{
    bool success = false;
    if (parseMap("map", "Resources/Maps/map2.tmx"))
    {
        success = true;
    }
    return success;
}

bool TileMapParser::cleanMap()
{
    std::map<std::string, GameMap*>::iterator it;
    for (it = gameMaps.begin(); it != gameMaps.end(); it++)
    {
        it->second = nullptr;
    }
    gameMaps.clear();
    return true;
}

GameMap* TileMapParser::getGameMap(std::string id_)
{
    return gameMaps[id_];
}

TileMapParser::TileMapParser()
{

}

bool TileMapParser::parseMap(std::string id_, std::string file_path)
{
    TiXmlDocument xmlDocument;
    xmlDocument.LoadFile(file_path);

    if (xmlDocument.Error())
    {
        std::cout << "Failed to load xml doc\n";
        return false;
    }
    TiXmlElement* root = xmlDocument.RootElement();

    int rows, columns, tilesize;
    root->Attribute("width", &rows);
    root->Attribute("height", &columns);
    root->Attribute("tilewidth", &tilesize);

    std::vector<tileSet> tilesets;
    for (TiXmlElement* i = root->FirstChildElement(); i != nullptr; i = i->NextSiblingElement())
    {
        if (i->Value() == std::string("tileset"))
        {
            tilesets.push_back(parseTileSet(i));
        }
    }

    GameMap* gamemap = new GameMap();
    for (TiXmlElement* i = root->FirstChildElement(); i != nullptr; i = i->NextSiblingElement())
    {
        if (i->Value() == std::string("layer"))
        {
            TileLayer* tilelayer = parseTileLayer(i, tilesets, tilesize, rows, columns);
            gamemap->mapLayers.push_back(tilelayer);
        }
    }

    gameMaps[id_] = gamemap;
    return true;

}

tileSet TileMapParser::parseTileSet(TiXmlElement* xml_tile_set)
{
    tileSet tileset;
    tileset.name = xml_tile_set->Attribute("name");
    xml_tile_set->Attribute("firstgid", &tileset.firstTileID); //the process of assignment is different for strings and numbers
    xml_tile_set->Attribute("tilecount", &tileset.totalTiles);
    tileset.lastTileID = (tileset.firstTileID + tileset.totalTiles) - 1;
    xml_tile_set->Attribute("columns", &tileset.columns);
    tileset.rows = tileset.totalTiles / tileset.columns;
    xml_tile_set->Attribute("tilewidth", &tileset.tileSize);
    TiXmlElement* imageResource = xml_tile_set->FirstChildElement();
    tileset.path = imageResource->Attribute("source");
    return tileset;
}

TileLayer* TileMapParser::parseTileLayer(TiXmlElement* xml_tile_layer, std::vector<tileSet> tile_sets, int tile_size, int rows_, int columns_)
{
    TiXmlElement* dataFromFile = nullptr;

    for (TiXmlElement* i = xml_tile_layer->FirstChildElement(); i != nullptr; i = i->NextSiblingElement())
    {
        dataFromFile = i;
        break;
    }

    std::string matrix(dataFromFile->GetText());
    std::istringstream iss(matrix);
    std::string id;

    std::vector<std::vector<int> > tilemap(rows_, std::vector<int>(columns_, 0)); //initialise all values in 2d vector with 0

    for (int x = 0; x < rows_; x++)
    {
        for (int y = 0; y < columns_; y++)
        {
            std::getline(iss, id, ',');
            std::stringstream convertor(id);
            convertor >> tilemap[x][y];

            if (!iss.good())
                break;
        }
    }

    return (new TileLayer(tile_size, rows_, columns_, tilemap, tile_sets));

}
