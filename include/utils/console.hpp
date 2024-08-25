#pragma once

#include <iostream>
#include <map>
#include <string>
#include <SDL.h>

#include "utils/string.hpp"

const std::map<std::string, std::string> COLORS = {
    {"<reset>", "0"},
    {"<bold>", "1"},

    {"<black>", "30"},
    {"<red>", "31"},
    {"<green>", "32"},
    {"<yellow>", "33"},
    {"<blue>", "34"},
    {"<magenta>", "35"},
    {"<cyan>", "36"},
    {"<white>", "37"}
};

class Console
{
    public:
        static void print(const char* message);
        static void print(const std::string message) {
            print(message.c_str());
        };
        static const char* getOSName();
        static const char* getGraphicsCardInfo(SDL_Renderer* renderer);
        static const char* getSDLVersion();

    private:
          
};