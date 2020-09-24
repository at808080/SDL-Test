#include "Camera.h"

Camera* Camera::instance = nullptr;

Camera* Camera::getInstance()
{
    if (instance == nullptr)
    {
        instance = new Camera();
    }
    return instance;
}

SDL_Rect Camera::getViewRectangle()
{
    return viewOfCamera;
}

Vector2f Camera::getCameraPosition()
{
    return positionOfCamera;
}

void Camera::setTarget(Vector2f* target_)
{
    targetOfCamera = target_;
}

void Camera::updateCamera(float dt)
{
    if (targetOfCamera != nullptr)
    {
        viewOfCamera.x = targetOfCamera->getX() - screenWidth / 2;
        viewOfCamera.y = targetOfCamera->getY() - screenHeight / 2; 

        if (viewOfCamera.x < 0)
        {
            viewOfCamera.x = 0;
        }
        if (viewOfCamera.y < 0)
        {
            viewOfCamera.y = 0;
        }
        if (viewOfCamera.x > (2*screenWidth - viewOfCamera.w))
        {
            viewOfCamera.x = (2 * screenWidth - viewOfCamera.w);
        }
        if (viewOfCamera.y > (2 * screenHeight - viewOfCamera.h))
        {
            viewOfCamera.y = (2 * screenHeight - viewOfCamera.h);
        }
        positionOfCamera = Vector2f(viewOfCamera.x, viewOfCamera.y);
    }
}

Camera::Camera()
    : viewOfCamera({0, 0, screenWidth, screenHeight}), targetOfCamera(nullptr)
{
}
