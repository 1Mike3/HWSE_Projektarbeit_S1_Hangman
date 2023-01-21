//
// Created by Michi on 27.12.2022.
//

#include "userInput.h"
#include "errorManagement.h"
#include "helperFunctions.h"
#include "dataLogging.h"
#include "stdbool.h"


#include <string.h>
#include <unistd.h>


//Debugging Helpers
#define DEBUG1 0 //TestPrint argc argv
#define DEBUG2 0 // Debug messages in the Functions
//#define DEBUG3 0

//my constants
#define ALPHABETSIZE 26
#define ALPHABETOFFSET 32


int startSequence(void) {


    static int textFormat = 0; //prints out a different textblock depending on if this is the first function call


    if (textFormat == 0) { // text on first call
        //start block to be printed on every Programm start
        printf("\n\n           ======= HANGMAN =======\n");
        printf("Welcome to my version of the Hangman-Game!\n\n");

        printf("             ##  How to Play: ##    \n");
        printf("Look up the Manual \"Hangman_Manual.txt\" (automatically generated on first startup)\n\n");


        printf("Press \"s\" to start the Game, \"q\" to quit, \"e\" to edit the Word-file.\n");
        printf("* Consult manual about the \"e\" option\n");
    }
    if (textFormat == 1) { //text on the following calls
    printf("Do you want to Play another Game?\n");

    printf("Press \"s\" to start a new Game / press \"q\" to quit,\"e\" to edit the Word-file. \n");
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
    }else if(controlCharacter == 'q'){
        return 1;
    } else if(controlCharacter == 'e'){
        return 3;
    }else{
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
        fflush(stdin);
        return 'I';
    }


    if(userInput == 'q' || userInput == 'Q'){ //Interpreting of the user-input
            return 'q';
        }else if(userInput == 's' || userInput == 'S'){
        return 's';
    } else if(userInput == 'e' || userInput == 'E'){
        return 'e';
    }else{
        printf("invalid input or more than one letter, try again!\n");
        fflush(stdin);
        return 'I';
    }

}



short int commLineArgManagement(char* active_Word, int argc, char **argv,bool * activateFileInput) {
    //!! important i am rewriting this whole function for getOpt, Will comment old code out and mark with %&&%
    //!! Doing this just so it can be seen that i did the first part of the assignment

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

    bool wordValid = false; //marker for the check-word function
    int getOptReturn; //return "char" of the getOpt function, used for  switch case to decide

    //while loop to manage the input arguments using getOpt
    //1 retrurn = file  input selected
    //-1 return if error in function
    //2 for word command line enter selection
    //0 return if programm should be no longer executed after function but no error
    while ((getOptReturn = getopt(argc, argv, "mfw:")) != -1) {
        //switchCase to manage the getOpt returns
        switch (getOptReturn) {

            case  'm': //Print Manual
                printf("\n\n ## Open Manual-input was chosen ## \n\n");
                printFileTOConsole("Hangman_Manual.txt");
                //TODO add change filename option
                break;
            case 'f': //case User chose to use the input-file for the Game
                printf("\n\n# file-input was chosen # \n\n");
                *activateFileInput = true;
                return 1;


            case 'w': //case user chose to use a input Word on the command line
                printf("\n\n# command-line-input was chosen # \n\n");
                wordValid = checkWord(optarg); //check if the active Word meets the input criteria
                if (wordValid == false) { //behavior if word does not meet input criteria
                    errorManagement(EEInputCriteriaNotMet, WARNING);
                    return -1;
                } else {
                    //return optarg;
                    strcpy(active_Word, optarg);
                    return 2;
                }

                    case '?': // unknown option encountered
                        errorManagement(EEGetOptUnknownArgument, WARNING);
                return -1;

                    case ':': // missing argument for option
                        errorManagement(EEGetOptMissingArgument, WARNING);
                        return -1;

                    default:
                        errorManagement(EEDefaultGetOptSwitchCase, WARNING);
                    return -1;
                }
        }




    /* %&&%
    //switch case to handle the different
    int wordValid = 0;
    switch (argc){
        case 1: //not enough input args
            errorManagement(EENotEnoughInputArguments, WARNING);
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
            return "#ERROR";
    }
    */
    return -1;
}



