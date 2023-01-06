cmake_minimum_required(VERSION 3.23)
project(hangman C)

set(CMAKE_C_STANDARD 99)

add_executable(hangman main.c userInput.c userInput.h dataLogging.c dataLogging.h gameImplementation.c gameImplementation.h errorManagement.c errorManagement.h helperFunctions.c helperFunctions.h helperFunctions.c wordInputFile.c wordInputFile.h)

#custom gcc flags
set(GCC_COVERAGE_COMPILE_FLAGS "-std=c99 -Wall -Wextra -pedantic -Wno-unused-parameter")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )