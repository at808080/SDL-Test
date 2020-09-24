#ifndef H_Clock
#define H_Clock

#include <SDL.h>
#include <SDL_main.h>

const float FPS_TARGET = 60.f;
const float DT_TARGET = 1.5f;

class Clock
{
public:
	static Clock* getInstance();

	void tick();
	float getDeltaTime();
	

private:
	Clock();
	static Clock* instance;

	float deltaTime;
	float previousTime;
};

#endif