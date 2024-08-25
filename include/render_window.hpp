#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include "utils/console.hpp"
#include "entity/entity.hpp"

class RenderWindow
{
    public:
        RenderWindow(const char* title, int x, int y, int width, int height, Uint32 flags);
        ~RenderWindow();

        SDL_Texture* loadTexture(const char* filePath);

        void cleanUp();
        void clear();
        void render(Entity& entity);
        void display();
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;

        int screenWidth;
        int screenHeight;
};
