#include "gui.hpp"

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

std::vector<std::string>& seperateString(std::string toSeperate, const char *seperator) {
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

template<typename ptr, typename... Args>
void GUI::addElements(std::string instruction, ptr* connectedVar, Args... arguments) {
    evaluate(instruction connectedVar);

    // Recursivly calls function again if enough elements are still in Parameter-list
    if constexpr(sizeof...(arguments) > 1) {
        addElements(arguments...);
    }
}

template<typename ptr>
bool GUI::evaluate(std::string instruction, ptr* connectedVar) {
    std::vector<std::string> seperatedInput = seperateString(instruction, gui_config::inputSeperation);

    // Has to have at least one Argument (Description of what is to be added)
    if(seperatedInput.size() < 1) throw InputParsingError("Wrong Number of Input Arguments in Parsing the Input!");
    // Allows currently for single Inputs like 's' and double Inputs like 'bg'
    if(seperatedInput[0].size() != 1 && seperatedInput[0].size() != 2) throw InputParsingError("Wrong size of first input Argument!")

    switch(seperatedInput[0]) {
        // Case Slider -> Needs to have 4 different Parts -> 's' + 'length' + 'min' + 'text'
        case "s":
            controller->addElement(new Slider(connectedVar, int(seperatedInput[2]), int(seperatedInput[3]), seperatedInput[1]));
            break;
        case 
    }
};

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
        case '#' :
            controller->printGUI();
            break;
        }
    }
    inputThread.join();
    return;
}