#include "button.hpp"

Button::Button(bool &variable, std::string const && description) : variable(variable), description(description), selected(false) {
    std::cout << "Created Button " << description << std::endl;
}

Button::~Button() {
    std::cout << "Destroyed Button " << description << std::endl;
}

void Button::setWidth(int width) {
    this->width = width;
}

void Button::setSelected(bool selected) {
    this->selected = selected;
}

std::string Button::getOuterLine() {
    std::string line = "";
    for(int i = 0; i < width; i++) {
        line += selected ? "%" : "#";
    }
    return line;
}

std::string Button::getInnerLine() {
    int descriptionLenght = this->description.length();
    //Ensure that description length is even for placing element in center
    if((descriptionLenght % 2)) descriptionLenght--;
    // -2 because of outer '#', -descriptionLenght to calculate out the text
    int stringOffset = (this->width - 2 - descriptionLenght) / 2;
    
    std::string line = "";
    line += selected ? "%" : "#";
    for(int i = 0; i < stringOffset; i++) {
        line += " ";
    }
    line += description;
    for(int i = 0; i < stringOffset; i++) {
        line += " ";
    }
    line += selected ? "%" : "#";
    return line;
}

std::string Button::getDescription() {
    return this->description;
}

void Button::toggleElement() {   
    variable = !variable;
}