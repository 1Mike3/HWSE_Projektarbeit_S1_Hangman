//
// Created by Michi on 27.12.2022.
//

#ifndef HANGMAN_GAMEIMPLEMENTATION_H
#define HANGMAN_GAMEIMPLEMENTATION_H

#endif //HANGMAN_GAMEIMPLEMENTATION_H

//enum containing the return Values of the game runtime function
enum returnValuesGameRuntime{
    gameWon = 0,
    gameLost = 1,
    gameUnpredictedBehavior = 2,
    gameRuntimeError = 3,
    gameUserDecidedToQuit = 4,
};

int gameRuntime(char *activeWord);
void printVariablyCoveredWord(unsigned long long wordSize,const short int *uncoveredArray, char *activeWord);
short int coveredWordManagement(char inputChar, char *convertedWord, short int *uncoveredArray,
                          char *misses,  char *hits);
