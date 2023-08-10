#ifndef GUI_ELEMENT_HPP
#define GUI_ELEMENT_HPP

#include <iostream>
#include <iomanip>

#include "../gui_config.hpp"

class GUI_Element {
    protected:
        // Counter for Instance-ID's (Important to know that Buttons in Button-Groups get their "Parents" ID)
        static unsigned char instance_id_counter;
        // Saves the actual Instance-ID for the Element
        const unsigned char instance_id;
        
        // Represents whether the current Element is selected and therefore can be manipulated by User-Inputs (True := selected)
        bool selected;

        // Parent-Element Constructor -> Sets common elements like Instance-ID and selected
        GUI_Element();
    public:
        virtual ~GUI_Element();
        
        // Each GUI-Element should be printable
        virtual void printElement() = 0;
        // Allows for changing the Element in single Steps
        virtual void changeElement(gui_config::direction) = 0;
        // Allows for changing the Element in larger Steps
        virtual void changeElementBulk(gui_config::direction) = 0;

        // Allows for instantly toggeling the Element (changing any Value != 0 to 0 and back)
        virtual void toggleElement() = 0;

        // Setter for whether the current Element is selected -> Needs to be public as it is to be Set by controller
        void setSelected(bool selected);
        // Getter for whether the current Element is selected -> Needs to be public as it is to be Set by controller
        bool getSelected() const;

        // Getter for own Instance-ID
        int getID() const;
};

#endif