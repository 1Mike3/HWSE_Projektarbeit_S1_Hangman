                          ### Manual to my Hangman-Game :)  ###
-!!Configuration-File which contains the guess-words: Hangman_Words.txt (created on startup).

-the program only works with GETOPT now, an argument has to be provided on startup.
(note that the game has to be started with "s" for the entered argument to take effect)

                    -GET-OPT:
                    -default if nothing is entered is to use the wordFile for word input.
                    -press -w and enter a word after it to play using a manually selected guessword.
                    -enter -f to play using the input file
                    -enter -m to display the manual on startup (should be entered with one of the other functions)
                    

-when you encounter a problem with one of the files, delete it and the program will generate a new one on the next startup.

-The \"e\" function in the main menu only works if the program is executed
on linux in the command line, of course you can also open the files manually.

-The WordFile is limited to 40 Words and each word 35 characters max.

-valid input characters letter-guessing (except program control numbers) are 26 lat. alphabet letters (lower or uppercase).

-When too many invalid inputs(eg. AA or &) are made in one try it is counted as a miss.

-during letter guesses, press [1] to quit the game and [2] to guess the whole word.

-!argument options are only considered if start the game is selected

-the format in which the words should be written into the file is printed out in the file header.

-the program returns various error codes and messages if an exception occurs.

-if you select the file option and the input file is empty the game will return an error and you will not be able to play.

-How to Play:

                chose the input arguments which you want to use.
                (see GET-OPT, they are only considered if you press "s" on the next run)
                
                now you can chose between three options which are displayed in the command line
                (not that if you wat to play using the file input, you have to write the words into the file first)
                
                when you press s the game starts, then you can guess letter after letter until you either guessed the word
                or you run out of tries.
                
                The Number 2 can also be pressed to guess the word in one go.
                (note that you will loose the game if you choose wrong)
                
                After that you will be able to start another game.
                
                With the file input option another word from the file will be selected.
                With the -w option you will play again using the same word from the command line.
                
                You can quit the programm by pressing q in the menue.
                To get to the menue during the game you can press 1 to abbort the current game.
                
                
                
                
   
