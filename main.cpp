#include "GUI/gui.hpp"

#include <chrono>
#include <thread>

int main() {
    int test_var_1 = 0;
    int test_var_2 = 0;
    int test_var_3 = 0;
    int test_var_4 = 0;

    bool test_var_5 = false;
    bool test_var_6 = false;
    
    GUI::addElements("s#Hi#10#0", &test_var_1, \
                     "s#Hi2#20#-10", &test_var_2, \
                     "b#JUHUU", &test_var_6, \
                     "bg#1#Hi", &test_var_5, \
                     "bg#1#MOIN", &test_var_6, \
                     "bg#1#MOINsen", &test_var_6);

    GUI::startGUI();

    //getchar();
    std::cout << "\033[2J\033[1;1H" << std::endl;
    std::cout << "\033[2J\033[1;1H";
    std::cout << "\033[2J\033[1;1H";

    using namespace std::chrono_literals;

    std::this_thread::sleep_for(1000ms);
    std::cout << "\033[2J\033[1;1H";
    std::this_thread::sleep_for(5000ms);
    std::cout << "hii" << std::endl;

    //GUI::startGUI();
    while(true) {
        std::this_thread::sleep_for(1000ms);
        std::cout << "HIII" << std::endl;
    }

    std::cout << "STARTING REAL PROGRAMM NOWWW with " << test_var_1 << "|" << test_var_2 << "|" << test_var_3 << "|" << test_var_4 << "|" << test_var_5 << std::endl;

    return 1;
}