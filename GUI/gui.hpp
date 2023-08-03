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

#include <type_traits>

#include <vector>
#include <cstring>

//For Solution with thread -> needs while Loop 
void getCharWithoutEnterVoid();

//For "Seperating"/"Parsing" the String-Input
std::vector<std::string> seperateString(std::string toSeperate, const char *seperator);

class GUI {
    private:
        static std::unique_ptr<GUI_Controller> controller; 

        static std::vector<ButtonGroup*> buttonGroups;

        //****
        // Definition of Template Function has to be in Header File
        //****
        template<typename ptr>
        static bool evaluate(std::string instruction, ptr* connectedVar) {
            std::vector<std::string> seperatedInput = seperateString(instruction, gui_config::inputSeperation);

            // Has to have at least one Argument (Description of what is to be added)
            if(seperatedInput.size() < 1) throw InputParsingError("Wrong Number of Input Arguments in Parsing the Input!");
            // Allows currently for single Inputs like 's' and double Inputs like 'bg'
            if(seperatedInput[0].size() != 1 && seperatedInput[0].size() != 2) throw InputParsingError("Wrong size of first input Argument!");

            // Case Slider -> Needs to have 4 different Parts -> 's' + 'length' + 'min' + 'text'
            if(seperatedInput[0] == "s") {
                // Only Accepts Parameters of type int -> Otherwise C++ tries to compile with add Slider(...*bool) -> Error
                if constexpr(std::is_same_v<ptr, int>) {
                    //Currently dereferencing as reference were used instead of Sliders -> TODO Change
                    controller->addElement(new Slider(connectedVar, std::stoi(seperatedInput[2]), std::stoi(seperatedInput[3]), seperatedInput[1])); 
                }
            }

            /*** Currently Not yet Working ***/
            
            // Case Button -> Needs to have 2 different Parts -> 'b' + 'Text'
            if(seperatedInput[0] == "b") {
                if constexpr(std::is_same_v<ptr, bool>) {
                    controller->addElement(new Button(connectedVar, seperatedInput[1])); 
                }
            }

            // Case Button-Group -> Needs to have 3 different Parts -> 'bg' + 'id' + 'text'
            if(seperatedInput[0] == "bg") {
                // Only create new Button Group if necessary -> Maybe hash or Map to see if "Index" already
                // Getting int from second Input-Parameter -> stoi throws Error if argument was not parsable 
                int index = stoi(seperatedInput[1]);
                static int prevMax = 0;
                std::cout << index << std::endl;
                // Compiletime-evaluation of Template Parameter -> Does not try to call wrong functions
                if constexpr(std::is_same_v<ptr, bool>) {
                    // Return an Error if Index is Negativ or over the currently possible amount of creatable/created Buttongroups
                    // Must also check wheter index is at 1 because of shorthand evaluation -> calling size() if buttonGroups has no elements results in segfault
                    if(index < 0 || (index - 1 > prevMax)) throw InputParsingError("Wrong Index-Number in entering Button-Group ID!");
                    // If Index is just one Element "Out of Bounds", create new Buttongroup and Add it
                    if(index - 1 == prevMax) {
                        std::cout << index << "     " << buttonGroups.size() << std::endl; 
                        buttonGroups.emplace_back(new ButtonGroup());
                        controller->addElement(buttonGroups[(prevMax = index) - 1]);
                    }
                    buttonGroups[index - 1]->addButton(connectedVar, seperatedInput[2]);
                }
            }
            
        };
    public:
    //TODO MOVE TO PRIVATE
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