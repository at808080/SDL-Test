#include "InputHandler.h"
#include "Game.h"

InputHandler* InputHandler::instance = nullptr;

InputHandler* InputHandler::getInstance()
{
    if (instance == nullptr)
    {
        instance = new InputHandler();
        return instance;
    }
    return instance;
}

void InputHandler::listenForInput()
{
    //Returns array of every key that is not pressed (corresponding with 0)
    

    SDL_Event e;

    while (SDL_PollEvent(&e))
    {
        switch (e.type)
        {
            //QUITTING THE GAME
        case SDL_QUIT:
            Game::getInstance()->quitGame();
            break;

            //KEY PRESSES
        case SDL_KEYDOWN:
            keyDown();
            break;

        case SDL_KEYUP:
            keyUp();
            break;

            //MOUSE 
        case SDL_MOUSEBUTTONDOWN:
        {
            if (e.button.button == SDL_BUTTON_LEFT)
            {
                mouseButtonStates[LEFT] = true;
            }
            if (e.button.button == SDL_BUTTON_RIGHT)
            {
                mouseButtonStates[RIGHT] = true;
            }
        }
        case SDL_MOUSEBUTTONUP:
        {
            if (e.button.button == SDL_BUTTON_LEFT)
            {
                mouseButtonStates[LEFT] = false;
            }
            if (e.button.button == SDL_BUTTON_RIGHT)
            {
                mouseButtonStates[RIGHT] = false;
            }
        }
        }
    }
}

bool InputHandler::getKeyDown(SDL_Scancode key_)
{
    if (keyStates != 0)
    {
        if (keyStates[key_] == 1)
            return true;
        else
            return false;
    }
    return false;
}

bool InputHandler::getMouseButtonState(int button_)
{
    return mouseButtonStates[button_];
}

InputHandler::InputHandler()
    : keyStates(0)
{
    for (int i = 0; i < 3; i++)
    {
        mouseButtonStates.push_back(false);
    }
}

void InputHandler::keyUp()
{
    keyStates = SDL_GetKeyboardState(0);
}

void InputHandler::keyDown()
{
    keyStates = SDL_GetKeyboardState(0);
}
