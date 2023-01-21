//
// Created by osboxes on 31/12/22.
//
//this File contains little helper functions which are not really belonging to any specific source-code file

#include "helperFunctions.h"
#include "errorManagement.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
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
                return (char)letterReturnValue; //return lowercase char converted to uppercase char
            }else{ //if input was uppercase
                letterReturnValue = letterToBeChecked;
                return (char)letterReturnValue; //return the char as entered
            }

        } // end if input was valid

}



//converts the InputWord to uppercase
//+++ Tested +++ Works
void convertInputWordToUppercase(char *wordToBeConverted, char *convertedWord,unsigned short stringLength){
    char *tempStringValue = wordToBeConverted; //assigning temp var to be used in function

    // loop through string and convert the chars
    for (unsigned int a = 0; a < stringLength; a++)
    {
        //writing the converted chars into the converted Word
        convertedWord[a] = (char)toupper(tempStringValue[a]);
    }

    convertedWord[stringLength] = '\0';

#if DEBUG1
    printf("%s tempStringValue in Function \n", convertedWord);
#endif
}



//checks if word entered according to input criteria (alphabet 26 upper and lower)
//0: the word is incorrect
//1: the word is correct
int checkWord(char *Word){
    unsigned short stingLength = strlen(Word); //unsigned long long so no conversion error from size_t
    int tempCompareChar= 'A'; //Starts with A and moves through the Alphabet, uses offset constant to also compare lowercase
    unsigned int correctLetterCounter = 0;
    unsigned char tempLetter;
//little debug helper
/*
    char debugcharUpper;
    char DebugcharLower;
    char ComparedWord;
*/
    for (unsigned short i = 0; i < stingLength; ++i) {
        tempLetter = *(Word+i);
        //checking all letters of the Alphabet, lower and upper case with offset
        //premeditated style-change to improve visibility
        for (unsigned short j = 0; j < ALPHABETSIZE; ++j) {
            /*//little debug helper
            debugcharUpper = (tempCompareChar+j);
            DebugcharLower = (tempCompareChar+ALPHABETOFFSET+j);
            ComparedWord = (tempLetter + i);
             *///
            if((tempLetter) == (unsigned short ) (tempCompareChar + j) //comp w upper case
               ||
               (tempLetter) == (unsigned short )(tempCompareChar + ALPHABETOFFSET + j) //comp w lower case
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
          r = rand() % max;
    return r;
}

void printManualInFileOnStartup(void){
    char * manualFileName = "Hangman_Manual.txt";
    FILE *file;
    if ((file = fopen(manualFileName, "r"))) { //check if File Exists
        fclose(file);
    } else { //create file
        if ((file = fopen(manualFileName, "w+"))) {


            fprintf(file," ### Manual to my Hangman-Game :)  ###\n\n"
                         "-!!Configuration-File which contains the guess-words: Hangman_Words.txt (created on startup).\n"

                         " -the program only works with GETOPT now, an argument has to be provided on startup. (note that the game has to be started with [s] for the entered argument to take effect)\n"

                         " -GET-OPT:\n\n"

            "         \t -press -w and enter a word after it to play using a manually selected guessword.\n"
            "    -\t enter -f to play using the input file"
            "   -e\t enter -m to display the manual on startup (should be entered with one of the other functions)\n"
            "   -w\t when you encounter a problem with one of the files, delete it and the program will generate a new one on the next startup.\n"

            "    -The \"e\" function in the main menu only works if the program is executed on linux in the command line, of course you can also open the files manually.\n\n"

            "    -The WordFile is limited to 40 Words and each word 35 characters max.\n"

            "  -valid input characters letter-guessing (except program control numbers) are 26 lat. alphabet letters (lower or uppercase).\n"

            "  -When too many invalid inputs(eg. AA or &) are made in one try it is counted as a miss.\n"

            "  -during letter guesses, press [1] to quit the game and [2] to guess the whole word.\n\n"

            "    -!argument options are only considered if start the game is selected\n"

            "  -the format in which the words should be written into the file is printed out in the file header.\n"

            "  -the program returns various error codes and messages if an exception occurs.\n"

            "   -if you select the file option and the input file is empty the game will return an error and you will not be able to play.\n"

            "   -How to Play:\n\n"
            "  chose the input arguments which you want to use.\n"
            "    (see GET-OPT, they are only considered if you press \"s\" on the next run)\n"

            "   now you can chose between three options which are displayed in the command line.\n"
            "   (not that if you wat to play using the file input, you have to write the words into the file first).\n"

            "  when you press s the game starts, then you can guess letter after letter until you either guessed the word.\n"
            "  or you run out of tries."

            "    The Number 2 can also be pressed to guess the word in one go.\n"
            "    (note that you will loose the game if you choose wrong)\n"

            "  After that you will be able to start another game.\n"

            "    With the file input option another word from the file will be selected.\n"
            "     With the -w option you will play again using the same word from the command line.\n"

            "      You can quit the programm by pressing q in the menue.\n"
            "     (To get to the menue during the game you can press 1 to abbort the current game.)\n\n");



            fclose(file);
            return;
        }else{
            errorManagement(EEErrorOpeningFileStream, WARNING);
            return;
        }
    }
}


short int printFileTOConsole(char* filename){
    FILE * file;
    char tempC;
    file = fopen(filename, "r");

    if(file == NULL)
        return -1;

    tempC = (char)fgetc(file);
    if(tempC == EOF)
    return -1;

     printf("%c", tempC);

    while (tempC != EOF) {
        printf("%c", tempC);
        tempC = (char)fgetc(file);

    }

   int ret = fclose(file);
   if(ret == -1)
       return -1;

    return 0;
}
