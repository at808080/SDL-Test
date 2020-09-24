#ifndef H_BaseEntity
#define H_BaseEntity
class BaseEntity
{
public:

	virtual void drawObject() = 0;
	virtual void updateObject(float dt_) = 0;
	virtual void cleanObject() = 0;
};
#endif

