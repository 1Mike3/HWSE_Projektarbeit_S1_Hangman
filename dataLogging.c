//
// Created by Michi on 27.12.2022.
//

#include <stdio.h>
#include <time.h>
#include <string.h>

#include "dataLogging.h"
#include "errorManagement.h"
// """" File Description """"
//file responsible for all the data logging, except error Codes(errorManagement)
// """"END File Description """"

/*
//file that logs the progress of the game into a Log file
 -control Character Meaning in associated Header file enum
 -if not necessary because of control char value constant # written for other values
*/
int saveGameProgressIntoLogFile(char UserInputChar, char* uncoveredWord, short int controlCharacter){

   char *logFileName = "Hangman_Game_Logfile.txt";
    //Start saving to File
    FILE*file;
    if((file=fopen(logFileName, "a"))){


        //switch case for managing the different saving scenarios depending on the control Character

char *timeString;

        switch (controlCharacter) {
            case CONTROLCHARSAVEPROGRESSTOLOG_STARTOFTHEGAME:

                timeString = getTimeString(); //get the time in the form of a String
                fprintf(file, "\n\n==== Start of a new Hangman game ====");
                fprintf(file, " [Timestamp: %s] \n\n", timeString);
                break;
            case CONTROLCHARSAVEPROGRESSTOLOG_NORMALINPUTSAVING:
                timeString = getTimeString(); //get the time in the form of a String
                fprintf(file, "\n++ User selected a letter: %c ", UserInputChar);
                fprintf(file, " [Timestamp: %s] \n ", timeString);
                fprintf(file, " Status of the guess-word: %s ++\n", uncoveredWord);
                break;
            case CONTROLCHARSAVEPROGRESSTOLOG_INVALIDUSERINPUT:
                timeString = getTimeString(); //get the time in the form of a String
                fprintf(file, "\n++ Invalid user Input ++");
                fprintf(file, " [Timestamp: %s] \n", timeString);
                break;
            case CONTROLCHARSAVEPROGRESSTOLOG_ENDOFTHEGAME:
                timeString = getTimeString(); //get the time in the form of a String
                fprintf(file, "\n\n==== The Game has Ended ====");
                fprintf(file, " [Timestamp: %s] \n\n", timeString);
                break;
            case CONTROLCHARSAVEPROGRESSTOLOG_GAMEHASBEENWON:
                timeString = getTimeString(); //get the time in the form of a String
                fprintf(file, "\n++ Game has been won ++");
                fprintf(file, " [Timestamp: %s] \n", timeString);
                break;
            case CONTROLCHARSAVEPROGRESSTOLOG_GAMEHASBEENLOST:
                timeString = getTimeString(); //get the time in the form of a String
                fprintf(file, "\n++ Game has been lost ++");
                fprintf(file, " [Timestamp: %s] \n", timeString);
                break;
            default:
                errorManagement(EEFileManagementOpeningLogfileUnexpectedControlInput, ERROR);
                return SAVEPROGRESSTOLOGFILEFAILED;
        }

//

        fclose(file);
    }else{
        errorManagement(EEFileManagementOpeningLogfileFailed, ERROR);
        return SAVEPROGRESSTOLOGFILEFAILED;
    }
    return SAVEPROGRESSTOLOGFILEFINISHEDSUCCESSFULLY;
}

//function to get the current system Time in the Form of a String
char *getTimeString(void){
    //createThe variables for Time Management
    time_t systemTime = 0;
    char * timeString;

    systemTime = time(NULL); // get system Time
    timeString = ctime(&systemTime); //convert time to string
    timeString[strlen(timeString) - 1] = '\0'; //add null-terminating-Char to timeString

    return timeString;
}
