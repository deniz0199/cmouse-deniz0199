# cmouse-deniz0199
### Introduction
cmouse is a simple tool that outputs the relative changes in mouse input periodically. It uses the mice log found in /dev/input in order to calculate the changes.

### Instructions
The program can simply be run on any terminal on Ubuntu computers. The mouse inputs can then be tracked within the terminal. However, in special cases where the user's mice logs are not found in /dev/input, users may need to modify the address of mice in the code to suit their needs.

### Safety concerns
The program cannot modify the mice or any other files found in the computer, as its access is read only. However, it would be best if it isn't run in conjunction with programs with heavy loads, as so long as the task isn't forcefully killed, the programme will keep listening for changes in mice and rapidly outputing new information, consuming some system resources.
