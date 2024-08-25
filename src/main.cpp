#include <SDL_ttf.h>

#include "game.hpp"
#include "util/console.hpp"

Game *game = nullptr;

int main(int argc, char *argv[])
{
    game = new Game();

    game->run();

    return 0;
}
