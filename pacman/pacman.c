/*
Made by Deandrew.Y (UNSW student ID z5641581)
Started on 23 December 2024 00:36
Finished on --
*/

#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"

int main(void) {
    struct tile board[HEIGHT][WIDTH];
    int playerX, playerY;
    struct ghost gh[GHOSTMAX];

    initializeBoard(board);
    initializeGhost(gh);
    levelBuild(board, &playerX, &playerY, gh);
    movementMechanic(board, &playerX, &playerY, gh);
    return 0;
}