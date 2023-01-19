#include <stdio.h>

/** \file
 *  \brief
 */


/** \file  #### General Programm Information ####
 *  \brief  -Created by: Michal Kuc 27.12.2022
 * -Project HWSE WS22
 * -Hangman Game with visualisation, user input and data logging
 * -I added Debug-Helpers in the source code: #if DEBUG segments are irrelevant for the programs functionality
 *
 */


/** \file
  * \brief This is just an example file. */
 /**
 * \brief Calculates the quotient of two numbers.
 *
 * Divides two doubles and returns the resulting quotient.
 * Division by zero is handled explicitly and generates
 * a warning on \c stdout.
 *
 * \param dividend The number to be divided.
 * \param divisor The number to be divided by.
 * \return The resulting quotient, or
 * \c HUGE_VAL when zero is passed as \c divisor.
 */


//Including of project-related Header-Files
#include "dataLogging.h"
#include "gameImplementation.h"
#include "userInput.h"
#include "errorManagement.h"
#include "wordInputFile.h"
#include "helperFunctions.h"


//Including of external Header-Files
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>


//Debugging Helpers
#define DEBUG1 0 //TestPrint argc argv



int main(int argc, char **argv){

    //initialize random number generator
   time_t t;
   srand((unsigned) time(&t));

   //for skipping of comlineArgManagement
    bool skipComLineArgManagementAfterFirstEntry = false;

   //Print Manual
   printManualInFileOnStartup();

#if 0 //debug random number generator
    int r;
    for (int i = 0; i < 20; ++i) {
       r = generateRandomNumber(2);
        printf("%i\n", r);
    }
#endif


    //marker which is set if the file input will be used during the game
    bool activateFileInput;
    activateFileInput = false;

    //kinda self-explanatory
    createAnInputFileIfNoneExists();

    //#### Core Elements ####

    //the Word which was chosen for the game (comm line arg || user input)
    //later used
    char *activeWord = calloc(MAX_WORD_SIZE_FILE, sizeof (char ));

//switch-case to interpret the return Value of the StartSequence
    short int comLineArgManagementReturnValue = 0;

    do { //main loop to let the user run the Game multiple times

    //      ###         Program         start ###
    int bufferStartSequenceValue = startSequence();//execute the start sequence and proceed depending on it's ret val.


    switch (bufferStartSequenceValue) {

//               #### Hangman Game Active ####
        case 0: //the user has selected to run the Programm

        //bool to skip comLineArgManagement

        if(skipComLineArgManagementAfterFirstEntry == false) {
            comLineArgManagementReturnValue = commLineArgManagement(activeWord, argc, argv,&activateFileInput); //assign the activeWord from the commLineArg Function
        }
            skipComLineArgManagementAfterFirstEntry = true;

        //com LineArgManagement selected file Input
            if(comLineArgManagementReturnValue == 1){
                //DEBUG
                //works if initialize new word here and pass to function
                //strcpy doesn't work if word Previosly initialized
                //oh i get it the string assignemnt changes the address
                //change com line arg management function so active word passed as parameter and not touched if file input chosen.

             short int tempRetVal = getTheWordFromTheInputFile(&activeWord);
                 //Return Value Management:
                 //switch case because expect to add more returns later
                switch (tempRetVal) {
                    case 10: //no available words Abort Case
                        free(activeWord);
                        errorManagement(EENoInputDetectedFile, ERROR);
                        return ERNOUSERINPUTDETECTEDFILE;
                }
            }

            //Error handling of the commLineArgManagement Function
            //checking if return of com line Arg management is error (-1)
            if (comLineArgManagementReturnValue == -1) { //error handling
                errorManagement(EECommandLineArgumentFunctionFailed, ERROR);
                return ERCOMLINEARGMANAGEMENTFAILED;
            }

            // #### Start game Sequence ####
            int returnGameRuntime = gameRuntime(activeWord);
            if (returnGameRuntime == GAMERUNTIMEERROR || returnGameRuntime == GAMEUNPREDICTEDBEHAVIOR) {
                errorManagement(EEGameRuntimeFailed, ERROR);
                return ERGAMERUNTIMEFUNCTIONFAILED;
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
            return ERSTARTSEQUENCERET;
        case 3://open word file
            system("nano Hangman_Words.txt");
            break;
        default://undefined return error behavior
            errorManagement(EEStartSequenceDefault, ERROR);
            free(activeWord);
            return ERSTARTSEQUENCEDEF;
    }//End switch case start sequence Return

    }  while (1); //end of the loop which lets the user play multiple times
}

//all the todos
//TODO !!before final version set all DEBUG to 0!!

//TODO change errorManagement() to write to Error log (add or change)





