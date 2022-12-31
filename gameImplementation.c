//
// Created by Michi on 27.12.2022.
//


#include "gameImplementation.h"
#include "errorManagement.h"
#include "userInput.h"
#include "helperFunctions.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define DEBUG1 0
#define DEBUG2 1

#define UNDISCOVEREDSYMBOL '_' //the symbol that will be used for the uncovered parts of the word
#define NOOFROUNDS 10          //the number of game rounds that is set from the start



//Game behavior in runtime after all the checks have been done if another Game can/should start
//returns 0 if Finished successfully and 1 if not
int gameRuntime(char *activeWord){
//Errors
    errorStruct EEMemoryAllocationFailed = {
            .code = ERMemoryAllocationFailed,
            .message = "Heap ran out of Memory!"
    };

               //#### Uncovered Value Array ###
    //create An array which contains the Information if a letter was Uncovered or not
    unsigned long long wordLength = strlen(activeWord); //var., contains length of word for uncov.arr. intialization
#if DEBUG1
    printf("DB the length of your Word is: %i \n", wordLength);
#endif
    //undiscovered Char with preprozconst "UNDISCOVEREDSYMBOL"
    //1: discovered , 0: undiscovered
    //this array contains the Information if a letter has been discovered by the player or not
short int *uncoveredArray = calloc( wordLength , sizeof(short int));
if(uncoveredArray == NULL){
    errorManagement(EEMemoryAllocationFailed, WARNING);
    return 1;
}
// END #### Uncovered Value Array




//    #########  Game Variables ###########

short int tryCounter = NOOFROUNDS; //counts the number of available trys

char inputChars[NOOFROUNDS] = ""; //all the chars that have been entered by the User
char inputCharsHits[NOOFROUNDS] = ""; //all the chars that have been entered by the User and are correct
char inputCharsMisses[NOOFROUNDS] = ""; //all the chars that have been entered by the User and are incorrect

char gameControlCharacter;  //character used to let the user control the game during game runtime

  unsigned char *activeWordConverted = malloc(wordLength +1 * sizeof(char));
    if(activeWordConverted == NULL){
        errorManagement(EEMemoryAllocationFailed, WARNING);
        return 1;
    }
//END ######### Game Variables #############





// #### Convert lowercase input into uppercase input ####
    convertInputWordToUppercase(activeWord, activeWordConverted, wordLength);
#if DEBUG1
    printf("word Converted outside of funnction: %s\n", activeWordConverted);
#endif




//                  ###### start the Game ######

//while(1) { //Round loop, one Game-round is one loop through this while loop
    printVariablyCoveredWord(wordLength, uncoveredArray, activeWord);

    printf("You have %i tries left.\n", tryCounter);
    printf("Guess a letter/ Guess the Word/ End this Round.\n");
    printf("Letters not in my word: %s\n", inputCharsMisses);

    //insert control sequence here( q, g, enter)
    //insert control sequence return handeling here
    short int controlValueGuessLetters = 0;
    char guessedLetter = letUserGuessLetters(&controlValueGuessLetters);
#if DEBUG2
    printf("DB The guessed Letter is: %c", guessedLetter);
#endif



    //insert check letter for correctness and print function here

//} // End Round-loop while

    free(activeWordConverted);
    free(uncoveredArray);
    return 0;
}// End Game Runtime function







// ##################### Start Subfunctions ##############################################



//function to print out the active-word with the parts that haven't been guessed substituted by a '_'
void printVariablyCoveredWord(unsigned long long wordSize,const short int *uncoveredArray, char *activeWord){
    printf("My Word: ");

    for (unsigned int i = 0; i < wordSize; ++i) {

        if(*(uncoveredArray+i) == 0){
            printf("%c", UNDISCOVEREDSYMBOL);
        }

    }
    printf("\n\n");
}



void uncoverSelectedLetters(void){

}
