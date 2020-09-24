#ifndef H_Layer
#define H_Layer

class Layer
{
public:
	virtual void render() = 0;
	virtual void update() = 0;
private:
};

#endif