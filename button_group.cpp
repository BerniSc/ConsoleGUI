#include "button_group.hpp"

ButtonGroup::ButtonGroup() : currentSelection(0) {
    static bool test = false;
    buttons.emplace_back(new Button(test, "test1"));
    buttons.emplace_back(new Button(test, "test2"));
    buttons[0]->setWidth(25);
    buttons[1]->setWidth(25);
    button = buttons[0];
    button->setSelected(true);
}

ButtonGroup::~ButtonGroup() {
    for(auto button : buttons) {
        delete button;
    }
}

void ButtonGroup::printElement() {
    std::string outerLine = std::string(gui_config::offsetFromLeft + 2, ' ');
    std::string innerLine = "";
    if(this->getSelected()) {
        innerLine = "-->";
        innerLine += std::string(gui_config::offsetFromLeft - 1, ' ');
    } else {
        innerLine = std::string(gui_config::offsetFromLeft + 2, ' ');
    }
    for(auto button : buttons) {
        outerLine += button->getOuterLine(); 
        innerLine += button->getInnerLine();
    }
    std::cout <<  outerLine << "\n" << \
                  innerLine << "\n" << \
                  outerLine;
}

void ButtonGroup::changeElement(gui_config::direction) {
    button->toggleElement();
}

void ButtonGroup::changeElementBulk(gui_config::direction direction) {
    if((this->currentSelection + direction) >= 0) {
        currentSelection += direction;
        currentSelection %= this->buttons.size();
    }
    button->setSelected(false);
    button = buttons[currentSelection];
    button->setSelected(true);
}

void ButtonGroup::toggleElement() {
    button->toggleElement();
}

void ButtonGroup::addButton(Button* button) {
    buttons.emplace_back(button);
}