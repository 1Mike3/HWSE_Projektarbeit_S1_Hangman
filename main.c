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
#include "wordInputFile.h"
#include "helperFunctions.h"


//Including of external Header-Files
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> //for get-opt


//Debugging Helpers
#define DEBUG1 0 //TestPrint argc argv



int main(int argc, char **argv){

   // system("./Hangman_Helper_Script.sh");


    //initialize random number generator
   time_t t;
   srand((unsigned) time(&t));

   //Print Manual
   printManualInFileOnStartup();

#if 0 //debug random number generator
    int r;
    for (int i = 0; i < 20; ++i) {
       r = generateRandomNumber(2);
        printf("%i\n", r);
    }
#endif

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
    errorStruct EENoInputDetectedFile = {
            .code = ERNoUserInputDetectedFile ,
            .message = "No Available Guess-Word in WordFile, Game is shutting Down!"
    };

    //game Runtime Constants: (will be changed when new function available)
    //!!i won't include a check so only one is active so just set only one to true!
    //differentiate between old command line function and
    bool commandLineInputActive, fileInputActive;
    commandLineInputActive = false;
    fileInputActive = true;

    createAnInputFileIfNoneExists();

    //#### Core Elements ####
    //the central and most often Used Elements which will be used throughout the Program will be initialised here
    char *activeWord = calloc(MAX_WORD_SIZE_FILE, sizeof (char )); //the Word which will be used to play the game (comm line arg || user input)
    char** p_activeWord = &activeWord;


    do { //main loop to let the user run the Game multiple times

    //      ###         Program         start ###
    int bufferStartSequenceValue = startSequence();//execute the start sequence and proceed depending on it's ret val.

    //switch-case to interpret the return Value of the StartSequence
    switch (bufferStartSequenceValue) {

//               #### Hangman Game Active ####
        case 0: //the user has selected to run the Programm

            if(commandLineInputActive == true)
            activeWord = commLineArgManagement(argc, argv); //assign the activeWord from the commLineArg Function

            if(fileInputActive == true){
             short int tempRetVal = getTheWordFromTheInputFile(p_activeWord);
                 //Return Value Management:
                switch (tempRetVal) {
                    case 10: //no available words Abort Case
                        free(activeWord);
                        errorManagement(EENoInputDetectedFile, ERROR);
                        return ERNoUserInputDetectedFile;
                }
            }


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
            free(activeWord);
            return 0;
        case 2://Return value of start sequence signals there has been an error in its function
            errorManagement(EEStartSequenceReturn, ERROR);
            free(activeWord);
            return ERStartSequenceRet;
        case 3://open word file
            system("nano Hangman_Words.txt");
            break;
        default://undefined return error behavior
            errorManagement(EEStartSequenceDefault, ERROR);
            free(activeWord);
            return ERStartSequenceDef;
    }//End switch case start sequence Return

    }  while (1); //end of the loop which lets the user play multiple times
    return 0;
}

//all the todos
//TODO !!before final version set all DEBUG to 0!!

//TODO change errorManagement() to write to Error log (add or change)





