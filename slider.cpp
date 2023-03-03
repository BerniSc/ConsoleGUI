#include "slider.hpp"

Slider::Slider(int &variable) : size(2), min(-1), variable(variable) {
    std::cout << "Created Slider" << std::endl;
}

void Slider::printElement() {
    int lengthStatus = variable * gui_config::sliderWidth / this->size;
    if(this->getSelected()) {
        std::cout << variable << std::endl;
        std::cout << "-->";
    }
    std::cout << "  " << min << "   ";
    for(int i = 0; i < gui_config::sliderWidth; i++) {
        if(lengthStatus-- > 0) {
            std::cout << "#";
        } else {
            std::cout << ".";
        }
    }
    std::cout << "  " << size + min;
}

void Slider::changeElement(gui_config::direction direction) {
    if((this->variable + direction) >= 0 && (this->variable + direction) <= this->size) {
        variable += direction;
    }
}

Slider::~Slider() {
    std::cout << "Destroyed Slider" << std::endl;
}