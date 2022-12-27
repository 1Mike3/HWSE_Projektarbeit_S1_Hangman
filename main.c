#include <stdio.h>

/*  #### General Programm Information ####
  -Created by: Michal Kuc 27.12.2022
  -Project HWSE WS22
  -Hangman Game with visualisation, user input and data logging

  -I added Debug-Helpers in the source code: #if DEBUG segments are irrelevant for the programs functionality
 */

//Including of project-related Header-Files
#include "dataLogging.h"
#include "gameImplementation.h"
#include "userInput.h"

//Including of external Header-Files


//Debugging Helpers
#define DEBUG1 0 //TestPrint argc argv
#define DEBUG2 0
#define DEBUG3 0

int main(int argc, char **argv) {

#if DEBUG1
    //printf("Hello World");
    //Test Print the User Input
    //!!remember standard argument set in clion, first arg filepath for some reason
    for(int i=0; i<argc; i++) {
        printf("\"%s\"\n", argv[i]);
        }
#endif

    //#### Core Elements ####
    //the central and most often Used Elements which will be used throughout the Program will be initialised here
    char *userInput;

    //### Program start ###
    startSequence();

    return 0;
}
