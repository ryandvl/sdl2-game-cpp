#include "game.hpp"

Game::Game()
{
    renderWindow = nullptr;
    gameState = GameState::PLAY;
    isRunning = false;
    FPS = 60;
    FPSInterval = 1000;
    FPSDelay = FPSInterval / FPS;
    fps = 0;
}
Game::~Game() {}

void Game::init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "SDL failed to init: " << SDL_GetError() << std::endl;
        SDL_Quit();
    }

    if (TTF_Init() == -1) {
        std::cout << "TTF failed to init: " << TTF_GetError() << std::endl;
        SDL_Quit();
    }

    if (!(IMG_Init(IMG_INIT_PNG))) {
        std::cout << "IMG failed to init: " << IMG_GetError() << std::endl;
        SDL_Quit();
    }

    renderWindow = new RenderWindow(
        "SDL2 C++ Game",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1024,
        600,
        SDL_WINDOW_SHOWN
    );
}

void Game::run()
{
    init();

    std::string version = std::format(
        "<blue>SDL <black>(<white>{}<black>) <white>- <blue>{}",
        Console::getSDLVersion(),
        Console::getOSName()
    );
    Console::print(version);
    Console::print("<green>Game started!");

    gameLoop();
}

void Game::gameLoop()
{
    isRunning = true;
    SDL_Event event;

    fpsTimer = SDL_GetTicks64();

    while (gameState != GameState::EXIT)
    {
        frameStart = SDL_GetTicks64();

        handlePollEvent(event);
        handleEvents();

        frameCount++;

        if (SDL_GetTicks64() - fpsTimer >= FPSInterval) {
            fps = frameCount / ((SDL_GetTicks64() - fpsTimer) / FPSInterval);
            Console::print(std::format(
                "<magenta>FPS: <white>{}",
                fps
            ));

            fpsTimer = SDL_GetTicks64();
            frameCount = 0;
        }

        frameTime = SDL_GetTicks64() - frameStart;
        if (FPSDelay > frameTime) {
            SDL_Delay(FPSDelay - frameTime);
        }
    }

    stop();
}

void Game::handlePollEvent(SDL_Event& event)
{
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                gameState = GameState::EXIT;
                break;
        }
    }
}

void Game::handleEvents()
{
    renderWindow->clear();
    renderWindow->display();
}

void Game::stop()
{
    isRunning = false;

    // SDL_DestroyTexture(grassTexture);
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();

    Console::print("<red>Game closed!");
}
