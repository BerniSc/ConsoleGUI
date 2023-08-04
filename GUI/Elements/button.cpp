#include "button.hpp"

Button::Button(bool *variable, std::string description) : TextElement(&description), variable(variable), description(description), selected(false) {
    std::cout << "Created Button " << description << " With ID " << this->getID() << std::endl;
    this->setWidth(gui_config::sliderWidth);
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

std::string Button::getOuterLine() const {
    std::string line = "";
    for(int i = 0; i < width; i++) {
        line += selected ? "%" : "#";
    }
    return line;
}

std::string Button::getInnerLine() const {
    int descriptionLenght = this->description.length();
    //Ensure that description length is even for placing element in center
    if((descriptionLenght % 2)) descriptionLenght++;
    // -1 because of outer '#', -descriptionLenght to calculate out the text
    int stringOffset = (this->width - 1 - descriptionLenght) / 2;
    
    std::string line = "";
    line += selected ? "%" : "#";
    for(int i = 0; i < stringOffset; i++) {
        line += " ";
    }
    line += description;
    //for(int i = 0; i < stringOffset; i++) {
    //    line += " ";
    //}
    while(line.size() + 1 < this->width) line += " ";
    line += selected ? "%" : "#";
    return line;
}

std::string Button::getDescription() const {
    return this->description;
}


bool Button::getVar() const {
    return *variable;
}

void Button::toggleElement() {   
    *variable = !(*variable);
}

void Button::printElement() {
    std::string outerLine = std::string(gui_config::offsetFromLeft + 2, ' ');
    std::string innerLine = "";
    if(this->getSelected()) {
        innerLine = "-->";
        innerLine += std::string(gui_config::offsetFromLeft - 1, ' ');
    } else {
        innerLine = std::string(gui_config::offsetFromLeft + 2, ' ');
    }
    outerLine += getOuterLine(); 
    innerLine += getInnerLine();
    std::cout <<  outerLine << "\n" << \
                  innerLine << "\t\t" << "currently: " << (getVar() ? "true" : "false") <<"\n" << \
                  outerLine;
}

void Button::changeElement(gui_config::direction direction) {

}

void Button::changeElementBulk(gui_config::direction direction) {

}