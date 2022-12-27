//
// Created by Michi on 27.12.2022.
//

#include "userInput.h"
/*
Start sequence, meaning of return value:
 0: the user has selected to run the program
 1: Abort the Programm execution

*/
int startSequence(char *userInput){
    printf("======= HANGMAN =======\n");
    printf("Welcome to my version of the Hangman-Game!\n");
    printf("Press \"s\" to start the Game / press \"q\" to quit the Program\n");


    return 0;
}

unsigned char getSingleChar(){


        //q = 113 and s = 115
       // printf("Enter the control character here(s or q): ");
      //  //TODO make the function immune to more than one input
       unsigned char userInput = (int)getchar();
        getchar(); // to catch the enter input
        while(userInput != 'q' && userInput != 'Q'){// loop will only be executed if the user input is incorrect
            if(userInput != 's' && userInput != 'S'){
                //hello
            }
            else{
                break;
            } //till here: check in input either 113 or 115, if not stay in loop

            printf("You entered an incorrect character, try again!\n\n");
            printf("Enter the control character here(s or q): ");
            userInput = getchar();
            getchar(); // to catch the enter input
        }
        if(userInput == 113){
            return 2;
        }
        else if (userInput == 115) {
            return 1;
        }
}