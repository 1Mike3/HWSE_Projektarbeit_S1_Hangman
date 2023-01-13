//
// Created by osboxes on 31/12/22.
//
//this File contains little helper functions which are not really belonging to any specific source-code file

#include "helperFunctions.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

//my constants
#define ALPHABETSIZE 26
#define ALPHABETOFFSET 32
#define DEBUG1 0



//checks if char is part of the 26 lower or uppercase alphabet chars and converts them to uppercase for uniformity
//returns '#' if failed and returns the converted char if succeeded
//+++ Tested +++ Works
char checkIfCharPartOfAlphabet(unsigned char letterToBeChecked){
    int tempCompareChar= 'A'; //start character for start to compare
    short int correctLetterDetected = 0; //marker to set when correct letter was detected
    unsigned char letterReturnValue;

    //for Loop to check if Letter is part of Alphabet
        for (unsigned long long j = 0; j < ALPHABETSIZE; ++j) {

            if((letterToBeChecked) == (unsigned long long) (tempCompareChar + j) //comp w upper case
               ||
               (letterToBeChecked) == (unsigned long long)(tempCompareChar + ALPHABETOFFSET + j) //comp w lower case
                    ){
                correctLetterDetected = 1;
                break;
            }
        }

        if(correctLetterDetected == 0){ //if input was invalid
            return '#';

        } else{// if input was valid

            //check if lowercase
            if(letterToBeChecked <= 'z' && letterToBeChecked >= 'a'){ //if input was lowercase
                letterReturnValue = (letterToBeChecked - ALPHABETOFFSET);
                return letterReturnValue; //return lowercase char converted to uppercase char
            }else{ //if input was uppercase
                letterReturnValue = letterToBeChecked;
                return letterReturnValue; //return the char as entered
            }

        } // end if input was valid

}



//converts the InputWord to uppercase
//TODO add error handling
//+++ Tested +++ Works
void convertInputWordToUppercase(char *wordToBeConverted, char *convertedWord,unsigned long long stringLength){
    char *tempStringValue = wordToBeConverted; //assigning temp var to be used in function

    // loop through string and convert the chars
    for (unsigned int a = 0; a < stringLength; a++)
    {
        //writing the converted chars into the converted Word
        convertedWord[a] = toupper(tempStringValue[a]);
    }

    convertedWord[stringLength] = '\0';

#if DEBUG1
    printf("%s tempStringValue in Function \n", convertedWord);
#endif
}



//checks if word entered according to input criteria (alphabet 26 upper and lower)
//!!build for "" case
//0: the word is incorrect
//1: the word is correct
int checkWord(char *Word){
    unsigned long long stingLength = (size_t)strlen(Word); //unsigned long long so no conversion error from size_t
    int tempCompareChar= 'A'; //Starts with A and moves through the Alphabet, uses offset constant to also compare lowercase
    unsigned int correctLetterCounter = 0;
    unsigned char tempLetter;
//little debug helper
/*
    char debugcharUpper;
    char DebugcharLower;
    char ComparedWord;
*/
    for (unsigned long long i = 0; i < stingLength; ++i) {
        tempLetter = *(Word+i);
        //checking all letters of the Alphabet, lower and upper case with offset
        //premeditated style-change to improve visibility
        for (unsigned long long j = 0; j < ALPHABETSIZE; ++j) {
            /*//little debug helper
            debugcharUpper = (tempCompareChar+j);
            DebugcharLower = (tempCompareChar+ALPHABETOFFSET+j);
            ComparedWord = (tempLetter + i);
             *///
            if((tempLetter) == (unsigned long long) (tempCompareChar + j) //comp w upper case
               ||
               (tempLetter) == (unsigned long long)(tempCompareChar + ALPHABETOFFSET + j) //comp w lower case
                    ){
                correctLetterCounter++; //if hit one of the words increment correct letter counter and don't check other ones
                break;
            }
        }
    }
//\0 not accounted on purpose because of strlen behavior
    if((correctLetterCounter) == (stingLength) ){
        return 1;
    } else{
        return 0;
    }
}

//generate random integer from 0 to max
int generateRandomNumber(int max){
    int r;
          r = rand() % max; //the +2,if weirdness is so 0 also generated
    return r;
}

//todo make Manualprint function
void printManualInFileOnStartup(void){
    FILE *file;
    if ((file = fopen("Hangman_Manual.txt", "r"))) { //check if File Exists
        fclose(file);
    } else { //create file
        if ((file = fopen("Hangman_Manual.txt", "w+"))) {
            fprintf(file,"### Manual to my Hangman-Game :) ###\n\n");
            fprintf(file,"-!!Configuration-File which contains the guess-words: Hangman_Words.txt (created on startup).\n");
            fprintf(file,"-when you encounter a problem with one of the files, delete it and the program\n"
                         "will generate a new one on the next startup.");
            fprintf(file,"\n");
            fprintf(file,"The \"e\" function in the main menu only works if the program is executed\n"
                         "on linux in the command line, of course you can also open the files manually.");
            fprintf(file,"The WordFile is limited to 40 Words and each word 35 characters max.\n");
            fprintf(file,"\n");
            fprintf(file,"-valid input characters letter-guessing (except program control numbers).\n"
                   "are 26 lat. alphabet letters (lower or uppercase).\n");
            fprintf(file,"-When too many invalid inputs(eg. AA or &) are made in one try it is counted as a miss.\n");
            fprintf(file,"-GET-OPT:\n"
                         "default if nothing is entered is to use the wordFile for word input.\n"
                         "press -w and enter a word after");
            fprintf(file,"-during letter guesses, press [1] to quit the game and [2] to guess the whole word.\n\n");

            fclose(file);
            return;
        }else{
            printf("Error big Nono\n");
            //todo usual error stuff
            return;
        }
    }
}
