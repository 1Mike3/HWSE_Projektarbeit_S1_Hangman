//
// Created by Michi on 27.12.2022.
//

#include "errorManagement.h"
#include "stdio.h"
/*
 * Use preProz const
 type 1 = Error
 type 0 = Warning
 */
//function used to print error-codes and messages
//the errorStruct contains the message and the error-code, the type differentiates between warnings and errors

//Error Structs used for generating Error Messages  using the Error Management Function
const errorStruct EEMemoryAllocationFailed = {
        .code = ERMEMORYALLOCATIONFAILED,
        .message = "Heap ran out of Memory!"
};
const errorStruct EEDefaultSwitchCaseGuessWholeWordSequence = {
        .code = ERDEFAULTSWITCHCASEGUESSWHOLEWORDFUNCTION,
        .message = "Exception function let user guess whole word, check switchCase Default!"
};

const errorStruct EEDefaultGetOptSwitchCase = {
        .code = ERDEFAULTGETOPTSWITCHCASE  ,
        .message = "Uexpected GetOpt Behavior, Shutting Down"
};

const errorStruct EEMoreThanOneInputArgument = {
        .code = ERMORETHANONEINPUTARG ,
        .message = "More than one Input Argument has been entered"
};

const errorStruct EEInputCriteriaNotMet = {
        .code = ERINPUTCRITERIANOTMET ,
        .message = "The function which checks the Word for correctness determined it does not meet the requirements"
};

const errorStruct EEWrongInputGetWordFunction = {
        .code = ERWRONGINPUTGETWORDFUNCTION ,
        .message = "Wrong length of the Input Word"
};

const errorStruct EEFileManagementOpeningLogfileFailed = {
        .code =  ERFILEMANAGEMENTOPENINGFILEFAILED,
        .message = "Opening or Creating Logfile failed",
};
const errorStruct EEFileManagementOpeningLogfileUnexpectedControlInput = {
        .code =  ERFILEMANAGEMENTOPENINGFILEUNEXPECTEDCONTROLCHARACTER,
        .message = "Switch case save game progress into log file exception",
};

const errorStruct EEStartSequenceReturn  = {
        .code = ERSTARTSEQUENCERET,
        .message = "start sequence returned a value it should not return during normal operation (2)"
};
const errorStruct EEStartSequenceDefault = {
        .code = ERSTARTSEQUENCEDEF,
        .message = "default of switch-case after start sequence"
};
const errorStruct EECommandLineArgumentFunctionFailed = {
        .code =  ERCOMLINEARGMANAGEMENTFAILED,
        .message = "The ComLineArgManagement function has returned an error"
};
const errorStruct EEGameRuntimeFailed = {
        .code = ERGAMERUNTIMEFUNCTIONFAILED,
        .message = "An Error or Warning has caused the gameRuntime function to fail!"
};
const errorStruct EENoInputDetectedFile = {
        .code = ERNOUSERINPUTDETECTEDFILE ,
        .message = "No Available Guess-Word in WordFile, Game is shutting Down!"
};



void errorManagement(errorStruct error, const short int type){


    //ternary used to differentiate between printout for Warnings and errors
    type ? printf("\n## Runtime Error ##\n") : printf("\n## Warning ##\n");

   type ? printf("Error-code: [ %i ]\n", error.code) : printf("WarningID: [ %i ]\n", error.code);
    printf("[ %s ]\n\n", error.message);

}
