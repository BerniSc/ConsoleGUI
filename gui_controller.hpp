#ifndef GUI_CONTROLLER_HPP
#define GUI_CONTROLLER_HPP

#include <vector>
#include <iostream>
#include <string>

#include <thread>

#include "gui_element.hpp"
#include "gui_config.hpp"

class GUI_Element;

class GUI_Controller {
    private:
        static unsigned char instance_id_counter;
        const int instance_id;

        const std::string name;

        std::vector<GUI_Element*> elements;
        GUI_Element* element;

        uint currectSelection = 0;
    public:
        GUI_Controller(std::string);
        ~GUI_Controller();

        void printGUI();

        void changeCurrentElement(gui_config::direction direction);
        void toggleCurrentElement();

        void addElement(GUI_Element*);

        void switchElement(gui_config::direction direction);
    
};

#endif