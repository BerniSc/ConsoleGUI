#include "text_element.hpp"

TextElement::TextElement(std::string text, char frameSymbol) : text(text), frameSymbol(frameSymbol) {

}

std::string TextElement::getOuterLine() const {
    std::string line = "";
    for(int i = 0; i < width; i++) {
        line += this->frameSymbol;
    }
    return line;
}

std::string TextElement::getInnerLine() const {
    int descriptionLenght = this->text.length();
    //Ensure that description length is even for placing element in center
    if((descriptionLenght % 2)) descriptionLenght--;
    // -2 because of outer '#', -descriptionLenght to calculate out the text
    int stringOffset = (this->width - 2 - descriptionLenght) / 2;
    
    std::string line = "";
    line += this->frameSymbol;
    for(int i = 0; i < stringOffset; i++) {
        line += " ";
    }
    line += text;
    for(int i = 0; i < stringOffset; i++) {
        line += " ";
    }
    line += this->frameSymbol;
    return line;
}