#ifndef GUI_CONFIG_HPP
#define GUI_CONFIG_HPP

#include <chrono>

namespace gui_config {
    constexpr inline bool debugMode = true;
    constexpr inline std::chrono::milliseconds tick(200);   // 250 ms

    constexpr inline int sliderWidth = 50;

    constexpr inline int offsetFromLeft = 8;

    constexpr inline char inputSeperation = '#';

    enum direction {down = -1, up = 1};
}

#endif