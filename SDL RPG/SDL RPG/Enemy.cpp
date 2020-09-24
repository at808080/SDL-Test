#include "Enemy.h"
#include "CollisionHandler.h"
#include "Game.h"

Enemy::Enemy(loaderParameters* params_)
	: Being(params_)
{
	hitBox = new HitBox();
	hitBox->setBuffer(-30, 0, 0, 0);

	physicsComponent = new PhysicsComponent();
	animationComponent = new AnimationComponent(true);
	animationComponent->initialiseParameters(textureID, 0, 7, 96, SDL_FLIP_NONE);
}

void Enemy::drawObject()
{
	animationComponent->drawAnimation(movementComponent->position.getX(), movementComponent->position.getY(), 96, 96, 1, 1, SDL_FLIP_NONE); //

	SDL_Rect hitbox = hitBox->getHitBox();
	SDL_RenderDrawRect(Game::getInstance()->getTheRenderer(), &hitbox);
}

void Enemy::updateObject(float dt_)
{
	physicsComponent->updatePhysics(dt_);
	
	hitBox->setHitBox(movementComponent->position.getX(), movementComponent->position.getY(), 40, 80);
	if (CollisionHandler::getInstance()->mapCollision(hitBox->getHitBox()))
	{
		//movementComponent->position.set(lastSafePosition);
		animationComponent->initialiseParameters(textureID, 4, 3, 200, SDL_FLIP_NONE);
		movementComponent->position.set(lastSafePosition);
	}
	else
	{
		lastSafePosition = movementComponent->position;
	}
	////////////////////////

	//updating the origin of the player each loop
	
	/*origin->setX(movementComponent->position.getX() + width / 2);
	origin->setY(movementComponent->position.getY() + height / 2);

	movementComponent->translate(physicsComponent->getPosition());
	animationComponent->updateAnimation(dt_);*/
}

void Enemy::cleanObject()
{
}
