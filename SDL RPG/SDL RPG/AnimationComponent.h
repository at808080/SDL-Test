#ifndef H_AnimationComponent
#define H_AnimationComponent

#include "BaseAnimation.h"

#include <string>
#include <SDL.h>
#include <SDL_main.h>
#include <SDL_image.h>



class AnimationComponent : public BaseAnimation
{
public:
	AnimationComponent(bool repeat_);

	void updateAnimation(float dt_);
	void drawAnimation(float x_, float y_, int w_, int h_, float x_scale, float y_scale, SDL_RendererFlip flip_ = SDL_FLIP_NONE);
	void initialiseParameters(std::string textureID_, int row_, int frame_count, int speed_, SDL_RendererFlip flip = SDL_FLIP_NONE);

	int getCurrentRow();
	void setCurrentRow(int row_);
	void increaseSpriteRow();
	void decreaseSpriteRow();

private:

	int spriteSheetRow;
	int spriteSheetFrame;
	int maxFrameCount;
	int animationSpeed;
	std::string textureID;
	SDL_RendererFlip rendererFlip;

};

#endif