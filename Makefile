COMPILER = g++
PROJECTNAME = gui
SOURCES = main.cpp GUI/gui_exceptions.cpp GUI/gui.cpp GUI/Elements/gui_element.cpp GUI/gui_controller.cpp GUI/Elements/slider.cpp GUI/Elements/button.cpp GUI/Elements/button_group.cpp GUI/Elements/text_element.cpp
SOURCES_TEST = gui.cpp gui_element.cpp gui_controller.cpp slider.cpp button.cpp button_group.cpp text_element.cpp
FLAGS = -Wall -std=c++17 -pthread

$(PROJECTNAME) : $(SOURCES)
		$(COMPILER) $(SOURCES) $(FLAGS) -o $(PROJECTNAME)