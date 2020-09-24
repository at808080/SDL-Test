#ifndef H_Enemy
#define H_Enemy


#include "Being.h"
#include "AnimationComponent.h"
#include "PhysicsComponent.h"
#include "HitBox.h"
#include "Camera.h"


#include "Being.h"
class Enemy : public Being
{
public:
    Enemy(loaderParameters* params_);
    //virtual ~Player();

    void drawObject();
    void updateObject(float dt_);
    void cleanObject();

private:

    AnimationComponent* animationComponent;
    PhysicsComponent* physicsComponent;
    HitBox* hitBox;
    Vector2f lastSafePosition;
};

#endif