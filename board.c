//
// Created by ramsa on 10/21/2025.
//

#include "bitboard.h"

void initBoard(GameBoard *board) {
    // Simple setup: top 3 rows = player2, bottom 3 rows = player1
    board->player1Pieces = 0x00000FFF00000000ULL;
    board->player2Pieces = 0x00000000000FFF00ULL;
    board->player1Kings = 0ULL;
    board->player2Kings = 0ULL;
    board->currentTurn = 1;
}

void printBoard(const GameBoard *board) {
    printf("\n  BitBoard Checkers\n");
    printf("  -----------------\n");

    for (int i = 63; i >= 0; i--) {
        if ((board->player1Pieces >> i) & 1ULL) printf(" R ");
        else if ((board->player2Pieces >> i) & 1ULL) printf(" B ");
        else if ((board->player1Kings >> i) & 1ULL) printf(" K ");
        else if ((board->player2Kings >> i) & 1ULL) printf(" Q ");
        else printf(" . ");

        if (i % 8 == 0) printf("\n");
    }
    printf("\n");
}

int isOccupied(const GameBoard *board, int position) {
    unsigned long long all = board->player1Pieces | board->player2Pieces |
                             board->player1Kings | board->player2Kings;
    return (all >> position) & 1ULL;
}
