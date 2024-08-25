#pragma once

#include <iostream>
#include <string>
#include <format>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "render_window.hpp"
#include "util/console.hpp"

enum GameState
{ PLAY, EXIT };

class Game
{
    public:
        Game();
        ~Game();

        bool isRunning;

        // FPS
        int FPS;
        int FPSInterval;
        int FPSDelay;
        Uint64 frameStart;
        int frameTime;
        int fps;
        Uint64 fpsTimer;
        int frameCount;

        void run();
        void update();
        void render();
        void clean();
        void stop();

    private:
        void init();
        void gameLoop();
        void handlePollEvent(SDL_Event& event);
        void handleEvents();

        RenderWindow* renderWindow;

        GameState gameState;
};
