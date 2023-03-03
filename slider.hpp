#ifndef SLIDER
#define SLIDER

#include "gui_element.hpp"
#include "gui_config.hpp"

class Slider : public GUI_Element {
    private:
        const int size;
        const int min; 
        int &variable;
    public:
        virtual ~Slider();

        virtual void printElement();

        virtual void changeElement(gui_config::direction) override;

        Slider(int &variable, int size, int min);
};

#endif