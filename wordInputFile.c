//
// Created by osboxes on 06/01/23.
//

#include "wordInputFile.h"
#include "errorManagement.h"
#include "helperFunctions.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILE_HEADER_OFFSET 295//offset for the allready printed part in the Input File

short int getTheWordFromTheInputFile(char** activeWord){




    FILE*file;
    if((file=fopen("Hangman_Words.txt","a+"))) {
        char *tempString = calloc(MAX_WORD_SIZE_FILE, sizeof (char ));

        //DO This :)
       // generateRandomNumber();


        long tell = ftell(file);
        long seekOffset = FILE_HEADER_OFFSET;
        int seekRet = fseek(file,seekOffset,SEEK_CUR);
        long tell2 = ftell(file);

        fscanf(file, "%s", tempString);

        tell = ftell(file);
        seekOffset = 1;
        seekRet = fseek(file,seekOffset,SEEK_CUR);
        tell2 = ftell(file);

        fscanf(file, "%s", tempString);

        tell = ftell(file);
        seekOffset = 1;
        seekRet = fseek(file,seekOffset,SEEK_CUR);
        tell2 = ftell(file);

        fscanf(file, "%s", tempString);

#endif

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

//
void createAnInputFileIfNoneExists(void) {
    FILE *file;
    if ((file = fopen("Hangman_Words.txt", "r"))) { //check if File Exists
        fclose(file);
    } else { //create file
        if ((file = fopen("Hangman_Words.txt", "w+"))) {
            fprintf(file,"## List of Hangman guess-words ## \n\n -enter guess-words in this Format: \n"
                         "[Word]  [Space]  [#]  [+]\n-the # is a terminating character\n"
                         "-the + is a marker if the word already was used\n"
                         "(write it only if this word should be skipped)"
                         "-max word length is 35 characters\n"
                         "__________________________________\n");
            fclose(file);
            return;
        }else{
            printf("Error big Nono\n");
            //todo usual error stuff
            return;
        }
    }

}