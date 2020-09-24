#ifndef H_GameEntity
#define H_GameEntity

#include "BaseEntity.h"
#include "MovementComponent.h"
#include "Vector2f.h"


#include <string>
#include <SDL.h>
#include <SDL_main.h>
#include <SDL_image.h>


//LOADERPARAMETERS: PARAMETERS TO PASS INTO AN ENTITY'S CONSTRUCTOR
struct loaderParameters
{
public:
    loaderParameters(std::string texture_id, int x_, int y_, int w_, int h_, SDL_RendererFlip flip_ = SDL_FLIP_NONE)
    {
        x = x_;
        y = y_;
        widthL = w_;
        heightL = h_;
        rendererFlipL = flip_;
        textureIDL = texture_id;
    }
    float x;
    float y;
    int widthL;
    int heightL;
    std::string textureIDL;
    SDL_RendererFlip rendererFlipL;
};

//ABSTRACT ENTITY CLASS: ANYTHING IN THE GAME DERIVED FROM ENTITY
class Entity : public BaseEntity //potentially CHOP BASE ENTITY CLASS WHY IS IT EVEN THERE AYE
{
public:
    Entity(loaderParameters* params_);
    
    virtual void drawObject() = 0;
    virtual void updateObject(float dt_) = 0;
    virtual void cleanObject() = 0;

    Vector2f* getOrigin();

protected:
    MovementComponent* movementComponent;
    int width;
    int height;
    std::string textureID;
    SDL_RendererFlip rendererFlip;
    Vector2f* origin;
    
};

#endif
