//
// Created by Michi on 27.12.2022.
//

#ifndef HANGMAN_ERRORMANAGEMENT_H
#define HANGMAN_ERRORMANAGEMENT_H

#endif //HANGMAN_ERRORMANAGEMENT_H

enum errorCodes{
    ERStartSequenceRet = 100, //start sequence returned a value it should not return during normal operation (2)
    ERStartSequenceDef = 101, //default of switch-case after start sequence

    ERNotEnoughInputArgs = 102, //the User has not submitted an argument on the command line
    ERMoreThanOneInputArg = 103, //the User has entered more than one Input Arg
};

void errorManagement(int errorCode);

