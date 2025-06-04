cmake_minimum_required(VERSION 3.30)
project(2048 C)

set(CMAKE_C_STANDARD 99)

add_executable(2048
        main.c
        move.c
        board.c
        clearScreen.c
        move.h
        board.h
        clearScreen.h
)
