#ifndef GUI_ELEMENT_HPP
#define GUI_ELEMENT_HPP

#include <iostream>

#include "gui_config.hpp"

struct GUI_Element {
    private:
        static unsigned char instance_id_counter;
        const int instance_id;
        
        bool selected = false;
    protected:
        GUI_Element();

    public:
        virtual ~GUI_Element();
        
        virtual void printElement() = 0;
        virtual void changeElement(gui_config::direction) = 0;

        void setSelected(bool selected);
        bool getSelected() const;

        int getID() const;
};

#endif