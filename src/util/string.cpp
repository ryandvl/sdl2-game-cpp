#include "util/string.hpp"

void replaceAll(std::string& input, std::string from, std::string to) {
    if(from.empty()) return;

    size_t start_pos = 0;
    while ((start_pos = input.find(from, start_pos)) != std::string::npos) {
        input.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
}
