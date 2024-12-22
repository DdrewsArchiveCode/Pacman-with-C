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
                board[i][j] = DOT; // Fill with dots
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