//function which allows the user to guess letters or enter a control Value during runtime
//control Value meaning:
//1: quit
//2: guess whole word
//return-value # if error in function
//return Value + if control char has been entered
//!! ++++ Partly Tested, seems to work, code looks like garbage and needs to be optimized
 char letUserGuessLetters(short int *controlValue){


    unsigned char userInput = (int) getchar(); //main input char
    unsigned char enterCatcher = (int) getchar(); // temp var to catch the \n input and check if only one char has been entered

    int errorDetector = 0; //detects if something went wrong during the input phase

    while (enterCatcher != '\n' && enterCatcher != '\r') { //loop till enter has been pressed
        enterCatcher = (int) getchar();//catch the second input
        errorDetector++;
    }


    short int tryCounter = 0;


    if(userInput == '1'){ //case if control character pressed quit
        *controlValue = 1;
        return  '+';
    } else if (userInput == '2'){ //case if control character pressed guess whole word
        *controlValue = 2;
        return '+';
    }


    if('#' == checkIfCharPartOfAlphabet(userInput))
    errorDetector++;

      if(errorDetector != 0){ //checking if more than one letter in input

        while (1){ // broken in end of loop
            saveGameProgressIntoLogFile('a', "a",
                                        CONTROLCHARSAVEPROGRESSTOLOG_INVALIDUSERINPUT);
        printf("invalid input or more than one letter, try again!\n");
            fflush(stdin);

        userInput = (int) getchar(); //main input char
        enterCatcher = (int) getchar(); // temp var to catch the \n input and check if only one char has been entered

        errorDetector = 0; //counts the amount of chars other than enter

        while (enterCatcher != '\n' && enterCatcher != '\r') { //loop till enter has been pressed
            enterCatcher = (int) getchar();//catch the second input
            errorDetector++;
        }

            if(userInput == '1'){ //case if control character pressed quit
                *controlValue = 1;
                return  '+';
            } else if (userInput == '2'){ //case if control character pressed guess whole word
                *controlValue = 2;
                return '+';
            }



            if('#' == checkIfCharPartOfAlphabet(userInput))
                errorDetector++;

        if(errorDetector != 0) { //checking if more than one letter in input
            tryCounter ++;
        } else{
            break;
        }


        if (tryCounter == 5){ // five trys to enter Valid char
            printf("too many wrong tries!\n");
            return ' '; //space for better optics in misses array
        }
    }//end while true loop



    }

    if(userInput == '1'){ //case if control character pressed
        *controlValue = 1;
        return  '+';
    } else if (userInput == '2'){
        *controlValue = 2;
        return '+';
    }


     char checkedChar = checkIfCharPartOfAlphabet(userInput);
    if(checkedChar == '#'){ //check if function failed
        saveGameProgressIntoLogFile('a', "a",
                                    CONTROLCHARSAVEPROGRESSTOLOG_INVALIDUSERINPUT);
        printf("invalid input or more than one letter, try again!\n");
        fflush(stdin);
        return '#';
    } else{
        return checkedChar;
    }
}



//allows the User to enter a String
//used for guess whole word function of the game
//0: it's all good man
//1: wrong input
short int getWord(unsigned short wordLength, char *returnString){


#if DEBUG2
    printf("#F get word Function\n");
#endif
    unsigned char tempInputChar = '0';
 char TempString[wordLength];
   unsigned short int inputCounter = 0;
    for (unsigned short i = 0; i < (wordLength + 1) && (tempInputChar != '\n') ; ++i) { //wordlength +1 so nullbyte gets
        tempInputChar =  getchar();
        if(tempInputChar != '\n') //so enter not in string
        TempString[i] =  (char)tempInputChar;

          inputCounter++;
    }

    TempString[wordLength] = '\0';

    if( wordLength != (inputCounter- 1)){ //-1 because offset in for loop
        errorManagement(EEWrongInputGetWordFunction,ERROR);
        return 1;
    }

    strcpy(returnString, TempString);
    return 0;
}




