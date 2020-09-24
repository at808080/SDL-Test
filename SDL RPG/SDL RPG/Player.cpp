#include "Player.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "CollisionHandler.h"

Player::Player(loaderParameters* params_)
	: Being(params_), isCrouching(false), isAttacking(false), attackTime(20.f)
{
	hitBox = new HitBox();
	hitBox->setBuffer(-30, 0, 0, 0);

	physicsComponent = new PhysicsComponent();

	animationComponent = new AnimationComponent(true);
	animationComponent->initialiseParameters(textureID, 0, 7, 96, SDL_FLIP_NONE);
}

void Player::drawObject()
{
	//TextureManager::getInstance()->drawAnimatedTexture(textureID, movementComponent->position.getX(), movementComponent->position.getY(), width, height, row, frame, SDL_FLIP_NONE);
	animationComponent->drawAnimation(movementComponent->position.getX(), movementComponent->position.getY(), width, height, 1, 1);

	Vector2f camera = Camera::getInstance()->getCameraPosition();
	SDL_Rect hitbox = hitBox->getHitBox();
	hitbox.x -= camera.getX();
	hitbox.y -= camera.getY();
	SDL_RenderDrawRect(Game::getInstance()->getTheRenderer(), &hitbox);
}

void Player::updateObject(float dt_)
{
	physicsComponent->updatePhysics(0.5);

	if (InputHandler::getInstance()->getKeyDown(SDL_SCANCODE_A))
	{
		animationComponent->initialiseParameters(textureID, 7, 7, 96, SDL_FLIP_NONE);
		physicsComponent->applyForce(Vector2f(-1, 0));
	}
	else if (InputHandler::getInstance()->getKeyDown(SDL_SCANCODE_D))
	{
		animationComponent->initialiseParameters(textureID, 0, 7, 96, SDL_FLIP_NONE);
		physicsComponent->applyForce(Vector2f(1, 0));
	}
	else if (InputHandler::getInstance()->getKeyDown(SDL_SCANCODE_W))
	{
		animationComponent->initialiseParameters(textureID, 1, 7, 96, SDL_FLIP_NONE);
		physicsComponent->applyForce(Vector2f(0, -1));
	}
	else if (InputHandler::getInstance()->getKeyDown(SDL_SCANCODE_S))
	{
		animationComponent->initialiseParameters(textureID, 4, 7, 96, SDL_FLIP_NONE);
		physicsComponent->applyForce(Vector2f(0, 1));
	}
	else if (InputHandler::getInstance()->getKeyDown(SDL_SCANCODE_C))
	{
		isCrouching = true;
		animationComponent->initialiseParameters("playeractions", 0, 7, 200, SDL_FLIP_NONE);
		physicsComponent->resetForce();
	}
	else if (InputHandler::getInstance()->getKeyDown(SDL_SCANCODE_X))
	{
		isAttacking = true;
		animationComponent->initialiseParameters("playeractions", 1, 7, 200, SDL_FLIP_NONE);
		physicsComponent->resetForce();
	}
	else if (!InputHandler::getInstance()->getKeyDown(SDL_SCANCODE_A)
		&& !InputHandler::getInstance()->getKeyDown(SDL_SCANCODE_D)
		&& !InputHandler::getInstance()->getKeyDown(SDL_SCANCODE_W)
		&& !InputHandler::getInstance()->getKeyDown(SDL_SCANCODE_S))
	{
		animationComponent->initialiseParameters(textureID, 4, 3, 200, SDL_FLIP_NONE);
		physicsComponent->resetForce();
	}
	
	
	
	Vector2f lastsafevel;
	/////////////////////
	/*physicsComponent->updatePhysics(dt_);
	
	movementComponent->position.set(physicsComponent->getPosition());*/
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
	origin->setX(movementComponent->position.getX() + width / 2);
	origin->setY(movementComponent->position.getY() + height / 2);

	movementComponent->translate(physicsComponent->getPosition());
	animationComponent->updateAnimation(dt_);	

	//animationState();
}

void Player::cleanObject()
{
	//TextureManager::getInstance()->cleanTextures();
	TextureManager::getInstance()->removeTexture(textureID);
}

void Player::animationState()
{
	animationComponent->initialiseParameters(textureID, 4, 3, 200, SDL_FLIP_NONE);

	if (isCrouching)
		animationComponent->initialiseParameters("playeractions", 0, 7, 200, SDL_FLIP_NONE);
	if (isAttacking)
		animationComponent->initialiseParameters("playeractions", 1, 7, 200, SDL_FLIP_NONE);
}
