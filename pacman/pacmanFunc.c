// Files for function that are used for pacman.c
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include "pacman.h"

// Function to initialize the board
void initializeBoard (struct tile board[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == 0 || i == HEIGHT - 1 || 
                j == 0 || j == WIDTH - 1) {
                board[i][j].space = WALL; // Create walls
            } else {
                board[i][j].space = DOT; // Fill the other with dot(point)
            }
            board[i][j].ghost = FALSE;
            board[i][j].player = FALSE;
        }
    }
}

// Function to initialize ghost struct
void initializeGhost (struct ghost gh[GHOSTMAX]) {
    for(int i = 0; i <= GHOSTMAX; i++) {
        gh[i].ghost = FALSE;
    }
}

// Function to print the board
void printBoard (struct tile board[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            struct tile curr = board[i][j];
            if (curr.ghost == TRUE) {
                printf(" G ");
            } else if (curr.player == TRUE) {
                printf("^-^");
            } else if (curr.space == WALL) {
                printf(" %c ", WALL);
            } else if (curr.space == DOT) {
                printf(" %c ", DOT);
            } else {
                printf(" %c ", EMPTY);
            }
        }
        printf("\n");
    }
}

// Function for user to setup their own level
void levelBuild (struct tile board[HEIGHT][WIDTH], int *playerX, 
                    int *playerY, struct ghost gh[GHOSTMAX]) {
    char input = 'c';
    int coorX = 0;
    int coorY = 0;

    printf("=== Welcome to level building phase! ===\n");
    printf("Level Building Dictionary: \n"
            "w = building a single wall \n"
            "g = adding a ghost in the board\n"
            "q = quit level building phase\n"
            "input format: [command] [coor x] [coor y]\n"
        );

    printf ("Input the command that you wish: ");
    scanf(" %c", &input);
    input = tolower(input);
    
    while (input != 'q') {
        scanf("%d%d", &coorY, &coorX); //edited
        if (input == 'w') {
            inputWall(coorX, coorY, board);
        } else if (input == 'g') {
            inputGhost(board, gh, coorX, coorY);
        }

        printBoard(board);
        printf ("Input the command that you wish: ");
        scanf(" %c", &input);
        input = tolower(input);
    }
    
    printBoard(board);
    int loopCheck = TRUE;
    while(loopCheck == TRUE) {
        printf("Input the player initial position: ");
        scanf("%d%d", playerX, playerY);

        if (board[*playerX][*playerY].ghost != TRUE && board[*playerX][*playerY].space != WALL) {
            board[*playerX][*playerY].player = TRUE;
            loopCheck = FALSE;
        } else {
            printf("Invalid player position\n");
        }

    }
    printBoard(board);
}

// Function to input ghost in the board
void inputGhost (struct tile board[HEIGHT][WIDTH], struct ghost gh[GHOSTMAX], 
                int coorX, int coorY) {
    int i = 0;
    while ( gh[i].ghost == FALSE) {
        i++;
    }
    gh[i].coorX = coorX;
    gh[i].coorY = coorY;
    gh[i].ghost = TRUE;
    board[gh[i].coorX][gh[i].coorY].ghost = TRUE;
}

// Function to compute movement mechanic
void movementMechanic (struct tile board[HEIGHT][WIDTH], 
                        int *playerX, int *playerY, 
                        struct ghost gh[GHOSTMAX]) {
    char mechanic;
    int checker = TRUE;

    printf("Movement command: ");
    while (checker == TRUE) {
        scanf(" %c", &mechanic);
        mechanic = tolower(mechanic);
        computingMovementMechanic(board, mechanic, 
                        playerX, playerY, &checker, gh);
    }

    if (checker == FALSE) {
        printf("=== Congrats! You win the game ===\n");
    } else if (checker == EXTRAFALSE) {
        printf("=== Sorry, you've lost the game ===\n");
    }
}

// Extended function of movementMechanic 
void computingMovementMechanic (struct tile board[HEIGHT][WIDTH], 
                                char mechanic, int *playerX, 
                                int *playerY, int *checker, 
                                struct ghost gh[GHOSTMAX]) {
    if (validCheck(board, mechanic, playerX, playerY) == TRUE) {
        if (mechanic == 'w') {
            movementW(board, playerX, playerY);
        } else if (mechanic == 's') {
            movementS(board, playerX, playerY);
        } else if (mechanic == 'd') {
            movementD(board, playerX, playerY);
        } else if (mechanic == 'a') {
            movementA(board, playerX, playerY);
        }

        printBoard(board);
        ghostMovement(board, gh);
        *checker = winCondition(board);
        if (*checker == TRUE) {
            printf("Movement command: ");
        }
    } else {
        printBoard(board);
        *checker = winCondition(board);
        if (*checker == TRUE) {
            printf("The designated command "
                "is invalid, please enter"
                " another command: ");
        }
    }
}

