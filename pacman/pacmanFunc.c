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
                board[i][j].space = DOT; // Fill with dot
            }
            board[i][j].ghost = FALSE;
            board[i][j].player = FALSE;
        }
    }
}

// Function to print the board
void printBoard (struct tile board[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            struct tile curr = board[i][j];
            if (curr.player == TRUE) {
                printf("^v^");
            } else if (curr.ghost == TRUE) {
                printf("G ");
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
                    int *playerY, struct ghost *head) {
    char input = 'c';
    int coorX = 0;
    int coorY = 0;

    printf("=== Welcome to level building phase! ===\n");
    printf("Level Building Dictionary: \n"
            "w = building a single wall \n"
            "g = adding a ghost in the board\n"
            "q = quit level building phase\n");

    printf ("Input the command that you wish: ");
    scanf(" %c", &input);
    input = tolower(input);
    
    while (input != 'q') {
        scanf("%d%d", &coorY, &coorX); //edited
        if (input == 'w') {
            inputWall(coorX, coorY, board);
        } else if (input == 'g') {
            head = inputGhost(coorX, coorY, board, head);
        }

        printBoard(board);
        printf ("Input the command that you wish: ");
        scanf(" %c", &input);
        input = tolower(input);
    }
    
    printBoard(board);
    printf("Input the player innitial position: ");
    scanf("%d%d", playerY, playerX);
    board[*playerX][*playerY].player = TRUE;
    printBoard(board);
}

// Function to compute movement mechanic
void movementMechanic (struct tile board[HEIGHT][WIDTH], 
                        int *playerX, int *playerY) {
    char mechanic;
    int checker = TRUE;

    printf("Movement command: ");
    while (checker == TRUE) {
        scanf(" %c", &mechanic);
        mechanic = tolower(mechanic);
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
            checker = winCondition(board);
            if (checker == TRUE) {
                printf("Movement command: ");
            }
        } else {
            printBoard(board);
            checker = winCondition(board);
            if (checker == TRUE) {
                printf("The designated command "
                        "is invalid, please enter"
                        " another command: ");
            }
        }
    }

    if (checker == FALSE) {
        printf("=== Congrats! You win the game ===\n");
    } else if (checker == EXTRAFALSE) {
        printf("=== Sorry, you've lost the game ===\n");
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

// Function that add ghost
struct ghost *inputGhost(int coorX, int coorY, 
                struct tile board[HEIGHT][WIDTH], struct ghost *head) {
    struct ghost *new = malloc(sizeof(struct ghost));
    new->coorX = coorX;
    new->coorY = coorY;
    new->next = NULL;
    if (head == NULL) {
        head = new;
    } else {
        head = append(new, head);
    }

    board[coorX][coorY].ghost = TRUE;
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
int winCondition (struct tile board[HEIGHT][WIDTH]) {
    struct tile boardCp[HEIGHT][WIDTH];
    int count = 0;
    int pacmanpos = 0;
    
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            boardCp[i][j] = board[i][j];

            if (boardCp[i][j].space == DOT) {
                count++;
            }

            if (boardCp[i][j].player == TRUE) {
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

void ghostMovement (struct tile board[HEIGHT][WIDTH], struct ghost *head) {
    struct ghost *tmp = head;

    while (tmp != NULL) {
        srand(time(NULL));
        int move = abs(rand() % GHOSTMOVEOPTION);
        if (checkGhost(board, move, tmp) == TRUE) {
            if (move = GHOSTW) {
                board[tmp->coorX][tmp->coorY].ghost = FALSE;
                tmp->coorX--;
                board[tmp->coorX][tmp->coorY].ghost = TRUE;
            } else if (move = GHOSTA) {
                board[tmp->coorX][tmp->coorY].ghost = FALSE;
                tmp->coorY--;
                board[tmp->coorX][tmp->coorY].ghost = TRUE;
            } else if (move = GHOSTS) {
                board[tmp->coorX][tmp->coorY].ghost = FALSE;
                tmp->coorX++;
                board[tmp->coorX][tmp->coorY].ghost = TRUE;
            } else if (move == GHOSTD) {
                board[tmp->coorX][tmp->coorY].ghost = FALSE;
                tmp->coorY++;
                board[tmp->coorX][tmp->coorY].ghost = TRUE;
            }
        }
        tmp = tmp->next;
    }
}

// Function to check if ghost movement is valid
int checkGhost(struct tile board[HEIGHT][WIDTH], int move, 
                struct ghost *tmp) {
    if (move == moveW && 
        board[(tmp->coorX) - 1][(tmp->coorY)].space == WALL) {
        return FALSE;
    } else if (move == moveA && 
                board[(tmp->coorX)][(tmp->coorY) - 1].space == WALL) {
        return FALSE;
    } else if (move == moveS && 
                board[(tmp->coorX) + 1][(tmp->coorY)].space == WALL) {
        return FALSE;
    } else if (move == moveD && 
                board[(tmp->coorX)][(tmp->coorY) + 1].space == WALL) {
        return FALSE;
    }              
    return TRUE;
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