//
// Created by Michi on 27.12.2022.
//

#ifndef HANGMAN_DATALOGGING_H
#define HANGMAN_DATALOGGING_H


#endif //HANGMAN_DATALOGGING_H

/**
 * \brief
 * This file is responsible for the logging of the user input data.
 */


/**
* \file
 */



/*!
 *the return value of the saveGameProgressIntoLogFile function.
 */
enum RETURNVALUESAVEGAMEPROGRESSTOLOGFILE{
    SAVEPROGRESSTOLOGFILEFINISHEDSUCCESSFULLY = 0,
    SAVEPROGRESSTOLOGFILEFAILED = 1,
};

/*!
 *the control character of the saveGameProgressIntoLogFile function.
 */
enum SAVEPROGRESSTOLOGFILECONTROLCHARACTER{
    CONTROLCHARSAVEPROGRESSTOLOG_NORMALINPUTSAVING = 1,
    CONTROLCHARSAVEPROGRESSTOLOG_INVALIDUSERINPUT = 2,
    CONTROLCHARSAVEPROGRESSTOLOG_STARTOFTHEGAME = 3,
    CONTROLCHARSAVEPROGRESSTOLOG_ENDOFTHEGAME = 4,
    CONTROLCHARSAVEPROGRESSTOLOG_GAMEHASBEENWON = 5,
    CONTROLCHARSAVEPROGRESSTOLOG_GAMEHASBEENLOST = 6,
};

/**
* \brief During Runtime: saves the game progress into the log file with a timestamp.
*
*Depending on which control character is used during game runtime(see enum SAVEPROGRESSTOLOGFILECONTROLCHARACTER)
 * a set of different messages is written into the log file (always appending)
*
* \param UserInputChar passing the entered char.
* \param uncoveredWord passing the current state of the guess-word to be saved into the file.
* \return SAVEPROGRESSTOLOGFILEFINISHEDSUCCESSFULLY (0) if finished successfully.
 * \return SAVEPROGRESSTOLOGFILEFAILED (1) if an error occurred.
*
*/
int saveGameProgressIntoLogFile(char UserInputChar, char* uncoveredWord, short int controlCharacter);
/**
* \brief returns the current system time formated as a string
*
*uses the time and ctime functions.
 *
* \param void this function does not require a parameter to be passed
* \return returns the system time and date formated as a "String"
*/
char *getTimeString(void);
