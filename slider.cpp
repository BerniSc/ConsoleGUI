#include "slider.hpp"

Slider::Slider(int &variable, int size, int min) : variable(variable), size(size), min(min) {
    std::cout << "Created Slider" << std::endl;
}

void Slider::printElement() {
    int lengthStatus = variable * gui_config::sliderWidth / this->size;
    int widthCounter = 8;
    if(this->getSelected()) {
        std::cout << std::setw(widthCounter + lengthStatus) << variable << std::endl;
        std::cout << "-->";
        widthCounter -= 3;
    }
    //std::cout << "  " << min << "   ";
    std::cout << std::setw(widthCounter) << min << "  ";
    for(int i = 0; i < gui_config::sliderWidth; i++) {
        if(lengthStatus-- > 0) {
            std::cout << "#";
        } else {
            std::cout << ".";
        }
    }
    //std::cout << "  " << size + min;
    std::cout << std::setw(5) << size + min;
}

void Slider::changeElement(gui_config::direction direction) {
    if((this->variable + direction) >= 0 && (this->variable + direction) <= this->size) {
        variable += direction;
    }
}

Slider::~Slider() {
    std::cout << "Destroyed Slider" << std::endl;
}