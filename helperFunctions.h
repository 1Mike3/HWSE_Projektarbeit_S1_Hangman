//
// Created by osboxes on 31/12/22.
//


#ifndef HANGMAN_HELPERFUNCTIONS_H
#define HANGMAN_HELPERFUNCTIONS_H

#endif //HANGMAN_HELPERFUNCTIONS_H

/**
 * \brief
 * this file contains little helper functions which can not be clearly assigned to another file.
 */

/**
* \file
 */



/**
* \brief
 *
*this function checks if a submitted char is a prt of the Alphabet (UPPER or lowercase)
*
* \param letterToBeChecked well if this is kinda self-explanatory
* \return returns the char in uppercase format, and # if the function failed
 *
*
*/
char checkIfCharPartOfAlphabet(unsigned char letterToBeChecked);

/**
* \brief
 *
*converts a word into uppercase using the toupper function
*
* \param wordToBeConverted the Uppercase version of the converted word.
 * \param convertedWord the converted word.
 *\param stringLength the length of the word to be converted.
* \return returns the char in uppercase format, and # if the function failed
 *
*
*/
void convertInputWordToUppercase(char *wordToBeConverted,char *convertedWord,unsigned short stringLength);
/**
* \brief
 *
*checks if word entered according to input criteria (alphabet 26 upper and lower)
*
* \param word the word which will be checked
* \return
 * 0: the word is incorrect
 *1: the word is correct
*/
int checkWord(char *Word);
/**
* \brief
 *
*generates a random integer from 0 to the max value
*
* \param max the maximum value which can be returned
* \return returns the randomly* generated number
 *
*/
int generateRandomNumber(int max);
/**
* \brief
 *
*prints a manual file on startup if it doesn't exist
*
* \param void does not require a parameter
* \return void, does not have a return value
 *
*/
void printManualInFileOnStartup(void);

/**
* \brief
 *
*function which prints out a file to the standard output
*
* \param filename name of the file to be printed
* \return
 *0: if it worked
 *1: if an error occurred
*/
short int printFileTOConsole(char* filename);
