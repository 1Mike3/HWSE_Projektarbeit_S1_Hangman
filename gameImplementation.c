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
    return gameRuntimeError;
}
// END #### Uncovered Value Array




//    #########  Game Variables ###########

short int tryCounter = NOOOFTRYS; //counts the number of available trys


//all the chars that have been entered by the User and are correct
    char * inputCharsHits = calloc(wordLength +1 , sizeof(char));
    if(inputCharsHits == NULL){
        errorManagement(EEMemoryAllocationFailed, WARNING);
        return gameRuntimeError;
    }

 char inputCharsMisses[NOOOFTRYS] = ""; //all the chars that have been entered by the User and are incorrect


    short int controlValueGuessLetters = 0; //controlValue of the guessLetters function
    short int controlValueCoveredWordManagement; //controlValue of the CoveredWordManagement function

    //assign space for the inputWord which has been converted into a only uppercase word
 char *activeWordConverted = malloc(wordLength +1 * sizeof(char));
    if(activeWordConverted == NULL){
        errorManagement(EEMemoryAllocationFailed, WARNING);
        return gameRuntimeError;
    }
//END ######### Game Variables #############





// #### Convert lowercase input into uppercase input ####
    convertInputWordToUppercase(activeWord, activeWordConverted, wordLength);
#if DEBUG1
    printf("word Converted outside of funnction: %s\n", activeWordConverted);
#endif




//                  ###### start the Game ######

while(1) { //Round loop, one Game-round is one loop through this while loop
    printf("\n");
    printVariablyCoveredWord(wordLength, uncoveredArray, activeWordConverted);
#if DEBUG1
    printf("Printout of the active Word: %s\n", activeWord);
#endif
    printf("(You have %i tries left.)\n", tryCounter);
    printf("-Guess a letter or enter a control Character.\n");
    printf("-Letters not in my word: %s \n", inputCharsMisses);

//####    let User guess Letters ####
    char guessedLetter = letUserGuessLetters(&controlValueGuessLetters);
    if(controlValueGuessLetters == 1){
        printf("You have chosen to abort the Game (Keystroke [1])!\n");
        break;
    }
//insert Error Case return #

//   ####       Manage the arrays responsible for the covered Word          ####
   controlValueCoveredWordManagement = coveredWordManagement(guessedLetter, activeWordConverted, uncoveredArray,
                          inputCharsMisses, inputCharsHits);


    //        #####         Check if Game is Won        #####
    unsigned int uncoveredLettersCounter = 0;
    for (unsigned int i = 0; i < wordLength; ++i) {
        if(uncoveredArray[i] == 1)
            uncoveredLettersCounter++;
    }
    if(uncoveredLettersCounter == wordLength){
        printf("\n");
        printVariablyCoveredWord(wordLength, uncoveredArray, activeWordConverted);
        printf("!! CONGRATULATIONS, you guessed the Word !!\n\n");
        return gameWon;
    }

        //END        #####         Check if Game is Won        #####


#if DEBUG2
    printf("DB The guessed Letter is: %c", guessedLetter);
#endif

 //count the misses
if (controlValueCoveredWordManagement == 2) //2 stands for input letter not contained in guess-word
tryCounter--; //decrement try-counter to keep track on how many guesses have been made

  if(tryCounter == 0) {
      printf("You ran out of trys, GAME OVER!\n\n");
      return gameLost;
  }
} // End Round-loop while

//      FREE Spot
    free(inputCharsHits);
    free(activeWordConverted);
    free(uncoveredArray);

    return gameUnpredictedBehavior;
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

        //loop to check if misses char has already been added to misses array so no double entries
        unsigned long lengthOfMissesArray = strlen(misses);
        short int charAlreadyInArrayMarker = 0;
        for (unsigned long i = 0; i < lengthOfMissesArray; ++i) {
            if(stringToAppend[0] == misses[i])
                charAlreadyInArrayMarker++;
        }
        if(charAlreadyInArrayMarker == 0)
        strcat(misses, stringToAppend);

          return 2;
    }

    return 0;
}

