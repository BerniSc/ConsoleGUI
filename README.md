# ConsoleGUI

Project to write a simple, universal console GUI for providing Sliders, Buttons etc. to change Parameters in realtime.

![grafik](https://user-images.githubusercontent.com/117440705/222965222-8162ed73-1dd7-4da4-b438-814d7894eadd.png)

The selected Row can be changed by pressing 'w' for up or 's' for down. The value can be changed (single) by 'a' or 'd' or bulk-wise by 'A' or 'D' and toggled by Space.
The GUI Application is closed by pressing 'q'.

The Idea is that for example the GUI is put before the real programm an the parameters are added. After selecting the desired Value the GUI can be exited by pressing 'q' and the real programm can Load.

![grafik](https://user-images.githubusercontent.com/117440705/222965645-2cd1bfc6-cdfc-4682-9238-9cd7e7263870.png)

Elements can be Added like this:
Creating new Controller and adding Elements per the add-element function. Sliders take in min-Value, Size, description and their Variable, Buttons just their description and their Variable.
