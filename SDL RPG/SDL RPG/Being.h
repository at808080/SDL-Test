#ifndef H_Being
#define H_Being

#include <string>

#include "Entity.h"
class Being : public Entity
{
public:
    Being(loaderParameters* params_);
        
    virtual void drawObject() = 0;
    virtual void updateObject(float dt_) = 0;
    virtual void cleanObject() = 0;

protected:
    std::string name;

private:

};

#endif