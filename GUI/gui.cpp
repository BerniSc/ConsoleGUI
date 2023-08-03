#include "gui.hpp"

std::unique_ptr<GUI_Controller> GUI::controller = std::unique_ptr<GUI_Controller>(new GUI_Controller("GUI Controller"));
std::vector<ButtonGroup*> GUI::buttonGroups = {};

static std::mutex inputMutex;
static char input = '#';

static std::mutex stopMutex;
static bool stop = false;

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

std::vector<std::string> seperateString(std::string toSeperate, const char *seperator) {
    std::vector<std::string> result;

    char* dataAsPointer = &toSeperate[0];
    char* token = strtok(dataAsPointer, seperator);
    result.push_back(token);
    
    while(token != NULL) {
        token = strtok(NULL, seperator);
        if(token != NULL) result.push_back(token);
    }
    
    return result;
}

// Function for starting the GUI
// Blocks calling thread until it is terminated
// Safe to be called multiple Times
void GUI::startGUI() {
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
        // Down means going up with reagard to IDs
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
        case 'p' :
            controller->printGUI();
            input = '#';
            break;
        case '#' :
            controller->printGUI();
            break;
        }
    }
    inputThread.join();
    stop = false;
    return;
}