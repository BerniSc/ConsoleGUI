/*
    DEPRECATED
    FOR TESTING PURPOSES ONLY
*/


/*
#include "gui_controller.hpp"
#include "gui_element.hpp"
#include "slider.hpp"
#include "button_group.hpp"

#include <unistd.h>
#include <termios.h>
#include <mutex>

static std::mutex inputMutex;
static char input = ' ';

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

int main(int argc, char *argv[]) {
    // Starting simple GUI Controller for testing
    GUI_Controller test_controller("Test Controller");
    int test_var_1 = 0;
    int test_var_2 = 0;
    int test_var_3 = 0;
    int test_var_4 = 0;
    test_controller.addElement(new Slider(test_var_1, 10, -5, "test_1"));
    test_controller.addElement(new Slider(test_var_2, 50, 0, "test_2"));
    test_controller.addElement(new Slider(test_var_3, 100, 0, "test_3"));
    test_controller.addElement(new Slider(test_var_4, 10, 0, "test_4"));
    
    bool test_var_5 = false;
    ButtonGroup *bg = new ButtonGroup();
    bg->addButton(new Button(test_var_5, "Test3"));
    bg->addButton(new Button(test_var_5, "Test2"));
    bg->addButton(new Button(test_var_5, "Test1"));
    bg->addButton(new Button(test_var_5, "Sizing Test 0"));
    test_controller.addElement(bg);

    test_controller.addElement(new Slider(test_var_4, 10, 0, "test_5"));

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
            test_controller.changeCurrentElement(gui_config::down);
            input = '#';
            break;
        //Move Large Chunck left -> (10 %)
        case 'A' :
            test_controller.changeCurrentElementBulk(gui_config::down);
            input = '#';
            break;
        //Move single number right
        case 'd' :
            test_controller.changeCurrentElement(gui_config::up);
            input = '#';
            break;
        //Move Large Chunk right -> (10 %)
        case 'D' :
            test_controller.changeCurrentElementBulk(gui_config::up);
            input = '#';
            break;
        //Switch selected Slider Up
        case 'w' :
            test_controller.switchElement(gui_config::down);
            input = '#';
            break;
        //Switch selected Slider Down
        case 's' :
            test_controller.switchElement(gui_config::up);
            input = '#';
            break;
        case ' ' :
            test_controller.toggleCurrentElement();
            input = '#';
            break;
        //Default Value
        case '#' :
            test_controller.printGUI();
            break;
        //case 'i' :
        //    test_controller.printGUI();
        //    input = '#';
        //    break;
        }
        //test_controller.printGUI();

        //std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }

    inputThread.join();

    return 0;
} 
*/