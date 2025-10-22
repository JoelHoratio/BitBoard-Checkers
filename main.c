#include <stdio.h>
#include "bitboard.h"

int main() {
    GameBoard board;
    initBoard(&board);
    printBoard(&board);

    printf("Welcome to BitBoard Checkers!\n");

    int from, to;
    while (1) {
        printf("Player %d, enter move (from to): ", board.currentTurn);
        scanf("%d %d", &from, &to);

        if (!makeMove(&board, from, to)) {
            printf("Invalid move. Try again.\n");
            continue;
        }

        printBoard(&board);

        int winner = checkWin(&board);
        if (winner) {
            printf("Player %d wins!\n", winner);
            break;
        }
    }

    return 0;
}
