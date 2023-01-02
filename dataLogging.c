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
 -if not necessary because of conrol char value constant # written for other values
*/
int saveGameProgressIntoLogFile(char UserInputChar, char* uncoveredWord, short int controlCharacter){
    //Error Messages
    errorStruct EEFileManagementOpeningLogfileFailed = {
            .code =  ERFileManagementOpeningFileFailed,
            .message = "Opening or Creating Logfile failed",
    };
    errorStruct EEFileManagementOpeningLogfileUnexpectedControlInput = {
            .code =  ERFileManagementOpeningFileUnexpectedControlCharacter,
            .message = "Switch case save game progress into log file exception",
    };



    //Start saving to File
    FILE*file;
    if((file=fopen("Hangman_Game_Logfile.txt","a"))){


        //switch case for managing the different saving scenarios depending on the control Character

        //createThe variables for Time Management
        time_t systemTime = 0;
        char * timeString = "Error obtaining Time";


        switch (controlCharacter) {
            case controlCharSaveProgressToLog_startOfTheGame:

                systemTime = time(NULL); // get system Time
                timeString = ctime(&systemTime); //convert time to string
                timeString[strlen(timeString) - 1] = '\0'; //add null-terminating-Char to timeString

                fprintf(file, "\n++++ Start of a new Hangman game ++++");
                fprintf(file, " -Timestamp: %s \n\n", timeString);
                break;
            case controlCharSaveProgressToLog_normalInputSaving:
                break;
            case controlCharSaveProgressToLog_invalidUserInput:
                break;
            case controlCharSaveProgressToLog_endOfTheGame:
                break;
            default:
                errorManagement(EEFileManagementOpeningLogfileUnexpectedControlInput, ERROR);
                return saveProgressToLogFileFailed;
        }

//

        fclose(file);
    }else{
        errorManagement(EEFileManagementOpeningLogfileFailed, ERROR);
        return saveProgressToLogFileFailed;
    }
    return saveProgressToLogFileFinishedSuccessfully;
}
