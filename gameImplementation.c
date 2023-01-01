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
#define DEBUG2 0

#define UNDISCOVEREDSYMBOL '_' //the symbol that will be used for the uncovered parts of the word
#define NOOOFTRYS 10          //the number of game rounds that is set from the start



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
    printf("DB the length of your Word is: %i \n", (unsigned long long)wordLength);
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

short int tryCounter = NOOOFTRYS; //counts the number of available trys

 char inputChars[NOOOFTRYS] = ""; //all the chars that have been entered by the User
 char inputCharsHits[NOOOFTRYS] = ""; //all the chars that have been entered by the User and are correct
 char inputCharsMisses[NOOOFTRYS] = ""; //all the chars that have been entered by the User and are incorrect


    short int controlValueGuessLetters = 0; //controlValue of the guessLetters function
    short int controlValueCoveredWordManagement = 0; //controlValue of the CoveredWordManagement function

    //assign space for the inputWord which has been converted into a
 char *activeWordConverted = malloc(wordLength +1 * sizeof(char));
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

while(tryCounter != 0) { //Round loop, one Game-round is one loop through this while loop
    printf("\n");
    printVariablyCoveredWord(wordLength, uncoveredArray, activeWordConverted);
#if DEBUG1
    printf("Printout of the active Word: %s\n", activeWord);
#endif
    printf("You have %i tries left.\n", tryCounter);
    printf("Guess a letter/ Guess the Word/ End this Round.\n");
    printf("Letters not in my word: %s\n", inputCharsMisses);


    char guessedLetter = letUserGuessLetters(&controlValueGuessLetters);
    if(controlValueGuessLetters == 1){
        printf("You have chosen to abort the Game (Keystroke [1])!\n");
        break;
    }
//insert Error Case return #

   controlValueCoveredWordManagement = coveredWordManagement(guessedLetter, activeWordConverted, uncoveredArray,
                          inputCharsMisses, inputCharsHits);

#if DEBUG2
    printf("DB The guessed Letter is: %c", guessedLetter);
#endif

 //count the misses
if (controlValueCoveredWordManagement == 2)
tryCounter--; //decrement trycounter to keep track on how many guesses have been made

if(tryCounter == 0)
    printf("You ran out of trys, GAME OVER!\n");

} // End Round-loop while

    free(activeWordConverted);
    free(uncoveredArray);
    return 0;
}// End Game Runtime function







// ##################### Start Subfunctions ##############################################



//function to print out the active-word with the parts that haven't been guessed substituted by a '_'
void printVariablyCoveredWord(unsigned long long wordSize,const short int *uncoveredArray, char *activeWordConverted){
    printf("My Word: ");

    for (unsigned int i = 0; i < wordSize; ++i) {

        if(*(uncoveredArray+i) == 0){
            printf("%c", UNDISCOVEREDSYMBOL);
        }

        if(*(uncoveredArray+i) == 1){
            printf("%c", activeWordConverted[i]);
        }

    }
    printf("\n\n");
}




//function to manage the Letter input and adjust the different Word-Arrays accordingly
// 0: if finished successfully and word has been correctly guessed
//1: if falied
//2: if no word has been correctly guessed
short int coveredWordManagement(char inputChar, char *convertedWord,short int *uncoveredArray,
                            char *misses,  char *hits){
    char stringToAppend[2]; //converting input Char to string for StrCat functions
   stringToAppend[0] = inputChar;
           stringToAppend[1] = '\0';

  unsigned int wordLength = strlen(convertedWord); //get the length of the word used in the game
  short int appendedMarker = 0; //Marker so if word was once added to the hits or misses list, wont added again if two times in word

    for (unsigned int i = 0; i < wordLength; ++i) {//loop through word and check which uncovered

        if(inputChar == convertedWord[i]){ //case if hit was made
            uncoveredArray[i] = 1;
            if (appendedMarker == 0){ //so only once added to string even if 1+ in word
                strcat(hits, stringToAppend);
                appendedMarker++;
            }

        }

    }

    if (appendedMarker == 0) {//case if no hits were made
        strcat(misses, stringToAppend);
        return 2;
    }

    return 0;
}

