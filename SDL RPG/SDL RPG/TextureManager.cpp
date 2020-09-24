#include "TextureManager.h"
#include "Camera.h"
#include "External//TinyXML/tinyxml.h"
#include <string>
#include <fstream>


TextureManager* TextureManager::instance = nullptr;

TextureManager* TextureManager::getInstance()
{
    if (instance == nullptr)
    {
        instance = new TextureManager();
        return instance;
    }
    return instance;
}

bool TextureManager::loadTexture(std::string id_, std::string file_name)
{
    
    SDL_Surface* surface = nullptr;
    SDL_Texture* texture = nullptr;
    //CREATE SURFACE
    surface = IMG_Load(file_name.c_str());
    if (surface == nullptr) {
        SDL_Log("failed to load texture: %s, %s", file_name.c_str(), SDL_GetError());
        return false;
    }
    //CREATE TEXTURE
    texture = SDL_CreateTextureFromSurface(getTheRenderer(), surface);
    if (texture == nullptr)
    {
        SDL_Log("failed to create the texture from the surface %s", SDL_GetError());
    }
    //ADD TEXTURE TO MAP OF TEXTURES
    textureMap[id_] = texture;
    return true;
}

void TextureManager::removeTexture(std::string id_)
{
    SDL_DestroyTexture(textureMap[id_]);
    textureMap.erase(id_);
}

void TextureManager::cleanTextures()
{
    for (std::map<std::string, SDL_Texture*>::iterator i = textureMap.begin(); i != textureMap.end(); i++)
    {
        SDL_DestroyTexture(i->second);
    }
    textureMap.clear();
    std::cout << "Texture map cleared";
}

void TextureManager::drawStaticTexture(std::string id_, int x_, int y_, int w_, int h_, float x_scale, float y_scale, float scroll_ratio, SDL_RendererFlip flip_)
{
    SDL_Rect sourceRectangle = {0, 0, w_, h_};
    //SDL_Rect destinationRectangle = { x_, y_, w_, h_ };
    Vector2f camera = Camera::getInstance()->getCameraPosition() * scroll_ratio;
    SDL_Rect destinationRectangle = { x_ - camera.getX(), y_ - camera.getY(), w_*x_scale, h_*y_scale }; //SDL_Rect destinationRectangle = { x_, y_, tile_size, tile_size };

    SDL_RenderCopyEx(getTheRenderer(), textureMap[id_], &sourceRectangle, &destinationRectangle, 0, nullptr, flip_);
}

void TextureManager::drawStaticTile(std::string tile_set_id, int tile_size, int x_, int y_, int row_, int frame_, SDL_RendererFlip flip_)
{
    SDL_Rect sourceRectangle = { tile_size * frame_, tile_size * (row_ ), tile_size, tile_size }; //potentially just row not row-1

    Vector2f camera = Camera::getInstance()->getCameraPosition();
    SDL_Rect destinationRectangle = { x_ - camera.getX(), y_ - camera.getY(), tile_size, tile_size }; //SDL_Rect destinationRectangle = { x_, y_, tile_size, tile_size };
    SDL_RenderCopyEx(getTheRenderer(), textureMap[tile_set_id], &sourceRectangle, &destinationRectangle, 0, nullptr, flip_);    
}

void TextureManager::drawAnimatedTexture(std::string id_, int x_, int y_, int w_, int h_, int row_, int frame_, SDL_RendererFlip flip_)
{
    SDL_Rect sourceRectangle = { w_ * frame_, h_ * row_, w_, h_ };

    Vector2f camera = Camera::getInstance()->getCameraPosition();
    SDL_Rect destinationRectangle = { x_ - camera.getX(), y_ - camera.getY(), w_, h_ }; //SDL_Rect destinationRectangle = { x_, y_, w_, h_ };
    SDL_RenderCopyEx(getTheRenderer(), textureMap[id_], &sourceRectangle, &destinationRectangle, 0, nullptr, flip_);
}

bool TextureManager::parseTextures(std::string path_)
{
    /*TiXmlDocument xmldoc;
    xmldoc.LoadFile(path_);
    if (xmldoc.Error())
    {
        std::cout << "failed to load\n";
        return false;
    }

    TiXmlElement* root = xmldoc.RootElement();
    for (TiXmlElement* e = root->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
    {
        if (e->Value() == std::string("texture"))
        {
            std::string id = e->Attribute("id");
            std::string src = e->Attribute("source");
            loadTexture(id, src);
        }
    }*/

    /////////////////////////

    std::ifstream inFile("Resources/textures.ini");

    if (inFile.is_open())
    {
        std::string id = "";
        std::string src = "";

        while (inFile >> id >> src)
        {
            loadTexture(id, src);
            std::cout << "Loaded texture\n";
        }
            
        
    }
    inFile.close();
    return true;
}

SDL_Renderer* TextureManager::getTheRenderer()
{
    return Game::getInstance()->getTheRenderer();
}

TextureManager::TextureManager()
{
}
