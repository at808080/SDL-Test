#include "PhysicsComponent.h"

PhysicsComponent::PhysicsComponent()
{
	mass = MASS;
	gravity = GRAVITY;
}

void PhysicsComponent::setMass(float mass_)
{
	mass = mass_;
}

void PhysicsComponent::setGravity(float gravity_)
{
	gravity = gravity_;
}

void PhysicsComponent::applyForce(Vector2f force_)
{
	force = force_;
}

void PhysicsComponent::applyXForce(float force_)
{
	force.setX(force_);
}

void PhysicsComponent::applyYForce(float force_)
{
	force.setY(force_);
}

void PhysicsComponent::resetForce()
{
	force = Vector2f(0, 0);
}

void PhysicsComponent::applyFriction(Vector2f friction_)
{
	friction = friction_;
}

void PhysicsComponent::resetFriction()
{
	friction = Vector2f(0, 0);
}

void PhysicsComponent::updatePhysics(float dt)
{
	acceleration = (force + friction) / mass;
	velocity = acceleration * dt;
	position = velocity * dt;
}

float PhysicsComponent::getMass()
{
	return mass;
}

float PhysicsComponent::getGravity()
{
	return gravity;
}

Vector2f PhysicsComponent::getPosition()
{
	return position;
}

Vector2f PhysicsComponent::getVelocity()
{
	return velocity;
}

Vector2f PhysicsComponent::getAcceleration()
{
	return acceleration;
}