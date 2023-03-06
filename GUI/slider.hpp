#ifndef SLIDER
#define SLIDER

#include "gui_element.hpp"
#include "gui_config.hpp"

#include <string>

class Slider : public GUI_Element {
    private:
        int &variable;

        const int size;
        const int min; 

        std::string const description;

        int toggleValue;
    public:
        virtual ~Slider();

        virtual void printElement();

        virtual void changeElement(gui_config::direction) override;
        virtual void changeElementBulk(gui_config::direction) override;
        virtual void toggleElement() override;

        Slider(int &variable, int const size, int const min, std::string const &&description);
};

#endif