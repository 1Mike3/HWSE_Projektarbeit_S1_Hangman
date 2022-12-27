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
#include "errorManagement.h"

//Including of external Header-Files

//Debugging Helpers
#define DEBUG1 1 //TestPrint argc argv
//#define DEBUG2 0
//#define DEBUG3 0

int main(int argc, char **argv){



    //#### Core Elements ####
    //the central and most often Used Elements which will be used throughout the Program will be initialised here
    char *userInput = "0";

    //### Program start ###
    int bufferStartSequenceValue = startSequence();//execute the start sequence and proceed depending on it's ret val.
    switch (bufferStartSequenceValue) {
        case 0: //the user has selected to run the Programm

            commLineArgManagement(argc,argv);

            break;


            //#### Edge cases and abort behavior ####
        case 1://the user has selected to abort the programm
            printf("the program has been stopped by the user.\n");
            return 0;
        case 2://Return value of start sequence signals there has been an error in its function
            errorManagement(startSequenceRet);
            return startSequenceRet;

        default://undefined return error behavior
            errorManagement(startSequenceDef);
            return startSequenceDef;

    }
    return 0;
}

//all the todos
//TODO change errorManagement() to write to Error log
