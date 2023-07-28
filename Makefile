COMPILER = g++
PROJECTNAME = gui
SOURCES = main.cpp GUI/gui_element.cpp GUI/gui_controller.cpp GUI/slider.cpp GUI/button.cpp GUI/button_group.cpp GUI/text_element.cpp
SOURCES_TEST = gui.cpp gui_element.cpp gui_controller.cpp slider.cpp button.cpp button_group.cpp text_element.cpp
FLAGS = -Wall -std=c++17 -pthread

$(PROJECTNAME) : $(SOURCES)
		$(COMPILER) $(SOURCES) $(FLAGS) -o $(PROJECTNAME)