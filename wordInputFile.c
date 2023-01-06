//
// Created by osboxes on 06/01/23.
//

#include "wordInputFile.h"
#include "errorManagement.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


short int getTheWordFromTheInputFile(char** activeWord){
    FILE*file;
    if((file=fopen("hangmanWords.txt","r"))) {
        char *tempString = calloc(MAX_WORD_SIZE_FILE, sizeof (char ));
        fscanf(file, "%s", tempString);


       strcpy(*activeWord, tempString);
        free(tempString);
        fclose(file);


    }else{
        printf("Error");
        //todo usual error stuff + return
        return -1;
    }
    return 0;
}

