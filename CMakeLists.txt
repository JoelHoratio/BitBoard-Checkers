cmake_minimum_required(VERSION 4.0)
project(P1 C)

set(CMAKE_C_STANDARD 11)

add_executable(P1 main.c
        bitops.h
        bitops.c
        bitboard.h
        board.c
        game.c)
