#ifndef H_HitBox
#define H_HitBox

#include <SDL.h>

class HitBox
{
public:
	HitBox();

	SDL_Rect getHitBox();
	void setBuffer(int x_, int y_, int w_, int h_);
	void setHitBox(int x_, int y_, int w_, int h_);

private:
	SDL_Rect hitbox;
	SDL_Rect buffer;
};

#endif