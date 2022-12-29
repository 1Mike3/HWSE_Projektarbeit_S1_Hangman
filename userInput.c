//
// Created by Michi on 27.12.2022.
//

#include "userInput.h"
#include "errorManagement.h"
#include <string.h>

//Debugging Helpers
#define DEBUG1 0 //TestPrint argc argv
#define DEBUG2 0 // Debug messages in the Functions
//#define DEBUG3 0

//my constants
#define ALPHABETSIZE 26
#define ALPHABETOFFSET 32


/*
Start sequence, meaning of return value:
 0: the user has selected to run the program
 1: Abort the Programm execution
 2: Error
*/
int startSequence(void) {



    static int textFormat = 0; //prints out a different textblock depending on if this is the first function call


    if (textFormat == 0) { // text on first call
        //start block to be printed on every Programm start
        printf("======= HANGMAN =======\n");
        printf("Welcome to my version of the Hangman-Game!\n\n");
        printf("With the Version you're using the word to guess should\n have been selected while starting the Program.\n\n");
        printf("Press \"s\" to start the Game / press \"q\" to quit the program.\n");
    }
    if (textFormat == 1) { //text on the following calls
    printf("Do you want to Play another Game?\n");
    printf("Press \"s\" to start a new Game / press \"q\" to quit.\n");
}
    textFormat = 1;//set to 1 so different text on following calls

    //#### start control character input ####
    unsigned char controlCharacter = getSingleChar(); //get the formatted char from the get single char function
    short int wrongInputCounter = 0; //if there are more than 5 wrong inputs the Program stops

    //"I" is the "invalid input" return of the getSingleChar function
    while (controlCharacter == 'I'){ //try again if there has been a wrong input
        if(wrongInputCounter == 4){ //abort if too many wrong inputs (4 because first input outside of loop)
            printf("Too many wrong Inputs, the programm stops now!\n");
            return 1;
        }
        wrongInputCounter++; //increment counter so know how many wrong inputs
        controlCharacter = getSingleChar();//trying again after wrong input
    }

    //generate the return value
    if(controlCharacter == 's'){
        return 0;
    }
    if(controlCharacter == 'q'){
        return 1;
    } else{
        return 2; // error something went wrong if this is the return value
    }

}






//used in start sequence
//returns the following chars while dealing with wrong user Input:
//q: quit
//s: start
//I: wrong input
unsigned char getSingleChar(void){
    unsigned char userInput = (int) getchar(); //main input char
    unsigned char enterCatcher = (int) getchar(); // temp var to catch the \n input and check if only one char has been entered

    int loopCounter = 0; //counts the amount of chars other than enter

    while (enterCatcher != '\n' && enterCatcher != '\r') { //loop till enter has been pressed
        enterCatcher = (int) getchar();//catch the second input
        loopCounter++;
    }

    if(loopCounter != 0){ //checking if more than one letter in input
        printf("invalid input or more than one letter, try again!\n");
        return 'I';
    }


    if(userInput == 'q' || userInput == 'Q'){ //Interpreting of the user-input
            return 'q';
        }else if(userInput == 's' || userInput == 'S'){
        return 's';
    } else{
        printf("invalid input or more than one letter, try again!\n");
        return 'I';
    }

}





//manages the Input of the Word to be guessed on the command line
//!!Unfinished
char *commLineArgManagement(int argc, char **argv){
    errorStruct EENotEnoughInputArguments = {
            .code = ERNotEnoughInputArgs  ,
            .message = "No Input Argument Detected"
    };
    errorStruct EEMoreThanOneInputArgument = {
            .code = ERMoreThanOneInputArg ,
            .message = "More than one Input Argument has been entered"
    };

    errorStruct EEInputCriteriaNotMet = {
            .code = ERInputCriteriaNotMet ,
            .message = "The function which checks the Word for correctness determined it does not meet the requirements"
    };
#if DEBUG2
    printf("#F comLineArgManagement\n");
#endif

#if DEBUG1
    //printf("Hello World");
    //Test Print the User Input
    for(int i=0; i<argc; i++) {
        if (i != 0) { //so the Programm name will be skipped
            printf("\"%s\"\n", argv[i]);
        }
    }
#endif

    //switch case to handle the different
    int wordValid = 0;
    switch (argc){
        case 1: //not enough input args
            errorManagement(EENotEnoughInputArguments, WARNING);
            //TODO fix this edgecase (let user enter another word)
            //!!Not Fixed
            return "#ERROR";
        case 2:// one Input arg, correct
             wordValid = checkWord(*(argv+1)); //check if the active Word meets the input criteria
             if(wordValid == 0){ //behavior if word does not meet input criteria

                 errorManagement(EEInputCriteriaNotMet, WARNING);
                 return "#ERROR";

             } else{ //behavior if the word meets the input criteria
                 return *(argv+1); //return the input word
             }


        default: //too many input args
            errorManagement(EEMoreThanOneInputArgument, WARNING);
            //!!Not Fixed
            //TODO fix this edgecase (let user enter another word)
            return "#ERROR";
    }
}



//allows the User to enter a String
//!!Unfinished
char *getWord(void){
#if DEBUG2
    printf("#F get word Function\n");
#endif
}

//checks if word entered according to input criteria (alphabet 26 upper and lower)
//!!build for "" case
//!!Unfinished
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
