//
// Created by Michi on 27.12.2022.
//

#ifndef HANGMAN_USERINPUT_H
#define HANGMAN_USERINPUT_H

#endif //HANGMAN_USERINPUT_H

#include "stdio.h"

int startSequence(void);
unsigned char getSingleChar(void);
char *commLineArgManagement(int argc, char **argv);
char *getWord(void);
int checkWord(char *Word);
