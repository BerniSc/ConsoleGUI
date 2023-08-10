#ifndef GUI_CONFIG_HPP
#define GUI_CONFIG_HPP

#include <chrono>

namespace gui_config {
    constexpr inline bool debugMode = false;

    // Defualt-Value: 250
    constexpr inline std::chrono::milliseconds tick(200);   // 250 ms

    // Default-Value: 50
    constexpr inline int sliderWidth = 99;

    // Default-Value: 8
    constexpr inline int offsetFromLeft = 8;

    // Default-Value: "#"
    constexpr inline char* const inputSeperation = (char*) "#";

    enum direction {down = -1, up = 1};
}

#endif