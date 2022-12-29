//
// Created by Michi on 27.12.2022.
//


#include "gameImplementation.h"

#include "string.h"
#include "stdio.h"
#include "stdlib.h"

#define DEBUG1 0

#define UNDISCOVERED '_'

//Game behavior in runtime after all the checks have been done if another Game can/should start
//returns 0 if Finished successfully and 1 if not
int gameRuntime(char *activeWord){

               //#### Uncovered Value Array ###
    //create An array which contains the Information if a letter was Uncovered or not

    unsigned long long wordLength = strlen(activeWord); //var., contains length of word for uncov.arr. intialization
#if DEBUG1
    printf("DB the length of your Word is: %i \n", wordLength);
#endif

    //undiscovered Char with preprozconst "UNDISCOVERED"
    //1: discovered , 0: undiscovered
    //this array contains the Information if a letter has been discovered by the player or not
short int *uncoveredArray = calloc( wordLength , sizeof(short int));
if(uncoveredArray == NULL){
    //todo malloc error message
    return 1;
}

//              ### start the Game ###
    printVariablyCoveredWord(wordLength, uncoveredArray);

    free(uncoveredArray);
    return 0;
}

void printVariablyCoveredWord(short int wordSize,const short int *uncoveredArray){
    printf("My Word: ");
    for (int i = 0; i < wordSize; ++i) {
        if(*(uncoveredArray+i) == 0){
            printf("_");
        }

    }
    printf("\n\n");
}

//todo implement in User Input
void letUserGuessLetters(void){

}