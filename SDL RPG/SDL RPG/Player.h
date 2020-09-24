#ifndef H_Player
#define H_Player

#include "Being.h"
#include "AnimationComponent.h"
#include "PhysicsComponent.h"
#include "HitBox.h"
#include "Camera.h"

class Player : public Being
{
public:
    Player(loaderParameters* params_);
    //virtual ~Player();

    void drawObject();
    void updateObject(float dt_);
    void cleanObject();

private:
    AnimationComponent* animationComponent;
    PhysicsComponent* physicsComponent;
    HitBox* hitBox;

    void animationState();

    bool isGrounded;
    bool isJumping;

    bool isCrouching;
    bool isAttacking;


    Vector2f lastSafePosition;

    float attackTime;



};

#endif