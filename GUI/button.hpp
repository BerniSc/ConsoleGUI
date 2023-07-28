#ifndef BUTTON
#define BUTTON

#include "gui_element.hpp"
#include "text_element.hpp"
#include "gui_config.hpp"

#include <string>
#include <cmath>
#include <iostream>

class Button :  public TextElement {
    private:
        bool &variable;

        int width;

        std::string description;

        bool selected;
    public:
        virtual ~Button();

        std::string getInnerLine() const;
        std::string getOuterLine() const;

        std::string getDescription() const;

        void setWidth(int width);
        void setSelected(bool selected);

        virtual void toggleElement();

        bool getVar() const;

        virtual void printElement() {};
        virtual void changeElement(gui_config::direction) {};
        virtual void changeElementBulk(gui_config::direction) {};

        Button(bool &variable, std::string const & description);
};

#endif