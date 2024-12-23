/*
Made by Deandrew.Y (UNSW student ID z5641581)
Started on 23 December 2024 00:36
With the help of Blackbox AI for board template
*/

#include <stdio.h>
#include "pacman.h"

int main(void) {
    char board[HEIGHT][WIDTH];
    int playerX, playerY;
    initializeBoard(board);
    levelBuild(board, &playerX, &playerY);
    movementMechanic(board, &playerX, &playerY);
    return 0;
}