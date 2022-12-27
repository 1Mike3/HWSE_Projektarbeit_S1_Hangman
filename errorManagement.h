//
// Created by Michi on 27.12.2022.
//

#ifndef HANGMAN_ERRORMANAGEMENT_H
#define HANGMAN_ERRORMANAGEMENT_H

#endif //HANGMAN_ERRORMANAGEMENT_H

enum errorCodes{
    startSequenceRet = 100, //start sequence returned a value it should not return during normal operation (2)
    startSequenceDef = 101 //default of switch-case after start sequence
};

void errorManagement(int errorCode);

