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

static std::mutex inputMutex;
static char input = '#';

static std::mutex stopMutex;
static bool stop = false;

//For Solution with thread -> needs while Loop 
static void getCharWithoutEnterVoid();

//For "Seperating"/"Parsing" the String-Input
static std::vector<std::string>& seperateString(std::string toSeperate, const char *seperator);

class GUI {
    private:
        static std::unique_ptr<GUI_Controller> controller; 

        template<typename ptr>
        bool evaluate(std::string, ptr*);
    public:
        template<typename ptr, typename... Args>
        static void addElements(std::string, ptr*, Args... arguments);

        static void startGUI();

        GUI() = delete;
};

std::unique_ptr<GUI_Controller> GUI::controller = std::unique_ptr<GUI_Controller>(new GUI_Controller("GUI Controller"));

#endif