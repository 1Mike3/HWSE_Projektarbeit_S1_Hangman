//
// Created by Michi on 27.12.2022.
//

#ifndef HANGMAN_GAMEIMPLEMENTATION_H
#define HANGMAN_GAMEIMPLEMENTATION_H

#endif //HANGMAN_GAMEIMPLEMENTATION_H

//enum containing the return Values of the game runtime function
enum RETURNVALUESGAMERUNTIME{
    GAMEWON = 0,
    GAMELOST = 1,
    GAMEUNPREDICTEDBEHAVIOR = 2,
    GAMERUNTIMEERROR = 3,
    GAMEUSERDECIDEDTOQUIT = 4,
};



int gameRuntime(char *activeWord);


void printVariablyCoveredWord(unsigned short wordSize,const short int *uncoveredArray,
                              char *activeWord, char *statusWordUncovered);

short int coveredWordManagement(char inputChar, char *convertedWord, short int *uncoveredArray,
                                char *misses, char *StatusWordForDataLogging);


short int sequenceLetUserGuessWord(char * activeWordConvert, unsigned short activeWordLength);

