//
// Created by Michi on 27.12.2022.
//

#ifndef HANGMAN_DATALOGGING_H
#define HANGMAN_DATALOGGING_H

#endif //HANGMAN_DATALOGGING_H

enum returnValueSaveGameProgressToLogFile{
    saveProgressToLogFileFinishedSuccessfully = 0,
    saveProgressToLogFileFailed = 1,
};

enum saveProgressToLogFileControlCharacter{
    controlCharSaveProgressToLog_normalInputSaving = 1,
    controlCharSaveProgressToLog_invalidUserInput = 2,
    controlCharSaveProgressToLog_startOfTheGame = 3,
    controlCharSaveProgressToLog_endOfTheGame = 4,
    controlCharSaveProgressToLog_gameHasBeenWon = 5,
    controlCharSaveProgressToLog_gameHasBeenLost = 6,
};

int saveGameProgressIntoLogFile(char UserInputChar, char* uncoveredWord, short int controlCharacter);
char *getTimeString(void);
