#ifndef H_BaseAnimation
#define H_BaseAnimation

class BaseAnimation
{
public:
	BaseAnimation(bool repeat_ = true);

	virtual void updateAnimation(float dt_) = 0;
	bool isEnded();

private:
	bool special;
	bool repeat;
	bool ended;
	int currentFrame;

};

#endif