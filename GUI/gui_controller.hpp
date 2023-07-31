#ifndef GUI_CONTROLLER_HPP
#define GUI_CONTROLLER_HPP

#include <vector>
#include <iostream>
#include <string>

#include <thread>

#include "Elements/gui_element.hpp"
#include "gui_config.hpp"

class GUI_Element;

class GUI_Controller {
    private:
        const int instance_id;

        const std::string name;

        std::vector<GUI_Element*> elements;
        GUI_Element* element;

    // Declare Counter Protected to allow Element with multiple Columns to Edit ID
    protected:
        static unsigned char instance_id_counter;
        
    public:
        GUI_Controller(std::string);
        ~GUI_Controller();

        void printGUI();

        void changeCurrentElement(gui_config::direction direction);
        void changeCurrentElementBulk(gui_config::direction direction);
        void toggleCurrentElement();

        void addElement(GUI_Element*);

        void switchElement(gui_config::direction direction);
    
};

#endif