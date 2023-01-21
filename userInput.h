//
// Created by Michi on 27.12.2022.
//

/**
 * \brief
 * This file is responsible for managing the different scenarios in which the player interacts with the game
 */

/**
* \file
 */


#ifndef HANGMAN_USERINPUT_H
#define HANGMAN_USERINPUT_H

#endif //HANGMAN_USERINPUT_H

#include "stdio.h"
#include <stdbool.h>
#include <getopt.h> //included because -std=c99 flag messes up getOpt compiling with GCC

/**
* \brief
 *
*initiates the start sequence, prints out an introduction to the game
*
* \param void this function does not require an input parameter
* \return
*0: the user has selected to run the program
*1: Abort the Programm execution
*2: Error
*/
int startSequence(void);

/**
* \brief
 *
*used in start sequence
*returns the following chars while dealing with wrong user Input
 *
* \param void this function does not require an input parameter
* \return
*e: to edit the word-input file
*q: quit
*s: start
*I: wrong input
*/
unsigned char getSingleChar(void);


/**
* \brief
 *
*Function which manages com line Arguments
 *
* \param active_Word the chosen guess-word
 * \param argc argument count
 * \param argv argument vector
 * \param activateFileInput boolean used to limit the function call to 1 in the caller loop
* \return
 * Return 1 = file input chosen
 * Return -1 = Error
*/

short int commLineArgManagement(char* active_Word,int argc, char **argv,bool * activateFileInput);

/**
* \brief
 *
*lets user guess letters during game runtime
 *
* \param controlValue return of a control value for special input:
 * 1: user selected to quit
 * 2: user selected to guess the whole word
* \return
 * return-value # if error in function
 * return Value + if control char has been entered
*/

char letUserGuessLetters(short int *controlValue);

/**
* \brief
 *
*allows the User to enter a "String", used during game runtime
 * used for guessing of the whole word part of the assignment
 *
* \param wordLength length of the word which can be entered
 * \param returnWord returns the word which the user selected
 *
* \return
 * 0: word was chosen
 * 1: incorrect input
*/

short int getWord(unsigned short wordLength, char *returnWord);