// Function to move player 1 step to the left
void movementA (struct tile board[HEIGHT][WIDTH], int *playerX, int *playerY) {
    board[*playerX][*playerY].space = EMPTY;
    board[*playerX][*playerY].player = FALSE;
    *playerY = *playerY - 1;
    if (board[*playerX][*playerY].space == DOT) {
        board[*playerX][*playerY].space = EMPTY;
    }
    board[*playerX][*playerY].player = TRUE;
}

// Function to move player 1 step to the right
void movementD (struct tile board[HEIGHT][WIDTH], int *playerX, int *playerY) {
    board[*playerX][*playerY].space = EMPTY;
    board[*playerX][*playerY].player = FALSE;
    *playerY = *playerY + 1;
    if (board[*playerX][*playerY].space == DOT) {
        board[*playerX][*playerY].space = EMPTY;
    }
    board[*playerX][*playerY].player = TRUE;
}

// Function to move player 1 step downward
void movementS (struct tile board[HEIGHT][WIDTH], int *playerX, int *playerY) {
    board[*playerX][*playerY].space = EMPTY;
    board[*playerX][*playerY].player = FALSE;
    *playerX = *playerX + 1;
    if (board[*playerX][*playerY].space == DOT) {
        board[*playerX][*playerY].space = EMPTY;
    }
    board[*playerX][*playerY].player = TRUE;
}

// Function to move player 1 step upward
void movementW (struct tile board[HEIGHT][WIDTH], int *playerX, int *playerY) {
    board[*playerX][*playerY].space = EMPTY;
    board[*playerX][*playerY].player = FALSE;
    *playerX = *playerX - 1;
    if (board[*playerX][*playerY].space == DOT) {
        board[*playerX][*playerY].space = EMPTY;
    }
    board[*playerX][*playerY].player = TRUE;
}

// Function that add walls
void inputWall(int coorX, int coorY, struct tile board[HEIGHT][WIDTH]) {
    board[coorX][coorY].space = WALL;
}

// Funtion that check the winning condition
int winCondition (struct tile board[HEIGHT][WIDTH]) {
    int count = 0;
    int pacmanpos = 0;
    
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (board[i][j].space == DOT) {
                count++;
            }

            if (board[i][j].player == TRUE) {
                pacmanpos = TRUE;
            }
        }
    }

    // Returning value for winning condition
    if (pacmanpos != TRUE) {
        return EXTRAFALSE;
    } else if (count > 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}

// Function to compute Ghost Movement
void ghostMovement (struct tile board[HEIGHT][WIDTH], struct ghost gh[GHOSTMAX]) {
    srand(time(NULL));
    int move = rand() % GHOSTMOVEOPTION;
    printf("ghost move: %d\n", move);
    for (int i = 0; gh[i].ghost == TRUE; i++) { 
        if (move == GHOSTD) {
            board[gh[i].coorX][gh[i].coorY].ghost = FALSE;
            gh[i].coorY++;
            board[gh[i].coorX][gh[i].coorY].ghost = TRUE;
        } else if (move == GHOSTW) {
            board[gh[i].coorX][gh[i].coorY].ghost = FALSE;
            gh[i].coorX++;
            board[gh[i].coorX][gh[i].coorY].ghost = TRUE;
        } else if (move == GHOSTA) {
            board[gh[i].coorX][gh[i].coorY].ghost = FALSE;
            gh[i].coorY--;
            board[gh[i].coorX][gh[i].coorY].ghost = TRUE;
        } else {
            board[gh[i].coorX][gh[i].coorY].ghost = FALSE;
            gh[i].coorX--;
            board[gh[i].coorX][gh[i].coorY].ghost = TRUE;
        }
    }
}

// Function to check if ghost movement is valid
int checkGhost(struct tile board[HEIGHT][WIDTH], int move, 
                struct ghost gh[GHOSTMAX]) {
    
}

// Function to check if the movement is valid
int validCheck (struct tile board[HEIGHT][WIDTH], char input, 
                int *coorX, int *coorY) {
    if (input == moveW && 
        board[*coorX - 1][*coorY].space == WALL) {
        return FALSE;
    } else if (input == moveA && 
                board[*coorX][*coorY - 1].space == WALL) {
        return FALSE;
    } else if (input == moveS && 
                board[*coorX + 1][*coorY].space == WALL) {
        return FALSE;
    } else if (input == moveD && 
                board[*coorX][*coorY + 1].space == WALL) {
        return FALSE;
    }
    return TRUE;
}