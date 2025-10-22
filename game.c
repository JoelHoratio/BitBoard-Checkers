//
// Created by ramsa on 10/21/2025.
//

#include "bitboard.h"

int makeMove(GameBoard *board, int from, int to) {
    unsigned long long fromMask = 1ULL << from;
    unsigned long long toMask = 1ULL << to;

    if (board->currentTurn == 1 && (board->player1Pieces & fromMask)) {
        board->player1Pieces &= ~fromMask;
        board->player1Pieces |= toMask;
        board->currentTurn = 2;
        return 1;
    }
    else if (board->currentTurn == 2 && (board->player2Pieces & fromMask)) {
        board->player2Pieces &= ~fromMask;
        board->player2Pieces |= toMask;
        board->currentTurn = 1;
        return 1;
    }

    return 0; // invalid move
}

int checkWin(const GameBoard *board) {
    if (board->player1Pieces == 0 && board->player1Kings == 0) return 2;
    if (board->player2Pieces == 0 && board->player2Kings == 0) return 1;
    return 0;
}
