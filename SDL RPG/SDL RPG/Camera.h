#ifndef H_Camera
#define H_Camera

#include <SDL.h>
#include "Vector2f.h"

class Camera
{
public:
	static Camera* getInstance();

	SDL_Rect getViewRectangle();
	Vector2f getCameraPosition();

	void setTarget(Vector2f* target_);
	void updateCamera(float dt);

private:
	Camera();
	static Camera* instance;

	Vector2f* targetOfCamera; //should be the center of the player's sprite
	Vector2f positionOfCamera;
	SDL_Rect viewOfCamera;

	int screenWidth = 640;
	int screenHeight = 480;
};

#endif