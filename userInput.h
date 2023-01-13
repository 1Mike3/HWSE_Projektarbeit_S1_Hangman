//
// Created by Michi on 27.12.2022.
//

#ifndef HANGMAN_USERINPUT_H
#define HANGMAN_USERINPUT_H

#endif //HANGMAN_USERINPUT_H

#include "stdio.h"
#include <stdbool.h>

int startSequence(void);
unsigned char getSingleChar(void);
char *commLineArgManagement(int argc, char **argv,bool * activateFileInput);
char letUserGuessLetters(short int *controlValue);
short int getWord(unsigned long long wordLength, char *returnWord);
