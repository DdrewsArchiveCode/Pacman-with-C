// Files for function that are used for the pacman code

#include <stdio.h>
#include <ctype.h>
#include "pacman.h"

// Function to initialize the board
void initializeBoard (char board[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) {
                board[i][j] = WALL; // Create walls
            } else {
                board[i][j] = DOT; // Fill with dot
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
    char input = 'c';
    int coorX = 0;
    int coorY = 0;

    printf("=== Welcome to level building phase! ===\n");
    printf("Level Building Dictionary: \n"
            "w = building a single wall \n"
            "g = adding a ghost in the board\n");

    printf ("Input the command that you wish: ");
    scanf(" %c %d %d", &input, &coorX, &coorY);
    input = tolower(input);
    
    while (input != 'q') {
        input = tolower(input);
        if (input == 'w') {
            inputWall(coorX, coorY, board);
        } else if (input == 'g') {
            inputGhost(coorX, coorY, board);
        }

        printBoard(board);
        printf ("Input the command that you wish: ");
        scanf(" %c %d %d", &input, &coorX, &coorY);
        input = tolower(input);
    }
}

// // Function to compute movement mechanic
// void movementMechanic (char board[HEIGHT][WIDTH]) {
//     return;
// }

// Function that add walls
void inputWall(int coorX, int coorY, char board[HEIGHT][WIDTH]) {
    board[coorY][coorX] = WALL;
}

// Function that add ghost
void inputGhost(int coorX, int coorY, char board[HEIGHT][WIDTH]) {
    board[coorY][coorX] = GHOST;
}