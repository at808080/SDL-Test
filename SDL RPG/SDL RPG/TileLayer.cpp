#include "TileLayer.h"
#include "TextureManager.h"

TileLayer::TileLayer(int tile_size, int row_count, int col_count, std::vector<std::vector<int> > tile_map, std::vector<tileSet> tile_sets)
	: tileSize(tile_size), rows(row_count), columns(col_count), tileSets(tile_sets), tileMap(tile_map)
{
	//tileMap = tile_map;
	//tileSets = tile_sets;

	for (unsigned int i = 0; i < tileSets.size(); i++)
	{
		TextureManager::getInstance()->loadTexture(tileSets[i].name, "Resources/Maps/" + tileSets[i].path);
	}
}

void TileLayer::render()
{
	for (unsigned int i = 0; i < rows; i++)
	{
		for (unsigned int j = 0; j < columns; j++)
		{
			int tileID = tileMap[i][j];

			if (tileID == 0)
				continue;
			else
			{
				int tilesetindex = 0;

				if (tileSets.size() > 1)
				{
					for (unsigned int k = 1; k < tileSets.size(); k++) //tiles in the first tileset have correct index. however tiles in tilesets 2, 3, etc will need to have their indexes corrected
					{
						if (tileID > tileSets[k].firstTileID && tileID < tileSets[k].lastTileID)
						{
							tileID += (tileSets[k].totalTiles = tileSets[k].lastTileID);
							tilesetindex = k;
							break;
						}
					}
				}

				tileSet tileset = tileSets[tilesetindex];
				int tilesetrow = tileID / tileset.columns;
				int tilesetcolumn = tileID - tilesetrow * tileset.columns - 1;

				if (tileID % tileset.columns == 0)
				{
					tilesetrow -= 1;
					tilesetcolumn = tileset.columns - 1;
				}

				TextureManager::getInstance()->drawStaticTile(tileset.name, tileset.tileSize, j * tileset.tileSize, i * tileset.tileSize, tilesetrow, tilesetcolumn);

			}
		}
	}
}

void TileLayer::update()
{
}

std::vector<std::vector<int>> TileLayer::getTileMap()
{
	return tileMap;
}
