#include "Entity.h"

//CONSTRUCTOR
Entity::Entity(loaderParameters* params_)
{
	width = params_->widthL;
	height = params_->heightL;
	textureID = params_->textureIDL;
	rendererFlip = params_->rendererFlipL;

	movementComponent = new MovementComponent(params_->x, params_->y);
	origin = new Vector2f(params_->x + params_->widthL/2, params_->y + params_->heightL/2);
}

Vector2f* Entity::getOrigin()
{
	return origin;
}
