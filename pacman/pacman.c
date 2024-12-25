/*
Made by Deandrew.Y (UNSW student ID z5641581)
Started on 23 December 2024 00:36
Finished on --
With the help of Blackbox AI for board template
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "pacman.h"

int main(void) {
    char board[HEIGHT][WIDTH];
    int playerX, playerY;
    struct ghost *head = NULL;

    initializeBoard(board);
    levelBuild(board, &playerX, &playerY, head);
    movementMechanic(board, &playerX, &playerY);
    return 0;
}
