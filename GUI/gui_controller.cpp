#include "gui_controller.hpp"

unsigned char GUI_Controller::instance_id_counter = 0;

GUI_Controller::GUI_Controller(std::string name) : instance_id(instance_id_counter++), name(name) {
    if(gui_config::debugMode) {
        std::cout << "Created GUI-Controller with id " << instance_id << " and name " << name << "!" << std::endl;
    }
}

GUI_Controller::~GUI_Controller() {
    if(gui_config::debugMode) {
        std::cout << "Destroyed GUI-Controller with id " << instance_id << " and name " << name << "!" << std::endl;
    }

    for(GUI_Element* element : this->elements) {
        delete element;
    }
}

void GUI_Controller::addElement(GUI_Element* element) {
    static int i = 0;
    std::cout << "Adding Element " << element << std::endl;
    this->elements.emplace_back(element);
    // If Two or more Elements are in vector deactivate previous and activate current
    if(i++ != 0) this->element->setSelected(false);
    this->element = element;
    this->element->setSelected(true);
}

void GUI_Controller::printGUI() {
    std::cout << "\033[2J\033[1;1H";
    std::cout << "\n\n";
    for(auto element : elements) {
        element->printElement();
        std::cout << "\n";
    }
    std::this_thread::sleep_for(gui_config::tick);
}

void GUI_Controller::changeCurrentElement(gui_config::direction direction) {
    std::cout << "Changing " << direction << std::endl;
    element->changeElement(direction);
}

void GUI_Controller::changeCurrentElementBulk(gui_config::direction direction) {
    std::cout << "Changing Bulk " << direction << std::endl;
    element->changeElementBulk(direction);
}

void GUI_Controller::toggleCurrentElement() {
    std::cout << "Toggling " << std::endl;
    element->toggleElement();
}

void GUI_Controller::switchElement(gui_config::direction direction) {
    std::cout << "1:" << ((this->element->getID() + direction) >= 0) << "   2:" << ((this->element->getID() + direction) <= (int) (this->elements.size() - 1)) << std::endl;
    std::cout << "Elements:" << this->elements.size() << " ID: " << this->element->getID() << std::endl; 
    std::cout << "Lower:" << element->getID() + direction << "  higher: " << (int) (elements.size()-1) << std::endl;
    if((this->element->getID() + direction) >= 0 && (this->element->getID() + direction) <= (int) (this->elements.size() - 1)) {
        std::cout << "officially switching now..." << std::endl;
        std::cout << "ID:" << this->element->getID() << std::endl;
        this->element->setSelected(false);
        std::cout <<  elements.size() << "  " << (this->element->getID() + static_cast<int>(direction)) << std::endl;
        this->element = this->elements[this->element->getID() + static_cast<int>(direction)];
        this->element->setSelected(true);
    }
}