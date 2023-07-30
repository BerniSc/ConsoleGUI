#include "GUI/gui.hpp"

int main() {
    int test_var_1 = 0;
    int test_var_2 = 0;
    int test_var_3 = 0;
    int test_var_4 = 0;

    bool test_var_5 = false;
    bool test_var_6 = false;
    
    //GUI::controller->addElement(new Slider(test_var_1, 10, -5, "test_1"));
    //GUI::controller->addElement(new Slider(test_var_2, 50, 0, "test_2"));
    //GUI::controller->addElement(new Slider(test_var_3, 100, 0, "test_3"));
    //GUI::controller->addElement(new Slider(test_var_4, 10, 0, "test_4"));
    
    //ButtonGroup *bg = new ButtonGroup();
    //bg->addButton(new Button(test_var_5, "Test3"));
    //bg->addButton(new Button(test_var_6, "Test2"));
    //bg->addButton(new Button(test_var_5, "Test1"));
    //bg->addButton(new Button(test_var_5, "Sizing Test 0"));
    //GUI::controller->addElement(bg);
    //delete bg;

    //GUI::controller->addElement(new Slider(test_var_4, 10, 0, "test_5"));

    //std::thread GUI_thread(GUI::startGUI);
    //GUI_thread.join();

    GUI::controller->addElement(new Button(test_var_5, std::string("Hi")));
    //ButtonGroup* bg = new ButtonGroup();
    //bg->addButton(new Button(test_var_5,"Rolf"));
    //bg->addButton(new Button(test_var_6,"Ralf"));
    //GUI::controller->addElement(bg);

    std::string s = "hi";

    GUI::addElements("s#Hi#10#0", &test_var_1, "s#Hi2#20#-10", &test_var_2);

    GUI::startGUI();

    std::cout << "STARTING REAL PROGRAMM NOWWW with " << test_var_1 << "|" << test_var_2 << "|" << test_var_3 << "|" << test_var_4 << "|" << test_var_5 << std::endl;

    return 1;
}