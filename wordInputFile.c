//
// Created by osboxes on 06/01/23.
//

#include "wordInputFile.h"
#include "errorManagement.h"
#include "helperFunctions.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


short int getTheWordFromTheInputFile(char** activeWord){

    unsigned short int wordCount = 0; //count of the guessWords in the File
    char wordArray[MAX_WORD_COUNT_FILE][MAX_WORD_SIZE_FILE]; //Array containing the Guess-words
    //Array containing the Markers corresponding to the wordArray
    short int *wordArrayMarkers = calloc(MAX_WORD_COUNT_FILE, sizeof (short int ));

    generateFileInformation(wordCount,wordArray, wordArrayMarkers, activeWord);


    free(wordArrayMarkers);
    return 0;
}

//function to create the file which contains the guess-words on the first program start if the file doesn't exist
void createAnInputFileIfNoneExists(void) {
    FILE *file;
    if ((file = fopen("Hangman_Words.txt", "r"))) { //check if File Exists
        fclose(file);
    } else { //create file
        if ((file = fopen("Hangman_Words.txt", "w+"))) {
            fprintf(file,"## List of Hangman guess-words ## \n\n -enter guess-words in this Format: \n"
                         "[Word]  [Space]  [#]  [+]\n-the # is a terminating character\n"
                         "-the + is a marker if the word already was used\n"
                         "(write it only if this word should be skipped)"
                         "-max word length is 35 characters, more info in Manual\n"
                         "__________________________________\n");
            fclose(file);
            return;
        }else{
            printf("Error big Nono\n");
            //todo usual error stuff
            return;
        }
    }

}


//function to count the lines in the file so the word-markers can be managed
//returns -1 on error
short int generateFileInformation(unsigned short int wordCount,char wordArray[MAX_WORD_COUNT_FILE][MAX_WORD_SIZE_FILE], short int *wordArrayMarkers, char ** activeWord) {


    FILE*file;
    if((file=fopen("Hangman_Words.txt","a+"))) {
        char *tempWordString = calloc(MAX_WORD_SIZE_FILE, sizeof (char ));
        char *tempMarkerString = calloc(SIZE_MARKERS, sizeof (char ));

        const char *compareFileMarkerUsable = "#";
        const char *compareFileMarkerUnusable = "#+";
        char checkIfNextCharEOF ='a';

        //DO This :
        // generateRandomNumber();



// Block skip the Text in the beginning
// This block is copied in the following code, it is larger than it needs to be for easier debugging
        long tell = ftell(file);
        long seekOffset = FILE_HEADER_OFFSET;
        int seekRet = fseek(file,seekOffset,SEEK_CUR);
        long tell2 = ftell(file);
//End Block skip the text in the beginning



//wile Loop to run through the input Words and assign them to the wordArray
//also generates the WordMarkersArray according to the tempMarkerStrings
while(true){

    fscanf(file, "%s", tempWordString);

    tell = ftell(file);
    seekOffset = 1;
    seekRet = fseek(file, seekOffset, SEEK_CUR);
    tell2 = ftell(file);

    fscanf(file, "%s", tempMarkerString);

    tell = ftell(file);
    seekOffset = 1;
    seekRet = fseek(file, seekOffset, SEEK_CUR);
    tell2 = ftell(file);

    checkIfNextCharEOF = fgetc(file);
    if(checkIfNextCharEOF == EOF){
        break;
    }else{
        seekOffset = -1;
        seekRet = fseek(file, seekOffset, SEEK_CUR);
    }


}



        //copy the tempWordString to the active Word
        strcpy(*activeWord, tempWordString);

        //FreeSpot
        free(tempWordString);
        free(tempMarkerString);

        //CLOSE the Filestream
        fclose(file);


    }else{
        printf("Error");
        //todo usual error stuff + return
        return -1;
    }

return 0;
}
