#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include "utils/math.hpp"

class Entity
{
    public:
        Entity(Vector2f position, SDL_Texture* texture);
        
        Vector2f getPosition();
        SDL_Rect getCurrentFrame();
        SDL_Texture* getTexture();
    private:
        Vector2f position;
        SDL_Rect currentFrame;
        SDL_Texture* texture;
};