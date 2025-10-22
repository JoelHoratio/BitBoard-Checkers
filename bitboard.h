#ifndef BITBOARD_H
#define BITBOARD_H

#include <stdio.h>

// ===========================
// Bit Manipulation Functions
// ===========================

unsigned int setBit(unsigned int value, int position);
unsigned int clearBit(unsigned int value, int position);
unsigned int toggleBit(unsigned int value, int position);
int getBit(unsigned int value, int position);

int countBits(unsigned int value);

unsigned int shiftLeft(unsigned int value, int positions);
unsigned int shiftRight(unsigned int value, int positions);

void printBinary(unsigned int value);
void printHex(unsigned int value);


// Board and Game Structures

typedef struct {
    unsigned long long player1Pieces;
    unsigned long long player1Kings;
    unsigned long long player2Pieces;
    unsigned long long player2Kings;
    int currentTurn;
} GameBoard;


// Board Utility Functions

void initBoard(GameBoard *board);
void printBoard(const GameBoard *board);
int isOccupied(const GameBoard *board, int position);


// Game Logic Functions

int makeMove(GameBoard *board, int from, int to);
int checkWin(const GameBoard *board);

#endif
