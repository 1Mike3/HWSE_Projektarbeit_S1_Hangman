//
// Created by Michi on 27.12.2022.
//

#ifndef HANGMAN_ERRORMANAGEMENT_H
#define HANGMAN_ERRORMANAGEMENT_H
#endif //HANGMAN_ERRORMANAGEMENT_H




//Differentiating between Warning and Error Messages in ErrorManagement Function
#define ERROR 1
#define WARNING 0



//Listing of all the error codes and WaringIDs, start with ER for easier autocomplete
//The corresponding Structs Start with EE
//find the corresponding struct by searching for usages of the enum elements
//manually initialized for better overview of the codes
enum errorCodes{
    ERStartSequenceRet = 100,
    ERStartSequenceDef = 101,
    ERNotEnoughInputArgs = 102,
    ERMoreThanOneInputArg = 103,
    ERComLineArgManagementFailed = 104,
    ERInputCriteriaNotMet = 105,
    ERMemoryAllocationFailed = 106,
    ERGameRuntimeFunctionFailed = 107,
    ERFileManagementOpeningFileFailed = 108,
    ERFileManagementOpeningFileUnexpectedControlCharacter = 109,
    ERWrongInputGetWordFunction = 110,
    ERDefaultSwitchCaseGuessWholeWordFunction = 111,
    ERNoUserInputDetectedFile = 112,
};


// creating a const struct for easier Error Management
typedef struct errorStruct {
    short int code;
   char message[150];
}errorStruct;

//Error Struct References
extern const errorStruct EEMemoryAllocationFailed;
extern const errorStruct EEDefaultSwitchCaseGuessWholeWordSequence;
extern const errorStruct EENotEnoughInputArguments;
extern const errorStruct EEMoreThanOneInputArgument;
extern const errorStruct EEInputCriteriaNotMet;
extern const errorStruct EEWrongInputGetWordFunction;
extern const errorStruct EEFileManagementOpeningLogfileFailed;
extern const errorStruct EEFileManagementOpeningLogfileUnexpectedControlInput;
extern const errorStruct EEStartSequenceReturn;
extern const errorStruct EEStartSequenceDefault;
extern const errorStruct EECommandLineArgumentFunctionFailed;
extern const errorStruct EEGameRuntimeFailed;
extern const errorStruct EENoInputDetectedFile;

/*
errorStruct  = {
        .code =  ,
        .message = ""
};
*/
void errorManagement(errorStruct error, short int type);

