#ifndef H_TextureManager
#define H_TextureManager

#include <string>
#include <SDL.h>
#include <SDL_main.h>
#include <SDL_image.h>
#include <map>
#include "Game.h"

class TextureManager
{
public:
	static TextureManager* getInstance();

	bool loadTexture(std::string id_, std::string file_name);
	void removeTexture(std::string id);
	void cleanTextures();
	void drawStaticTexture(std::string id_, int x_, int y_, int w_, int h_, float x_scale, float y_scale, float scroll_ratio, SDL_RendererFlip flip_);
	void drawStaticTile(std::string tileSetID_, int tile_size, int x_, int y_, int row_, int frame_, SDL_RendererFlip flip_= SDL_FLIP_NONE);
	void drawAnimatedTexture(std::string id_, int x_, int y_, int w_, int h_, int row, int frame, SDL_RendererFlip flip_);

	bool parseTextures(std::string path_);

	SDL_Renderer* getTheRenderer();

private:
	TextureManager();
	static TextureManager* instance;
	std::map<std::string, SDL_Texture*> textureMap;
};

#endif