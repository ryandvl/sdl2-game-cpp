#include "utils/date.hpp"

std::string getCurrentTimeFormatted()
{
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    std::tm localTime;

    #ifdef _WIN32
    localtime_s(&localTime, &currentTime); // WINDOWS
    #else
    localtime_r(&currentTime, &localTime); // UNIX
    #endif

    std::ostringstream oss;
    oss << "[" 
        << std::put_time(&localTime, "%H:%M:%S")
        << "]";

    return oss.str();
}

float hireTimeInSeconds()
{
    float time = SDL_GetTicks64();
    time *= 0.001f;

    return time;
}
