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
    unsigned short int *p_wordCount = &wordCount;
    char wordArray[MAX_WORD_COUNT_FILE][MAX_WORD_SIZE_FILE]; //Array containing the Guess-words
    //Array containing the Markers corresponding to the wordArray
    short int wordArrayMarkers[MAX_WORD_COUNT_FILE] = {0}; //array containing the markers signaling if the word can be used or not

    char wordArrayValid[MAX_WORD_COUNT_FILE][MAX_WORD_SIZE_FILE]; //Array containing the Guess-words that are marked as Valid
    unsigned short int wordCountValid = 0; //count of the Valid guess-words in the wordArray Valid


    //read out all the necessary information from the wordGuessFile
    generateFileInformation(p_wordCount,wordArray, wordArrayMarkers);

    //generate Array containing only valid Words for guessing
    for (int i = 0; i < wordCount; ++i) {
        if(wordArrayMarkers[i] == 1){
            strcpy(wordArrayValid[wordCountValid], wordArray[i]);
            wordCountValid++;
        }
    }

    //get random Number for Word choosing
    int randNum = generateRandomNumber(wordCountValid);


    //copy a random word from the wordArray into the active Word
    strcpy(*activeWord, wordArrayValid[randNum]);


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


//writes different in
short int generateFileInformation(unsigned short int *wordCount,char wordArray[MAX_WORD_COUNT_FILE][MAX_WORD_SIZE_FILE], short int *wordArrayMarkers){


    FILE*file;
    if((file=fopen("Hangman_Words.txt","a+"))) {
        char *tempWordString = calloc(MAX_WORD_SIZE_FILE, sizeof(char));
        char *tempMarkerString = calloc(SIZE_MARKERS, sizeof(char));

        const char *compareFileMarkerUsable = "#";
        const char *compareFileMarkerUnusable = "#+";
        char checkIfNextCharEOF;


// Block skip the Text in the beginning
        long seekOffset = FILE_HEADER_OFFSET;
        fseek(file, seekOffset, SEEK_CUR);
        seekOffset = 1; //so skips newline and space
//End Block skip the text in the beginning



//wile Loop to run through the input Words and assign them to the wordArray
//also generates the WordMarkersArray according to the tempMarkerStrings
        int arrayIndex = 0;
        while (true) {

            fscanf(file, "%s", tempWordString); //assign word to tempWordString




            strcpy(wordArray[arrayIndex], tempWordString);


            fseek(file, seekOffset, SEEK_CUR); //skip Space
            fscanf(file, "%s", tempMarkerString);//assign Marker to tempMarkerString


            if (0 == (strcmp(tempMarkerString, compareFileMarkerUsable))) { //case #
                wordArrayMarkers[arrayIndex] = 1;
            } else if (0 == (strcmp(tempMarkerString, compareFileMarkerUnusable))) { //case #+
                wordArrayMarkers[arrayIndex] = 0;
            } else {
                //todo error stuff
            }

            fseek(file, seekOffset, SEEK_CUR); //skip newline



            *(wordCount) += 1; //Increment Word-counter so caller function knows how many entries in Array valid



            //check if end of file is reached
            checkIfNextCharEOF = fgetc(file);
            if (checkIfNextCharEOF == EOF) {
                break; //break loop if EOF is reached
            } else {
                seekOffset = -1; //go one byte back
                fseek(file, seekOffset, SEEK_CUR);
                seekOffset = 1; //reset to the def value
            }

            arrayIndex++; //increment arrayIndex so on next run written to next spot


        }//endwhile true

        //FreeSpot
        free(tempWordString);
        free(tempMarkerString);

        //CLOSE the Filestream
        fclose(file);

    }else{ //file open error

        printf("Error");
        //todo usual error stuff + return
        return -1;
    }




return 0;
}
