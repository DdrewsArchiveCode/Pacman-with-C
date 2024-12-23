// Header file for define, and function prototype

// Line 2-13 is provided by Blackbox AI
#define WIDTH 10
#define HEIGHT 10

// Define the characters for the board
#define EMPTY ' '
#define WALL '#'
#define DOT '.'
#define PACMAN 'P'

void initializeBoard (char board[HEIGHT][WIDTH]);
void printBoard (char board[HEIGHT][WIDTH]);

/* 
    Starting from this line, all of 
    them is my own decalration
*/

// constant
#define GHOST 'G'

//Function Prototype
void levelBuild (char board[HEIGHT][WIDTH]);
// void movementMechanic (char board[HEIGHT][WIDTH]);
void inputWall(int coorX, int coorY, char board[HEIGHT][WIDTH]);
void inputGhost(int coorX, int coorY, char board[HEIGHT][WIDTH]);
