#include "Clock.h"




Clock* Clock::instance = nullptr;

Clock* Clock::getInstance()
{
	if (instance == nullptr)
	{
		instance = new Clock();
		return instance;
	}
	return instance;
}

void Clock::tick()
{
	deltaTime = (SDL_GetTicks() - previousTime) * (FPS_TARGET / 1000.f);

	if (deltaTime > DT_TARGET)
	{
		deltaTime = DT_TARGET;
	}

	previousTime = SDL_GetTicks();
}

float Clock::getDeltaTime()
{
	return deltaTime;
}

Clock::Clock()
	: deltaTime(DT_TARGET), previousTime(DT_TARGET)
{
}
