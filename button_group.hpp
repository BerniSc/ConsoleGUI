#ifndef BUTTON_GROUP
#define BUTTON_GROUP

#include "gui_element.hpp"
#include "gui_config.hpp"
#include "button.hpp"

#include <string>
#include <vector>

class ButtonGroup : public GUI_Element {
    private:
        std::vector<Button*> buttons;
        Button* button;

        int currentSelection;
    public:
        virtual ~ButtonGroup();

        virtual void printElement();

        virtual void changeElement(gui_config::direction) override;
        virtual void changeElementBulk(gui_config::direction) override;
        virtual void toggleElement() override;

        virtual void addButton(Button* button);

        ButtonGroup();
};

#endif