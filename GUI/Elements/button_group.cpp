#include "button_group.hpp"

ButtonGroup::ButtonGroup() : currentSelection(0) {
    std::cout << "Created ButtonGroup  With ID " << this->getID() << std::endl;
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
                  innerLine << "\t\t" << "currently: " << (buttons[currentSelection]->getVar() ? "true" : "false") <<"\n" << \
                  outerLine;
}

void ButtonGroup::changeElement(gui_config::direction) {
    button->toggleElement();
}

void ButtonGroup::changeElementBulk(gui_config::direction direction) {
    if((this->currentSelection + direction) >= 0) {
        currentSelection += direction;
        currentSelection %= this->buttons.size();
    } else {
        currentSelection = this->buttons.size() - 1;
    }
    button->setSelected(false);
    button = buttons[currentSelection];
    button->setSelected(true);
}

void ButtonGroup::toggleElement() {
    button->toggleElement();
}

void ButtonGroup::addButton(bool *variable, std::string const description) {
    instance_id_counter--;
    Button *button = new Button(variable, description);


    buttons.emplace_back(button);

    this->button = buttons[0];
    this->button->setSelected(true);

    int overallTextWidth = 0;
    for(auto button_iterator : buttons) {
        overallTextWidth += button_iterator->getDescription().length();
    }

    //Calculate individual Width of every button
    std::vector<int> individualWidth;
    for(auto button_iterator : buttons) {
        individualWidth.push_back(std::round((gui_config::sliderWidth) * float(button_iterator->getDescription().length() + 1) / float(overallTextWidth)));
    }

    //get sum of all individual Widths for checking if its has Slider length
    int sum = 0;
    for(auto i : individualWidth) {
        sum += i;
    }

    for(unsigned long int i = 0; i < buttons.size(); i++) {
        buttons[i]->setWidth(individualWidth[i]);
    }

    if(sum != gui_config::sliderWidth - 1) {
        buttons[buttons.size() - 1]->setWidth(individualWidth[buttons.size() - 1] + (gui_config::sliderWidth - sum));
    }
}