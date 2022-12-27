//
// Created by Michi on 27.12.2022.
//

#include "userInput.h"

/*
Start sequence, meaning of return value:
 0: the user has selected to run the program
 1: Abort the Programm execution
 2: Error
*/
int startSequence() {

    static int textFormat = 0; //prints out a different textblock depending on if this is the first function call


    if (textFormat == 0) { // text on first call
        //start block to be printed on every Programm start
        printf("======= HANGMAN =======\n");
        printf("Welcome to my version of the Hangman-Game!\n");
        printf("Press \"s\" to start the Game / press \"q\" to quit the program\n");
    }
    if (textFormat == 1) { //text on the following calls
    printf("Do you want to Play another Game?\n");
    printf("Press \"s\" to start a new Game / press \"q\" to quit\n");
}
    textFormat = 1;//set to 1 so different text on following calls

    //#### start control character input ####
    unsigned char controlCharacter = getSingleChar(); //get the formatted char from the get single char function
    short int wrongInputCounter = 0; //if there are more than 5 wrong inputs the Program stops

    //I is the "invalid input" return of the getSingleChar function
    while (controlCharacter == 'I'){ //try again if there has been a wrong input
        if(wrongInputCounter == 4){ //abort if too many wrong inputs (4 because first input outside of loop)
            printf("Too many wrong Inputs, the programm stops now!\n");
            return 1;
        }
        wrongInputCounter++; //increment counter so know how many wrong inputs
        controlCharacter = getSingleChar();//trying again after wrong input
    }

    //generate the return value
    if(controlCharacter == 's'){
        return 0;
    }
    if(controlCharacter == 'q'){
        return 1;
    } else{
        return 2; // error something went wrong if this is the return value
    }

}


//returns the following chars while dealing with wrong user Input:
//q: quit
//s: start
//I: wrong input
unsigned char getSingleChar(){
    unsigned char userInput = (int) getchar(); //main input char
    unsigned char enterCatcher = (int) getchar(); // temp var to catch the \n input and check if only one char has been entered

    int loopcounter = 0; //counts the amount of chars other than enter

    while (enterCatcher != '\n' && enterCatcher != '\r') { //loop till enter has been pressed
        enterCatcher = (int) getchar();//catch the second input
        loopcounter++;
    }

    if(loopcounter != 0){ //checking if more than one letter in input
        printf("invalid input or more than one letter, try again!\n");
        return 'I';
    }


    if(userInput == 'q' || userInput == 'Q'){ //Interpreting of the user-input
            return 'q';
        }else if(userInput == 's' || userInput == 'S'){
        return 's';
    } else{
        printf("invalid input or more than one letter, try again!\n");
        return 'I';
    }

}