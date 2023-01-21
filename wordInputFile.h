//
// Created by osboxes on 06/01/23.
//



/**
 * \brief
 *  -reads out information from the file.
 *  -chooses an input word.
 * - marks used words.
 */

/**
* \file
 */


#ifndef HANGMAN_WORDINPUTFILE_H
#define HANGMAN_WORDINPUTFILE_H

#endif //HANGMAN_WORDINPUTFILE_H

#define FILE_HEADER_OFFSET 316//offset for the allready printed part in the Input File
#define SIZE_MARKERS 3// define the size of the Word Flags
#define MAX_WORD_SIZE_FILE 40 //limit to the wordLength in the file
#define MAX_WORD_COUNT_FILE 50 //limit to the amount of guessWords in the File


/**
* \brief
 *
*main function of the file.
*
* \param activeWord return of the word from the file.
* \return
*RETURNNOAVAILABLEINPUTWORDS (10) if there are no available words in the file.
 * RETURNFINISHEDSUCCESSFULLY (0) if the function was executed sucessfully.
*/
short int getTheWordFromTheInputFile(char **activeWord);


/**
* \brief
 *
*function to create the file which contains the guess-words on the first program start if the file doesn't exist.
*
* \param void this function does not require an input parameter.
* \return void, this function does not return a value.
*/

void createAnInputFileIfNoneExists(void);

/**
* \brief
*
*writes different Information from the file into the value arrays.
* which are passed as Parameters, and counts the amount of words contained in the file.
*
* \param wordCount contains the numbwer of words in the file.
 * \param wordArray contains all the words from the file.
 * \param wordArrayMarkers contains an array with numbers representing the control characters from the input file.
* \return
 * 0: if executed successfully .
 * -1: if an error occurred.
*/

short int generateFileInformation(unsigned short int *wordCount,
                                  char wordArray[MAX_WORD_COUNT_FILE][MAX_WORD_SIZE_FILE] ,short int *wordArrayMarkers);


/**
* \brief
*
*writes detected Word marker in place of the current marker after the usedWord in the file.
*
* \param usedWord chosen word for which the marker in the file will be set.
* \return
 * 0: if executed successfully .
 * -1: if an error occurred.
*/

short int writeMarkerInFile(char usedWord[MAX_WORD_SIZE_FILE]);

