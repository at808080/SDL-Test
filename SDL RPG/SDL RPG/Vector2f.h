#ifndef H_Vector2f
#define H_Vector2f

#include <cmath>

class Vector2f
{


public:
	Vector2f(float x_ = 0, float y_ = 0);
	float getX();
	float getY();
	void setX(float x_);
	void setY(float y_);
	void set(Vector2f v_);

	float getLength();

	Vector2f operator+(const Vector2f& second_Vect) const;
	Vector2f operator-(const Vector2f& second_Vect) const;
	Vector2f operator*(float scalar_) const;
	Vector2f operator/(float scalar_) const;

	friend Vector2f& operator+= (Vector2f& first_vect, Vector2f& second_vect);
	friend Vector2f& operator-= (Vector2f& first_vect, Vector2f& second_vect);
	friend Vector2f& operator*= (Vector2f& first_vect, float scalar_);
	friend Vector2f& operator/= (Vector2f& first_vect, float scalar_);

	bool operator==(const Vector2f&) const;

	const Vector2f& operator=(const Vector2f&);

	void normalise();

private:
	float x;
	float y;
};

#endif