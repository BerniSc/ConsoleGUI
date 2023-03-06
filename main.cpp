#include "GUI/gui.hpp"

int main() {
    int test_var_1 = 0;
    int test_var_2 = 0;
    int test_var_3 = 0;
    int test_var_4 = 0;

    bool test_var_5 = false;
    
    GUI::controller->addElement(new Slider(test_var_1, 10, -5, "test_1"));
    GUI::controller->addElement(new Slider(test_var_2, 50, 0, "test_2"));
    GUI::controller->addElement(new Slider(test_var_3, 100, 0, "test_3"));
    GUI::controller->addElement(new Slider(test_var_4, 10, 0, "test_4"));
    
    ButtonGroup *bg = new ButtonGroup();
    bg->addButton(new Button(test_var_5, "Test3"));
    bg->addButton(new Button(test_var_5, "Test2"));
    bg->addButton(new Button(test_var_5, "Test1"));
    bg->addButton(new Button(test_var_5, "Sizing Test 0"));
    GUI::controller->addElement(bg);

    GUI::controller->addElement(new Slider(test_var_4, 10, 0, "test_5"));

    std::thread GUI_thread(GUI::startGUI);
    GUI_thread.join();

    std::cout << "STARTING REAL PROGRAMM NOWWW with " << test_var_1 << "|" << test_var_2 << "|" << test_var_3 << "|" << test_var_4 << "|" << test_var_5 << std::endl;

    return 1;
}