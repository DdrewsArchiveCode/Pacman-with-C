// Files for function that are used for the pacman code

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
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
void levelBuild (char board[HEIGHT][WIDTH], int *playerX, int *playerY, struct ghost *head) {
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
            // Need further correction, in order to integrate it with the linked list
            head = inputGhost(coorX, coorY, board, head);
        }

        printBoard(board);
        printf ("Input the command that you wish: ");
        scanf(" %c %d %d", &input, &coorX, &coorY);
        input = tolower(input);
    }

    printf("Input the player innitial position: ");
    scanf("%d%d", &playerX, &playerY);
    board[*playerX][*playerY] = PACMAN;
}


// Function to compute movement mechanic
void movementMechanic (char board[HEIGHT][WIDTH], 
                        int *playerX, int *playerY) {
    char mechanic;
    int checker = TRUE;

    while (checker = TRUE) {
        printf("Movement command: ");
        scanf(" %c", mechanic);
        mechanic = tolower(mechanic);

        if (mechanic == 'w') {
            movementW(board, playerX, playerY);
        } else if (mechanic == 's') {
            movementS(board, playerX, playerY);
        } else if (mechanic == 'd') {
            movementD(board, playerX, playerY);
        } else if (mechanic == 'a') {
            movementA(board, playerX, playerY);
        }
        checker = winCondition(board);
    }
}

// Function to move player 1 step to the left
void movementA (char board[HEIGHT][WIDTH], int *playerX, int *playerY) {
    board[*playerX][*playerY] = EMPTY;
    *playerX++;
    board[*playerX][*playerY] = PACMAN;
}

// Function to move player 1 step to the right
void movementD (char board[HEIGHT][WIDTH], int *playerX, int *playerY) {
    board[*playerX][*playerY] = EMPTY;
    *playerX--;
    board[*playerX][*playerY] = PACMAN;
}

// Function to move player 1 step downward
void movementS (char board[HEIGHT][WIDTH], int *playerX, int *playerY) {
    board[*playerX][*playerY] = EMPTY;
    *playerY--;
    board[*playerX][*playerY] = PACMAN;
}

// Function to move player 1 step upward
void movementW (char board[HEIGHT][WIDTH], int *playerX, int *playerY) {
    board[*playerX][*playerY] = EMPTY;
    *playerY++;
    board[*playerX][*playerY] = PACMAN;
}

// Function that add walls
void inputWall(int coorX, int coorY, char board[HEIGHT][WIDTH]) {
    board[coorY][coorX] = WALL;
}

// Function that add ghost
struct ghost *inputGhost(int coorX, int coorY, 
                char board[HEIGHT][WIDTH], struct ghost *head) {
    struct ghost *new = malloc(sizeof(struct ghost));
    new->coorX = coorX;
    new->coorY = coorY;
    new->next = NULL;
    if (head = NULL) {
        head = new;
    } else {
        head = append(new, head);
    }
    board[coorY][coorX] = GHOST;
    return head;
}

// To append every new ghost from level builder to the end the linked list
struct ghost *append (struct ghost *new, struct ghost *head) {
    struct ghost *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new;
    return head;
}

// Funtion that check the winning condition
int winCondition (char board[HEIGHT][WIDTH]) {
    char boardCp[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            boardCp[i][j] = board[i][j];
        }
    }
    
    int check = 0;
    if (check > 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}