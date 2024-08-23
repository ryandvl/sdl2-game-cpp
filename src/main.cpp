#include <iostream>
#include <string>
#include <sstream>
#include <format>

#include "game.h"
#include "console.h"

using namespace std;

string getSDLVersion();

int main(int argc, char *argv[]) {
    Game game;

    string version = format(
        "<blue>SDL <black>(<white>{}<black>)",
        getSDLVersion()
    );
    Console::print(version);
    Console::print("<yellow>Loading...");
    
    game.run();

    Console::print("<red>Game closed!");

    return 0;
}

string getSDLVersion() {
    SDL_version sdlVersion;
    SDL_GetVersion(&sdlVersion);

    ostringstream oss;

    oss << static_cast<int>(sdlVersion.major) << "."
        << static_cast<int>(sdlVersion.minor) << "."
        << static_cast<int>(sdlVersion.patch);

    return oss.str();
}
