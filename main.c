#include <stdio.h>

/*  #### General Programm Information ####
  -Created by: Michal Kuc 27.12.2022
  -Project HWSE WS22
  -Hangman Game with visualisation, user input and data logging

  -I added Debug-Helpers in the source code: #if DEBUG segments are irrelevant for the programs functionality

  -convert to Uppercase functions in helperFunctions.c
 */

//Including of project-related Header-Files
#include "dataLogging.h"
#include "gameImplementation.h"
#include "userInput.h"
#include "errorManagement.h"

//Including of external Header-Files
#include <string.h>

//Debugging Helpers
#define DEBUG1 0 //TestPrint argc argv
//#define DEBUG2 0
//#define DEBUG3 0



int main(int argc, char **argv){
//Error Messages
    errorStruct EEStartSequenceReturn  = {
            .code = ERStartSequenceRet,
            .message = "start sequence returned a value it should not return during normal operation (2)"
    };
    errorStruct EEStartSequenceDefault = {
            .code = ERStartSequenceDef,
            .message = "default of switch-case after start sequence"
    };
    errorStruct EECommandLineArgumentFunctionFailed = {
            .code =  ERComLineArgManagementFailed,
            .message = "The ComLineArgManagement function has returned an error"
    };
    errorStruct EEGameRuntimeFailed= {
            .code = ERGameRuntimeFunctionFailed,
            .message = "An Error or Warning has caused the gameRuntime function to fail!"
    };

#if DEBUG1
    printf("°No of argc: %i\n", argc);
#endif

    //#### Core Elements ####
    //the central and most often Used Elements which will be used throughout the Program will be initialised here
    char *activeWord; //the Word which will be used to play the game (comm line arg || user input)



    do { //main loop to let the user run the Game multiple times

    //      ###         Program         start ###
    int bufferStartSequenceValue = startSequence();//execute the start sequence and proceed depending on it's ret val.

    //switch-case to interpret the return Value of the StartSequence
    switch (bufferStartSequenceValue) {

//               #### Hangman Game Active ####
        case 0: //the user has selected to run the Programm
            activeWord = commLineArgManagement(argc, argv); //assign the activeWord from the commLineArg Function

            //Error handling of the commLineArgManagement Function
            //finishing with 104 is on purpose
            int tempCompareValue = 1;
            tempCompareValue = strcmp(activeWord, "#ERROR");
            if (tempCompareValue == 0) { //error handling
                errorManagement(EECommandLineArgumentFunctionFailed, ERROR);
                return ERComLineArgManagementFailed;
            }

            // #### Start game Sequence ####
            int returnGameRuntime = gameRuntime(activeWord);
            if (returnGameRuntime == gameRuntimeError || returnGameRuntime == gameUnpredictedBehavior) {
                errorManagement(EEGameRuntimeFailed, ERROR);
                return ERGameRuntimeFunctionFailed;
            }


            break; //break case 0
            //   #### END Hangman Game Active ####


            //#### Edge cases and abort behavior ####

        case 1://the user has selected to abort the programm
            printf("the program has been stopped by the user.\n");
            return 0;
        case 2://Return value of start sequence signals there has been an error in its function
            errorManagement(EEStartSequenceReturn, ERROR);
            return ERStartSequenceRet;


        default://undefined return error behavior
            errorManagement(EEStartSequenceDefault, ERROR);
            return ERStartSequenceDef;
    }//End switch case start sequence Return

    }  while (1); //end of the loop which lets the user play multiple times
    return 0;
}

//all the todos
//TODO !!before final version set all DEBUG to 0!!

//TODO change errorManagement() to write to Error log (add or change)


//!!
//TODO check malloc function & small functions file

