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
#include <string.h>

//Debugging Helpers
#define DEBUG1 1 //TestPrint argc argv
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
            .message = "//The ComLineArgManagement function has returned an error"
    };

#if DEBUG1
    printf("°No of argc: %i\n", argc);
#endif

    //#### Core Elements ####
    //the central and most often Used Elements which will be used throughout the Program will be initialised here
    char *activeWord = "0"; //the Word which will be used to play the game (comm line arg || user input)

    //### Program start ###
    int bufferStartSequenceValue = startSequence();//execute the start sequence and proceed depending on it's ret val.
    //switch-case to interpret the return Value of the StartSequence
    switch (bufferStartSequenceValue) {

//               #### Hangman Game Active ####
        case 0: //the user has selected to run the Programm
          activeWord = commLineArgManagement(argc,argv); //assign the activeWord from the commLineArg Function

          //Error handling of the commLineArgManagement Function
          //finishing with 104 is on purpose
            int tempCompareValue = 1;
            tempCompareValue = strcmp(activeWord, "#ERROR");
            if(tempCompareValue == 0){ //error handling
                errorManagement(EECommandLineArgumentFunctionFailed, ERROR);
              return ERComLineArgManagementFailed;
          }
#if DEBUG1
            printf("the input Word is: %s", activeWord);
#endif


            // #### Start game Sequence ####
            gameRuntime(activeWord);


            break;
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
    }
    return 0;
}

//all the todos
//TODO !!before final version set all DEBUG to 0!!

//TODO change errorManagement() to write to Error log (add or change)
//TODO give getWord() parameter to determine Use Case

//!!
//TODO implement the checkWord function in the CommLineArgManagement function
