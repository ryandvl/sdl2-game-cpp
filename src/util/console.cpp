#include "util/console.hpp"
#include "util/date.hpp"

void Console::print(const char* message)
{
    const std::string message_str = message;
    if(message_str.empty()) return;

    std::string newMessage = "<white>" + getCurrentTimeFormatted() + "<reset> " + message;

    for (const auto& entry : COLORS) {
        size_t position = 0;

        std::string from = entry.first;
        std::string to = "\033[" + entry.second + "m";

        replaceAll(newMessage, from, to);
    }

    std::cout << newMessage << "\033[0m" << std::endl;
}

const char* Console::getOSName()
{
    #if defined(_WIN32) || defined(_WIN64)
        return "Windows";
    #elif defined(__APPLE__) || defined(__MACH__)
        return "macOS";
    #elif defined(__linux__)
        return "Linux";
    #elif defined(__unix__) || defined(__unix)
        return "Unix";
    #elif defined(_POSIX_VERSION)
        return "POSIX compliant system";
    #endif

    return "Unknown OS";
}

const std::string Console::getSDLVersion()
{
    SDL_version sdlVersion;
    SDL_GetVersion(&sdlVersion);

    std::string versionString = std::to_string(static_cast<int>(sdlVersion.major)) + "." +
        std::to_string(static_cast<int>(sdlVersion.minor)) + "." +
        std::to_string(static_cast<int>(sdlVersion.patch));

    return versionString;
}
