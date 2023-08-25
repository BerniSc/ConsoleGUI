# Compiler used for Compiling the C++ Project
COMPILER = g++
# Sources only for the actual GUI
SOURCES_GUI = GUI/gui_exceptions.cpp GUI/gui.cpp GUI/Elements/gui_element.cpp GUI/gui_controller.cpp GUI/Elements/slider.cpp GUI/Elements/button.cpp GUI/Elements/button_group.cpp GUI/Elements/text_element.cpp
# Sources of GUI Combined with sources of other Project -> Embedding own Sources directly in GUI Project
SOURCES_COMBINED = $(SOURCES_GUI) main.cpp
# Flags for every Compilation
FLAGS = -Wall -std=c++17 -pthread
# Flags for Compiling as LIB
LIB_FLAGS = $(FLAGS) -fPIC

# Name of the Project/Executable if compiled with sources embedded in other Project 
PROJECTNAME = gui

# List of the all the sources as object files
OBJECTS_LIB = $(SOURCES_GUI:.cpp=.o)

# Library Name = Console-GUI.so
LIBNAME = cguilib.so

# default Target -> GUI with Source-Code fully embedded into own project
$(PROJECTNAME) : $(SOURCES_COMBINED)
		$(COMPILER) $(SOURCES_COMBINED) $(FLAGS) -o $(PROJECTNAME)

# Target for library
lib : $(OBJECTS_LIB)
		$(COMPILER) -shared -o $(LIBNAME) $(OBJECTS_LIB)

# Compiling each of the Sourcefiles as .o files in case of Library-Creation 
%.o: %.cpp
		$(COMPILER) $(LIB_FLAGS) -c $< -o $@

# Clean all the Artifacts from all Build Options
clean: clean_lib clean_prj

# Clean Lib-building Artifacts
clean_lib:
		rm -f $(OBJECTS_LIB) $(LIBNAME)

# Clean Project-building Artifacts
clean_prj:
		rm -f $(PROJECTNAME)