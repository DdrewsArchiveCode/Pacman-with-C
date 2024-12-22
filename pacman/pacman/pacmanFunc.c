// Files for function that are used for the pacman code

#include <stdio.h>
#include "pacman.h"

// Function to initialize the board
void initializeBoard (char board[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) {
                board[i][j] = WALL; // Create walls
            } else {
                board[i][j] = EMPTY; // Fill with nothing
            }
        }
    }
}

// Function to print the board
void printBoard (char board[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function for user to setup their own level
void levelBuild (char board[HEIGHT][WIDTH]) {
    return;
}

// Function to compute movement mechanic
void movementMechanic (char board[HEIGHT][WIDTH]) {
    return;
}
