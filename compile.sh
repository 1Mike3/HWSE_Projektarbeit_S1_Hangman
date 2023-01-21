#!/bin/bash

gcc -std=c99 -Wall -Wextra -pedantic -Wno-unused-parameter main.c dataLogging.c \
gameImplementation.c helperFunctions.c userInput.c errorManagement.c wordInputFile.c -o GCCHangman

chmod +x GCCHangman