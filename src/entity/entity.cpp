#include "entity/entity.hpp"

Entity::Entity(Vector2f position, SDL_Texture* texture)
    :position(position), texture(texture)
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 32;
    currentFrame.h = 32;
}

Vector2f Entity::getPosition()
{
    return position;
}

SDL_Rect Entity::getCurrentFrame()
{
    return currentFrame;
}

SDL_Texture* Entity::getTexture()
{
    return texture;
}
