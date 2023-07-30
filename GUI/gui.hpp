#ifndef GUI_HPP
#define GUI_HPP

#include "gui_controller.hpp"
#include "gui_exceptions.hpp"
#include "Elements/button_group.hpp"
#include "Elements/slider.hpp"

#include <unistd.h>
#include <termios.h>
#include <mutex>

#include <string>

#include <vector>
#include <cstring>

//For Solution with thread -> needs while Loop 
void getCharWithoutEnterVoid();

//For "Seperating"/"Parsing" the String-Input
std::vector<std::string> seperateString(std::string toSeperate, const char *seperator);

class GUI {
    private:
//        static std::unique_ptr<GUI_Controller> controller; 

        static std::vector<ButtonGroup*> buttonGroups;

        //****
        // Definition of Template Function has to be in Header File
        //****
        template<typename ptr>
        static bool evaluate(std::string instruction, ptr connectedVar) {
            std::vector<std::string> seperatedInput = seperateString(instruction, gui_config::inputSeperation);

            // Has to have at least one Argument (Description of what is to be added)
            if(seperatedInput.size() < 1) throw InputParsingError("Wrong Number of Input Arguments in Parsing the Input!");
            // Allows currently for single Inputs like 's' and double Inputs like 'bg'
            if(seperatedInput[0].size() != 1 && seperatedInput[0].size() != 2) throw InputParsingError("Wrong size of first input Argument!");

            // Case Slider -> Needs to have 4 different Parts -> 's' + 'length' + 'min' + 'text'
            if(seperatedInput[0] == "s") {
                //Currently dereferencing as reference were used instead of Sliders -> TODO Change
                controller->addElement(new Slider(*connectedVar, std::stoi(seperatedInput[2]), std::stoi(seperatedInput[3]), seperatedInput[1])); 
            }

            /*** Currently Not yet Working ***/
            /*
            // Case Button -> Needs to have 2 different Parts -> 'b' + 'Text'
            if(seperatedInput[0] == "b") {
                controller->addElement(new Button(*connectedVar, seperatedInput[1])); 
            }

            // Case Button-Group -> Needs to have 3 different Parts -> 'bg' + 'id' + 'text'
            if(seperatedInput[0] == "bg") {
                // Only create new Button Group if necessary -> Maybe hash or Map to see if "Index" already created -> Currently test 
                if(buttonGroups.size() == 0) {
                    buttonGroups.emplace_back(new ButtonGroup());
                    controller->addElement(buttonGroups[0]);
                }
                buttonGroups[0]->addButton(new Button(*connectedVar, seperatedInput[1]));
            }
            */
        };
    public:
    //TODO MOVE TO PRIVATE
           static std::unique_ptr<GUI_Controller> controller; 
        //****
        // Definition of Template Function has to be in Header File
        //****
        template<typename ptr, typename... Args>
        static void addElements(std::string instruction, ptr* connectedVar, Args... arguments) {
            evaluate(instruction, connectedVar);
            // Recursivly calls function again if enough elements are still in Parameter-list
            if constexpr(sizeof...(arguments) > 1) {
                addElements(arguments...);
            }
        }

        static void startGUI();

        GUI() = delete;
};

#endif