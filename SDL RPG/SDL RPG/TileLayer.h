#ifndef H_TileLayer
#define H_TileLayer

#include "Layer.h"

#include <string>
#include <vector>

struct tileSet
{
    int firstTileID;
    int lastTileID;
    int rows;
    int columns;
    int totalTiles;
    int tileSize;
    std::string name;
    std::string path;

};

class TileLayer : public Layer
{
public:
    TileLayer(int tile_size, int row_count, int col_count, std::vector<std::vector<int> > tile_map, std::vector<tileSet> tile_sets );

    virtual void render();
    virtual void update();

    std::vector<std::vector<int> > getTileMap();
private:
    int tileSize;
    int rows;
    int columns;
    std::vector<std::vector<int> > tileMap;
    std::vector<tileSet> tileSets;

};

#endif