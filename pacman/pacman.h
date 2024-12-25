// Header file for define, and function prototype

// Line 4-14 is provided by Blackbox AI
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

// Struct 
struct ghost {
    int coorX;
    int coorY;
    struct ghost *next;
};

//Constant
#define GHOST 'G'
#define TRUE 1
#define FALSE 0
#define EXTRAFALSE 2
#define MAXCAP 10
#define MINCAP 0
#define GHOSTMOVEOPTION 4

//Function Prototype
void levelBuild (char board[HEIGHT][WIDTH], int *playerX, int *playerY, struct ghost *head);
void movementMechanic (char board[HEIGHT][WIDTH], int *playerX, int *playerY);
void inputWall(int coorX, int coorY, char board[HEIGHT][WIDTH]);
void movementW(char board[HEIGHT][WIDTH], int *playerX, int *playerY);
void movementA (char board[HEIGHT][WIDTH], int *playerX, int *playerY);
void movementD (char board[HEIGHT][WIDTH], int *playerX, int *playerY);
void movementS (char board[HEIGHT][WIDTH], int *playerX, int *playerY);
struct ghost *inputGhost(int coorX, int coorY, char board[HEIGHT][WIDTH], struct ghost *head);
struct ghost *append (struct ghost *new, struct ghost *head);
int winCondition (char board[HEIGHT][WIDTH]);
void ghostMovement (char board[HEIGHT][WIDTH], struct ghost *head);
