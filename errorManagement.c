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
void errorManagement(errorStruct error, const short int type){
    //ternary used to differentiate between printout for Warnings and errors
    type ? printf("\n## Runtime Error ##\n") : printf("\n## Warning ##\n");

   type ? printf("Error-code: [ %i ]\n", error.code) : printf("WarningID: [ %i ]\n", error.code);
    printf("[ %s ]\n\n", error.message);

}
