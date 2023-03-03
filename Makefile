COMPILER = g++
PROJECTNAME = gui
SOURCES = gui.cpp gui_element.cpp gui_controller.cpp slider.cpp
FLAGS = -Wall -std=c++17 -pthread

$(PROJECTNAME) : $(SOURCES)
		$(COMPILER) $(SOURCES) $(FLAGS) -o $(PROJECTNAME)