#include "main.h"

int main(int argc, char** argv) {
    mouseDataProcessor();
    return 0;
}

//The method that will be reading and interpreting the mice file, which is a recording of all inputs given by all mouses that can connect to the system.
void mouseDataProcessor() {
    //Opens the file, it is opened in read only mode to not give the program any authority to modify the log. In exceptional cases it may cause unwanted disruption to the input feed.
    int file = open("/dev/input/mice", O_RDONLY);

    //Initializes a size 3 signed char array to store the significant parts of the mice file. It is imperative to store them as signed chars, to ensure all movements in the coordinate plane are represented.
    signed char fileData[3];
    
    int xCoordinate = 0;
    int yCoordinate = 0;
    
    while (1) {
        //Reads the contents, and stores the first three bytes in fileData.
        read(file, fileData, 3);

        //Updates the coordinates with the new inputs. Char at 1 represents movement in the x-axis whereas 2 represents movement in the y-axis.
        xCoordinate += fileData[1];
        yCoordinate += fileData[2];

        //Outputs the new coordinates in (x,y) format.
        printf("(%d,%d)\n", xCoordinate, yCoordinate);
    }
}

