#include "AnimationComponent.h"

#include "TextureManager.h"


AnimationComponent::AnimationComponent(bool repeat_)
	: BaseAnimation(repeat_)
{

}

void AnimationComponent::updateAnimation(float dt_)
{
	spriteSheetFrame = (SDL_GetTicks() / animationSpeed) % maxFrameCount;
}

void AnimationComponent::drawAnimation(float x_, float y_, int w_, int h_, float x_scale, float y_scale, SDL_RendererFlip flip_)
{
	TextureManager::getInstance()->drawAnimatedTexture(textureID, x_, y_, w_, h_, spriteSheetRow, spriteSheetFrame, rendererFlip);
}

void AnimationComponent::initialiseParameters(std::string textureID_, int row_, int frame_count, int speed_, SDL_RendererFlip flip_)
{
	textureID = textureID_;
	spriteSheetRow = row_;
	spriteSheetFrame = 0;
	maxFrameCount = frame_count;
	animationSpeed = speed_;
	rendererFlip = flip_;
}

int AnimationComponent::getCurrentRow()
{
	return spriteSheetRow;
}

void AnimationComponent::setCurrentRow(int row_)
{
	spriteSheetRow = row_;
}

void AnimationComponent::increaseSpriteRow()
{
	spriteSheetRow++;
}

void AnimationComponent::decreaseSpriteRow()
{
	spriteSheetRow--;
}
