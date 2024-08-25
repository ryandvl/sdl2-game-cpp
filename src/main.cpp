#include "render_window.hpp"
#include "utils/console.hpp"
#include "entity/entity.hpp"
#include "utils/date.hpp"

int main(int argc, char *argv[])
{
    Console::print("<yellow>Loading...");

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "SDL failed to init: " << SDL_GetError() << std::endl;
        return -1;
    }

    if (!(IMG_Init(IMG_INIT_PNG))) {
        std::cout << "IMG failed to init: " << SDL_GetError() << std::endl;
        return -1;
    }

    RenderWindow window(
        "SDL2 C++ Game",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1024,
        600,
        SDL_WINDOW_SHOWN
    );

    SDL_Texture* grassTexture = window.loadTexture("res/gfx/grass_ground.png");

    Entity platform0(Vector2f(50, 50), grassTexture);
    Entity platform1(Vector2f(20, 20), grassTexture);

    bool isRunning = true;
    SDL_Event event;

    Uint64 startTime = 0;
    int frameCount = 0;
    const int fpsInterval = 1000;
    Uint64 fpsTimer = SDL_GetTicks64();

    while (isRunning) {
        startTime = SDL_GetTicks64();

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                isRunning = false;
            }
        }

        window.clear();
        window.render(platform0);
        window.render(platform1);

        window.display();

        frameCount++;

        if (SDL_GetTicks64() - fpsTimer >= fpsInterval) {
            float fps = frameCount / ((SDL_GetTicks64() - fpsTimer) / 1000.0f);
            std::cout << "FPS: " << fps << std::endl;

            fpsTimer = SDL_GetTicks64();
            frameCount = 0;
        }

        Uint32 frameTime = SDL_GetTicks64() - startTime;
        if (frameTime < 16) {
            SDL_Delay(16 - frameTime);
        }
    }

    window.cleanUp();
    SDL_DestroyTexture(grassTexture);
    IMG_Quit();
    SDL_Quit();
    
    Console::print("<red>Game closed!");

    return 0;
}
