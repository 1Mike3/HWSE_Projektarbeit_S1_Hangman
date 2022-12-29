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
//find the corresponding struckt by serarching for usages of the enum elements
//manually initialized for better overview of the codes
enum errorCodes{
    ERStartSequenceRet = 100,
    ERStartSequenceDef = 101,
    ERNotEnoughInputArgs = 102,
    ERMoreThanOneInputArg = 103,
    ERComLineArgManagementFailed = 104,
    ERInputCriteriaNotMet = 105,

};
// creating a const struct for easier Error Management
typedef const struct errorStruct {
    short int code;
   char message[150];
}errorStruct;



/*
errorStruct  = {
        .code =  ,
        .message = ""
};
*/
void errorManagement(errorStruct error, short int type);

