//
// Created by osboxes on 31/12/22.
//
//this File contains little helper functions which are not really belonging to any specific source-code file

#include "helperFunctions.h"

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
void convertInputWordToUppercase(void){
  //  strcasecmp_l();
}
