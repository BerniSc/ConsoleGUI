#include "gui_controller.hpp"
#include "gui_element.hpp"
#include "slider.hpp"

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
    GUI_Controller test("Hi");
    int test1 = 0;
    int test2 = 0;
    //Slider *s1 = new Slider(test1);
    //Slider *s2 = new Slider(test2);
    //std::cout << s1 << std::endl;
    //std::cout << s2 << std::endl;
    //test.addElement(s1);
    test.addElement(new Slider(test1));
    test.addElement(new Slider(test2));

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
        case 'a' :
            test.changeCurrentElement(gui_config::down);
            input = '#';
            break;
        case 'd' :
            test.changeCurrentElement(gui_config::up);
            input = '#';
            break;
        case 'w' :
            test.switchElement(gui_config::down);
            input = '#';
            break;
        case 's' :
            test.switchElement(gui_config::up);
            input = '#';
            break;
        case '#' :
            break;
        default:
            test.printGUI();
            break;
        }
        test.printGUI();

        //std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }

    inputThread.join();

    return 0;
} 