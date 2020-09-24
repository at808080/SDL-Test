#include "Vector2f.h"

Vector2f::Vector2f(float x_, float y_)
{
	x = x_;
	y = y_;
}

float Vector2f::getX()
{
	return this->x;
}

float Vector2f::getY()
{
	return this->y;
}

void Vector2f::setX(float x_)
{
	this->x = x_;
}

void Vector2f::setY(float y_)
{
	this->y = y_;
}

void Vector2f::set(Vector2f v_)
{
	setX(v_.getX());
	setY(v_.getY());
}

float Vector2f::getLength()
{
	return sqrt(x * x + y * y);
}

Vector2f Vector2f::operator+(const Vector2f& second_Vect) const
{
	Vector2f tempVect(x + second_Vect.x, y + second_Vect.y);
	return tempVect;
}

Vector2f Vector2f::operator-(const Vector2f& second_Vect) const
{
	Vector2f tempVect(x - second_Vect.x, y - second_Vect.y);
	return tempVect;
}

Vector2f Vector2f::operator*(float scalar_) const
{
	Vector2f tempVect(x * scalar_, y * scalar_);
	return tempVect;
}

Vector2f Vector2f::operator/(float scalar_) const
{
	Vector2f tempVect(x / scalar_, y / scalar_);
	return tempVect;
}

bool Vector2f::operator==(const Vector2f& other_vect) const
{
	if (x == other_vect.x && y == other_vect.y)
	{
		return true;
	}
	return false;
}

const Vector2f& Vector2f::operator=(const Vector2f& other_vect)
{
	if (this != &other_vect)
	{
		x = other_vect.x;
		y = other_vect.y;
	}
	return *this;
}

void Vector2f::normalise()
{
	float l = getLength();
	if (l > 0)
	{
		(*this) /= l;
	}
}

Vector2f& operator+=(Vector2f& first_vect, Vector2f& second_vect)
{
	first_vect.x += second_vect.x;
	first_vect.y += second_vect.y;
	return first_vect;
}

Vector2f& operator-=(Vector2f& first_vect, Vector2f& second_vect)
{
	first_vect.x -= second_vect.x;
	first_vect.y -= second_vect.y;
	return first_vect;
}

Vector2f& operator*=(Vector2f& first_vect, float scalar_)
{
	first_vect.x *= scalar_;
	first_vect.y *= scalar_;
	return first_vect;
}

Vector2f& operator/=(Vector2f& first_vect, float scalar_)
{
	first_vect.x /= scalar_;
	first_vect.y /= scalar_;
	return first_vect;
}
