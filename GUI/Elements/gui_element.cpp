#include "gui_element.hpp"

unsigned char GUI_Element::instance_id_counter = 0;

GUI_Element::GUI_Element() : instance_id(instance_id_counter++), selected(false) {

}

GUI_Element::~GUI_Element() {
    std::cout << "Destructed TEST" << std::endl;
}

int GUI_Element::getID() const {
    return this->instance_id;
}

void GUI_Element::setSelected(bool selected) {
    this->selected = selected;
}

bool GUI_Element::getSelected() const {
    return selected;
}