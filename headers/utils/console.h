#pragma once

#include <iostream>
#include <map>
#include <string>

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

class Console {
    public:
        static void print(std::string message);

    private:
          
};