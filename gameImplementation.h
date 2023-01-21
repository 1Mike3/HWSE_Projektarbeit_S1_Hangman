//
// Created by Michi on 27.12.2022.
//

/**
 * \brief
 * This file contains the main part of the game.
 * when the user selects to start the game the actual game sequence is
 * contained in this file.
 */


/**
* \file
 */




#ifndef HANGMAN_GAMEIMPLEMENTATION_H
#define HANGMAN_GAMEIMPLEMENTATION_H

#endif //HANGMAN_GAMEIMPLEMENTATION_H


/*!
 * enum containing the return Values of the game runtime function
 */
enum RETURNVALUESGAMERUNTIME{
    GAMEWON = 0,
    GAMELOST = 1,
    GAMEUNPREDICTEDBEHAVIOR = 2,
    GAMERUNTIMEERROR = 3,
    GAMEUSERDECIDEDTOQUIT = 4,
};


/**
* \brief
 *
*main function of this file, implementation of the game
*
* \param activeWord the guessword which has been chosen to play the game
* \return see the enum RETURNVALUESGAMERUNTIME
 *
*
*/
int gameRuntime(char *activeWord);

/**
* \brief
 *
*prints out the word with the uncovered letters to the standard output
*
* \param activeWord the guessword which has been chosen to play the game
 * \param statusWordUncovered the formatted word
 * \param wordSize size of the guess-word
 * \param uncoveredArray array which contains a 1 if the letter is uncovered
 * and a 0 if the word has not been uncovered.
* \return void, this function does not return a value
 *
*
*/
void printVariablyCoveredWord(unsigned short wordSize,const short int *uncoveredArray,
                              char *activeWord, char *statusWordUncovered);
/**
* \brief
 *
*function to manage the Letter input and adjust the different Word-Arrays accordingly.
*
* \param inputChar the Char which has been entered by the user in the caller function.
 * \param uncoveredArray array which contains a 1 if the letter is uncovered .
 * \param convertedWord guess-word converted to UPPERCASE.
 * \param misses consists of a "string" which contains the wrong guesses of the user.
 * \param StatusWordForDataLogging contains converted word for better looking save to logfile.
* \return
 *0: if finished successfully and word has been correctly guessed.
 *1: if falied.
 *2: if no word has been correctly guessed.
*
*/
short int coveredWordManagement(char inputChar, char *convertedWord, short int *uncoveredArray,
                                char *misses, char *StatusWordForDataLogging);

/**
* \brief
 *
*sequence which activates the option to let the user guess a whole word
*
* \param activeWordConvert guess-word converted to UPPERCASE.
 * \param activeWordLength contains the length of the previous parameter
* \return
 * 1: user guessed correctly
 *2: user guessed incorrectly
 *3: function error
*/


//1: user guessed correctly
//2: user guessed incorrectly
//3: function error
short int sequenceLetUserGuessWord(char * activeWordConvert, unsigned short activeWordLength);

