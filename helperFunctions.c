//
// Created by osboxes on 31/12/22.
//
//this File contains little helper functions which are not really belonging to any specific source-code file

#include "helperFunctions.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

//my constants
#define ALPHABETSIZE 26
#define ALPHABETOFFSET 32
#define DEBUG1 1



//checks if char is part of the 26 lower or uppercase alphabet chars and converts them to uppercase for uniformity
//returns '#' if failed and returns the converted char if succeeded
//+++ Tested +++ Works
unsigned char checkIfCharPartOfAlphabet(unsigned char letterToBeChecked){
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
void convertInputWordToUppercase(char *wordToBeConverted,unsigned char *convertedWord,unsigned long long stringLength){
    char *tempStringValue = wordToBeConverted; //assigning temp var to be used in function

    // loop through string and convert the chars
    for (unsigned int a = 0; a < stringLength; a++)
    {
        //writing the converted chars into the converted Word
        convertedWord[a] = toupper(tempStringValue[a]);
    }

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
