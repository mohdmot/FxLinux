<p align="center">
<img src="https://raw.githubusercontent.com/mohdmot/FxLinux/main/logo.png" width="470"></img>
</p>


**FxLinux** is a mini Linux emulator program that runs on the **fx-9860** series. It contains a terminal similar to Linux systems and takes input from the buttons in the same way as input from the rest of the calculator add-ins.

The program contains some commands in the **F1-F6** buttons, which are :

```
F1:   It cleans the terminal of all contents
F2:   Switch between uppercase and lowercase letters
F3:   It shows you the commands available in the system
F6:   Stops the program/add-in
```

The program is a Linux emulator, So of course there will be text commands that you can use and interact with the system with, which are :

```
help:      It shows you the commands available in the system
exit:      Stops the program/add-in
shutdown:  Same thing as exit
clear:     It cleans the terminal of all contents
ls:        Display files and folders in the current path
cat:       Print the content of a specified file
uname:     Print system information
echo:      Print text in the terminal
cd:        Change the current path
rm:        Delete a specified file
rmdir:     Delete a specified folder
sleep:     Stop the system for several seconds
pwd:       Print the current path
touch:     Create an empty file
mkdir:     Make a folder
bash:      Run a bash script file for FX Linux. You can write the same terminal 
./ :         commands inside the file and then run it.
```


This program is the first program I wrote in the C language and also the first program I wrote for a calculator, so there are some strange errors. For example, the addin crash sometimes when using some commands such as : *mkdir, rmdir, cat , etc..* ( after they are executed)

Also, dealing with paths is a bit clumsy, so make sure you are in the right place to point to a specific file or folder.
