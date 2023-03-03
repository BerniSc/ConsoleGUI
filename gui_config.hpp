#ifndef GUI_CONFIG_HPP
#define GUI_CONFIG_HPP

#include <chrono>

namespace gui_config {
    constexpr inline bool debugMode = true;
    constexpr inline std::chrono::milliseconds tick(250);

    constexpr inline int sliderWidth = 50;

    enum direction {down = -1, up = 1};
}

#endif