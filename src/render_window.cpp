#include "render_window.hpp"

RenderWindow::RenderWindow(
    const char* title,
    int x, int y,
    int width, int height,
    Uint32 flags
) : window(NULL), renderer(NULL)
{
    window = SDL_CreateWindow(
        title,
        x, y,
        width, height, 
        flags
    );

    if (window == NULL) {
        std::cout << "Window failed to init: " << SDL_GetError() << std::endl;
    }

    renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED
    );

    if (renderer == NULL) {
        std::cout << "Renderer failed to init: " << SDL_GetError() << std::endl;
    }

    Console::print("<green>Window loaded!");
}

RenderWindow::~RenderWindow() {}

SDL_Texture* RenderWindow::loadTexture(const char* filePath)
{
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, filePath);

    if (texture == NULL) {
        std::cout << "Image failed to load texture: " << SDL_GetError() << std::endl;
    }
    
    return texture;
}

void RenderWindow::cleanUp()
{
    SDL_DestroyWindow(window);
}

void RenderWindow::clear()
{
    SDL_RenderClear(renderer);
}

void RenderWindow::render(Entity& entity)
{
    SDL_Rect src_rect;
    src_rect.x = entity.getCurrentFrame().x;
    src_rect.y = entity.getCurrentFrame().y;
    src_rect.w = entity.getCurrentFrame().w;
    src_rect.h = entity.getCurrentFrame().h;

    SDL_Rect dst_rect;
    dst_rect.x = entity.getPosition().x * 4;
    dst_rect.y = entity.getPosition().y * 4;
    dst_rect.w = entity.getCurrentFrame().w * 4;
    dst_rect.h = entity.getCurrentFrame().h * 4;

    SDL_RenderCopy(
        renderer,
        entity.getTexture(),
        &src_rect,
        &dst_rect
    );
}

void RenderWindow::display()
{
    SDL_RenderPresent(renderer);
}
