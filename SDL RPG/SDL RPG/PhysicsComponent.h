#ifndef H_PhysicsComponent
#define H_PhysicsComponent

#include "Vector2f.h"
#include <string>

#define MASS 1.f
#define GRAVITY 9.8

enum getVals
{
	POSIITON = 0,
	VELOCITY = 1,
	ACCELERATION = 2
};

class PhysicsComponent
{
public:
	PhysicsComponent();

	void setMass(float mass_);
	void setGravity(float gravity_);

	void applyForce(Vector2f force_);
	void applyXForce(float force_);
	void applyYForce(float force_);
	void resetForce();

	void applyFriction(Vector2f friction_);
	void resetFriction();

	void updatePhysics(float dt);

	float getMass();
	float getGravity();
	Vector2f getPosition();
	Vector2f getVelocity();
	Vector2f getAcceleration();

private:
	float mass;
	float gravity;

	Vector2f force;
	Vector2f friction;

	Vector2f position;
	Vector2f velocity;
	Vector2f acceleration;
};

#endif