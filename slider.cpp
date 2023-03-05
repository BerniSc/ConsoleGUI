#include "slider.hpp"

Slider::Slider(int &variable, int const size, int const min, std::string const && description) : variable(variable), size(size), min(min), description(description) {
    variable = min;
    toggleValue = min;
    std::cout << "Created Slider " << description << std::endl;
}

void Slider::printElement() {
    //Counter for printing Progress of Slider 
    int lengthStatus = (variable - min) * gui_config::sliderWidth / this->size;
    //Offset from the left
    int widthCounter = gui_config::offsetFromLeft;
    //If current element is selcted print Current Value on top of it and with arrow on the front of Slider -> reduce offset by size of Arrow
    if(this->getSelected()) {
        std::cout << std::setw(widthCounter + lengthStatus) << variable << std::endl;
        std::cout << "-->";
        widthCounter -= 3;
    }
    //Print Min Value with WithOffset from left
    std::cout << std::setw(widthCounter) << min << "  ";
    //Print Slider and Status of Slider
    for(int i = 0; i < gui_config::sliderWidth; i++) {
        if(lengthStatus-- > 0) {
            std::cout << "#";
        } else {
            std::cout << ".";
        }
    }
    //Print Max Value of Slider with Offset
    std::cout << std::setw(5) << size + min;
    std::cout << "\t" << description;
}

void Slider::changeElement(gui_config::direction direction) {
    //if((this->variable + direction) >= 0 && (this->variable + direction) <= this->size) {
    if((this->variable + direction - min) >= 0 && (this->variable + direction - min) <= this->size) {
        variable += direction;
    }
}

void Slider::changeElementBulk(gui_config::direction direction) {
    //Set StepSize to 10 Percent for BulkMove
    int stepSize = (size - min) * 0.1f;
    for(int i = 0; i < stepSize; i++) {
        changeElement(direction);
    }
}

void Slider::toggleElement() {
    int temp = variable;
    variable = toggleValue;
    if(toggleValue != min) {
        toggleValue = min;
    } else {
        toggleValue = temp;
    }
}

Slider::~Slider() {
    std::cout << "Destroyed Slider " << description << std::endl;
}