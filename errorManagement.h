//
// Created by Michi on 27.12.2022.
//



/**
 * \brief
 * file for the handling of the different error behaviors.
 */

/**
* \file
 */



#ifndef HANGMAN_ERRORMANAGEMENT_H
#define HANGMAN_ERRORMANAGEMENT_H
#endif //HANGMAN_ERRORMANAGEMENT_H




//Differentiating between Warning and Error Messages in ErrorManagement Function
#define ERROR 1
#define WARNING 0



/*!
 *
 * //Listing of all the error codes and WaringIDs, start with ER for easier autocomplete
 * //The corresponding Structs Start with EE
 * //find the corresponding struct by searching for usages of the enum elements
 * //manually initialized for better overview of the codes
 */
enum ERRORCODES{
    ERSTARTSEQUENCERET = 100,
    ERSTARTSEQUENCEDEF = 101,
    ERGETOPTUNKNOWNARGUMENT = 102,
    ERUNEXPECTEDGETFILEINFORMATIONFUNCTIONBEHAVIOR = 103,
    ERCOMLINEARGMANAGEMENTFAILED = 104,
    ERINPUTCRITERIANOTMET = 105,
    ERMEMORYALLOCATIONFAILED = 106,
    ERGAMERUNTIMEFUNCTIONFAILED = 107,
    ERFILEMANAGEMENTOPENINGFILEFAILED = 108,
    ERFILEMANAGEMENTOPENINGFILEUNEXPECTEDCONTROLCHARACTER = 109,
    ERWRONGINPUTGETWORDFUNCTION = 110,
    ERDEFAULTSWITCHCASEGUESSWHOLEWORDFUNCTION = 111,
    ERNOUSERINPUTDETECTEDFILE = 112,
    ERDEFAULTGETOPTSWITCHCASE = 113,
    ERGETOPTMISSINGARGUMENT = 114,
    ERERRORWHILEOPENINGFILESTREAM = 115,
};

/*!
 * creating a struct for easier Error Management
 */

typedef struct errorStruct {
    short int code;
   char message[150];
}errorStruct;

/*!
 * Error struct references
 */
extern const errorStruct EEMemoryAllocationFailed;
extern const errorStruct EEDefaultSwitchCaseGuessWholeWordSequence;
extern const errorStruct EEDefaultGetOptSwitchCase;
extern const errorStruct EEGetOptUnknownArgument;
extern const errorStruct EEInputCriteriaNotMet;
extern const errorStruct EEWrongInputGetWordFunction;
extern const errorStruct EEFileManagementOpeningLogfileFailed;
extern const errorStruct EEFileManagementOpeningLogfileUnexpectedControlInput;
extern const errorStruct EEStartSequenceReturn;
extern const errorStruct EEStartSequenceDefault;
extern const errorStruct EECommandLineArgumentFunctionFailed;
extern const errorStruct EEGameRuntimeFailed;
extern const errorStruct EENoInputDetectedFile;
extern const errorStruct EEGetOptMissingArgument;
extern const errorStruct EEErrorOpeningFileStream;
extern const errorStruct EEUnexpectedGetFileInformationFunctionBehavior;

/*
errorStruct  = {
        .code =  ,
        .message = ""
};
*/


/**
* \brief
 *
*function which prints an error message and a corresponding error code.
*
* \param error struct containing error message and code.
 * \param type constant type if Errror (1) or warning (0), PreProc constant.
* \return
* void, this function does not return a value.
*/
void errorManagement(errorStruct error, short int type);

