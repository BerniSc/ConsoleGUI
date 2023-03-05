#ifndef GUI_HPP
#define GUI_HPP

#include "gui_controller.hpp"
#include "button_group.hpp"
#include "slider.hpp"

#include <unistd.h>
#include <termios.h>
#include <mutex>

static std::mutex inputMutex;
static char input = '#';

static std::mutex stopMutex;
static bool stop = false;

//For Solution with thread -> needs while Loop 
void getCharWithoutEnterVoid() {
    while(!stop) {
        char buffer = 0;
        struct termios old = {0};
        if(tcgetattr(0, &old) < 0) perror("tcsetattr()");
        //Disable canonical Mode
        //Supress Echo
        old.c_lflag &= ~ICANON;
        old.c_lflag &= ~ECHO;
        old.c_cc[VMIN] = 1;
        old.c_cc[VTIME] = 0;
        if(tcsetattr(0, TCSANOW, &old) < 0) perror("tcsetattr ICANONO");
        //Read Char
        if(read(0, &buffer, 1) < 0) perror("read()");
        //Reset Changes
        old.c_lflag |= ICANON;
        old.c_lflag |= ECHO;
        if(tcsetattr(0, TCSADRAIN, &old) < 0) perror("tcsetattr ~ICANON");
        //return Char
        inputMutex.lock();
        input = buffer;
        inputMutex.unlock();
    }
}


struct GUI {
    static std::unique_ptr<GUI_Controller> controller; 

    static void startGUI() {
        std::thread inputThread(getCharWithoutEnterVoid); 

        char inputDummy;
        //test.printGUI();
        while(!stop) {
            inputDummy = input;
            switch(inputDummy) {
            case 'q' :
                stop = !stop;
                input = '#';
                break;
            //Move single number left
            case 'a' :
                controller->changeCurrentElement(gui_config::down);
                input = '#';
                break;
            //Move Large Chunck left -> (10 %)
            case 'A' :
                controller->changeCurrentElementBulk(gui_config::down);
                input = '#';
                break;
            //Move single number right
            case 'd' :
                controller->changeCurrentElement(gui_config::up);
                input = '#';
                break;
            //Move Large Chunk right -> (10 %)
            case 'D' :
                controller->changeCurrentElementBulk(gui_config::up);
                input = '#';
                break;
            //Switch selected Slider Up
            case 'w' :
                controller->switchElement(gui_config::down);
                input = '#';
                break;
            //Switch selected Slider Down
            case 's' :
                controller->switchElement(gui_config::up);
                input = '#';
                break;
            case ' ' :
                controller->toggleCurrentElement();
                input = '#';
                break;
            //Default Value
            case '#' :
                controller->printGUI();
                break;
            /*case 'i' :
                test_controller.printGUI();
                input = '#';
                break;*/
            }
            //test_controller.printGUI();

            //std::this_thread::sleep_for(std::chrono::milliseconds(250));
        }

        inputThread.join();

        return;
    }

    
};

std::unique_ptr<GUI_Controller> GUI::controller = std::unique_ptr<GUI_Controller>(new GUI_Controller("GUI Controller"));

#endif