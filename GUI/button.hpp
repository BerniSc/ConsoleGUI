#ifndef BUTTON
#define BUTTON

#include "gui_element.hpp"
#include "gui_config.hpp"

#include <string>
#include <cmath>
#include <iostream>

class Button {
    private:
        bool &variable;

        int width;

        std::string const description;

        bool selected;
    public:
        virtual ~Button();

        std::string getInnerLine();
        std::string getOuterLine();

        std::string getDescription();

        void setWidth(int width);
        void setSelected(bool selected);

        virtual void toggleElement();

        Button(bool &variable, std::string const && description);
};

#endif