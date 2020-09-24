#include "HitBox.h"

HitBox::HitBox()
{

}

SDL_Rect HitBox::getHitBox()
{
	return hitbox;
}

void HitBox::setBuffer(int x_, int y_, int w_, int h_)
{
	buffer = { x_, y_, w_, h_ };
}

void HitBox::setHitBox(int x_, int y_, int w_, int h_)
{
	hitbox = { x_ - buffer.x, y_ - buffer.y, w_ - buffer.w, h_ - buffer.h};
}
