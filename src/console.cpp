#include "console.h"
#include "date.h"

void Console::print(std::string message) {
    if(message.empty()) return;

    std::string newMessage = "<black>" + getCurrentTimeFormatted() + "<reset> " + message;

    for (const auto& entry : COLORS) {
        size_t position = 0;

        std::string from = entry.first;
        std::string to = "\033[" + entry.second + "m";

        while ((position = newMessage.find(from, position)) != std::string::npos) {
            newMessage = newMessage.replace(position, from.length(), to);
            position += to.length();
        }
    }

    std::cout << newMessage << "\033[0m" << std::endl;
}
