# ConsoleGUI

Project to write a simple, universal console GUI for providing Sliders, Buttons etc. to change Parameters for any C++ Program in realtime.

![image](https://github.com/BerniSc/ConsoleGUI/assets/117440705/e3db5b00-819a-4c67-92f0-51fe1812a25e)

The selected Row can be changed by pressing 'w' for up or 's' for down. The value can be changed (single) by 'a' or 'd' or bulk-wise by 'A' or 'D' and toggled by Space.
The GUI Application is closed by pressing 'q'.<br>
In the specific case of the Button-Group the values can be changed by 'a', 'd' or Space and the selected Button is switched by 'A' and 'D'.<br> 

The Idea is that for example the GUI is put before the acutal programm or in specified parts of the actual programm that allow for the changing of Parameters.<br>

To add Values that can be changed the Folder GUI has to be in the same directory and then the header GUI/gui.hpp has to be included.<br>
After that values can be added to the GUI by calling GUI::addElements(). This Function always takes as many elements as the User wants to add, as long as they come in pairs. These pairs always consist of a String that describes what the Element looks like and how it behaves in the GUI and then the Variable that is to be changed.

The Syntax for the Description-Strings is hereby (in this example it is assumed that the default value for the seperation charactes has not been changed. This could be done via the gui_config header). The Values with the Questionmarks do not apply for every element and are therefore not always expected:
**<br><br>&ensp;\<IDENTIFIER>#\<?POSITION?>#\<TEXT>#\<?SIZE?>#\<?STARTVALUE?>**

Examples:
- Slider: "s#\<Text>#\<Size>#\<Startvalue>"&ensp;&ensp;&ensp;-> **Identifier "s"**
- Button: "b#\<Text>"&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;-> **Identifier "b"**
- Button-Group: "bg#\<Position>#\<Text>"&ensp;&ensp;&ensp;&ensp;-> **Identifier "bg"**

  For the Button Group the "Position" of the Button-group is passed and after that just the parameters for a regular Button. The GUI adds this button automaticly to the respective Group.<br><br>
   
![CGUI_Config_Demo](https://github.com/BerniSc/ConsoleGUI/assets/117440705/b7e98377-745b-467e-a53a-8f42b16713da)

<br>This is an exemplary configuration/use of the C-GUI. This example here is for configuring the image displayed on Top.<br>

Calling the GUI::startGUI() function blocks the calling thread, until the GUI is ended. Then the calling thread can run until the GUI::startGUI() function is called again.<br>

An Example for the Implementation of the GUI can be seen in the "main.cpp" Function.<br><br><br>

TODO-List for now:
- learn how to write GitHub Readme's
- Actually implement Text-Elements (like Output and Input Fields)
- Add Features like editing GUI-List and Removing Elements
- Ensure minimum Length for Button-Group Elements and Element-sizes in general
- Hunt down Bug with selecting Element
