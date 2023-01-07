//
// Created by osboxes on 31/12/22.
//

#ifndef HANGMAN_HELPERFUNCTIONS_H
#define HANGMAN_HELPERFUNCTIONS_H

#endif //HANGMAN_HELPERFUNCTIONS_H

char checkIfCharPartOfAlphabet(unsigned char letterToBeChecked);
void convertInputWordToUppercase(char *wordToBeConverted,char *convertedWord,unsigned long long stringLength);
int checkWord(char *Word);
int generateRandomNumber(int max);
void printManualInFileOnStartup(void);