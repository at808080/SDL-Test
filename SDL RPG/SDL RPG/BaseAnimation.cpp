#include "BaseAnimation.h"

BaseAnimation::BaseAnimation(bool repeat_)
	: repeat(repeat_), ended(false), currentFrame(0)
{
	ended = false;
}

bool BaseAnimation::isEnded()
{
	return ended;
}



