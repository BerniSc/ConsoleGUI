COMPILER = g++
PROJECTNAME = gui
SOURCES = main.cpp gui_element.cpp gui_controller.cpp slider.cpp button.cpp button_group.cpp
SOURCES_TEST = gui.cpp gui_element.cpp gui_controller.cpp slider.cpp button.cpp button_group.cpp
FLAGS = -Wall -std=c++17 -pthread

$(PROJECTNAME) : $(SOURCES)
		$(COMPILER) $(SOURCES) $(FLAGS) -o $(PROJECTNAME)