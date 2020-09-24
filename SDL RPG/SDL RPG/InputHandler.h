#ifndef H_InputHandler
#define H_InputHandler

#include <SDL.h>
#include <vector>

enum mouseButtons
{
	LEFT = 0,
	RIGHT = 1
};

class InputHandler
{
public:
	static InputHandler* getInstance();

	void listenForInput();

	//KEYS
	bool getKeyDown(SDL_Scancode code_);

	//MOUSE
	bool getMouseButtonState(int button_);	

private:
	InputHandler();
	static InputHandler* instance;

	//KEYS
	void keyUp();
	void keyDown();
	const Uint8* keyStates; //array to store states of keys

	//MOUSE
	std::vector<bool> mouseButtonStates;

};

#endif