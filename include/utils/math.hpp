#pragma once

#include <iostream>
#include <string>
#include <format>

#include "utils/console.hpp"

struct Vector2f
{
    float x, y;

    Vector2f()
        :x(0.0f), y(0.0f)
    {}

    Vector2f(float x, float y)
        :x(x), y(y)
    {}

    void print()
    {
        Console::print(std::format(
            "Vector2f[{}, {}]",
            std::to_string(x),
            std::to_string(y)
        ));
    }
};
