#ifndef H_MovementComponent
#define H_MovementComponent

#include "Vector2f.h"

class MovementComponent
{
public:
	MovementComponent(float x_ = 0, float y_ = 0);
	Vector2f position;
	void translate(Vector2f v_);

private:
	
};

#endif