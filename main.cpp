#include "GUI/gui.hpp"

#include <chrono>
#include <thread>

int main() {
    int test_var_1 = 0;
    int test_var_2 = 0;
    int test_var_3 = 0;

    bool test_var_4 = false;
    bool test_var_5 = false;
    bool test_var_6 = false;

    // Initialise GUI with Elements -> These will be displayed later    
    GUI::addElements("s#Slider 1#10#0", &test_var_1, \
                     "s#My Second Slider#20#-10", &test_var_2, \
                     "b#My Single Button", &test_var_4, \
                     "bg#1#1st Button-Group Element", &test_var_4, \
                     "bg#1#second Button", &test_var_5, \
                     "bg#1#third ", &test_var_6, \
                     "s#My Last Slider#50#0", &test_var_3);

    // Start the GUI with the configured Elements
    // GUI blocks calling thread until it is terminated
    GUI::startGUI();

    // Adding Elements also works later 
    GUI::addElements("b#This Button was Added Later...", &test_var_6);

    using namespace std::chrono_literals;

    // Other Code using the configured Elements...
    while(true) {
        static int i = 0;
        std::this_thread::sleep_for(1000ms);
        std::cout << "Important Function from other part of Code Nr. " << i << "..." << std::endl;
        if(++i == 10) break;
    }

    // Start GUI again...
    GUI::startGUI();

    return 0;
}