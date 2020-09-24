#include "MovementComponent.h"

MovementComponent::MovementComponent(float x_, float y_)
	: position(Vector2f(x_, y_))
{

}

void MovementComponent::translate(Vector2f v_)
{
	position += v_;
}
