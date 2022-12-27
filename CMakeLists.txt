cmake_minimum_required(VERSION 3.23)
project(hangman C)

set(CMAKE_C_STANDARD 99)

add_executable(hangman main.c userInput.c userInput.h dataLogging.c dataLogging.h gameImplementation.c gameImplementation.h)
