//
// Created by osboxes on 06/01/23.
//
/** \file  File for handling the input file
 *  \brief
 *  -reads out information from the file
 *  -chooses an input word
 * - marks used words
 */

#ifndef HANGMAN_WORDINPUTFILE_H
#define HANGMAN_WORDINPUTFILE_H

#endif //HANGMAN_WORDINPUTFILE_H

#define FILE_HEADER_OFFSET 316//offset for the allready printed part in the Input File
#define SIZE_MARKERS 3// define the size of the Word Flags
#define MAX_WORD_SIZE_FILE 40 //limit to the wordLength in the file
#define MAX_WORD_COUNT_FILE 50 //limit to the amount of guessWords in the File

/**\file functions for reading input from the WordGuessFile
 * \brief function which retrieves a guessword from the input file
 * @param activeWord the string which represents the chosen wordd
 * @return returns 0 if finished successfully
 */
short int getTheWordFromTheInputFile(char **activeWord);

void createAnInputFileIfNoneExists(void);

short int generateFileInformation(unsigned short int *wordCount,
                                  char wordArray[MAX_WORD_COUNT_FILE][MAX_WORD_SIZE_FILE] ,short int *wordArrayMarkers);

short int writeMarkerInFile(char usedWord[MAX_WORD_SIZE_FILE]);

