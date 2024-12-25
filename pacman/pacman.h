// Header file for define, and function prototype

// Line 4-14 is provided by Blackbox AI
#define WIDTH 10
#define HEIGHT 10

// Define the characters for the board
#define EMPTY ' '
#define WALL '#'
#define DOT '.'
#define PACMAN 'P'

void initializeBoard (struct tile board[HEIGHT][WIDTH]);
void printBoard (struct tile board[HEIGHT][WIDTH]);

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

struct tile {
    char space;
    int ghost;
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
void levelBuild (struct tile board[HEIGHT][WIDTH], int *playerX, int *playerY, struct ghost *head);
void movementMechanic (struct tile board[HEIGHT][WIDTH], int *playerX, int *playerY);
void inputWall(int coorX, int coorY, struct tile board[HEIGHT][WIDTH]);
void movementW(struct tile board[HEIGHT][WIDTH], int *playerX, int *playerY);
void movementA (struct tile board[HEIGHT][WIDTH], int *playerX, int *playerY);
void movementD (struct tile board[HEIGHT][WIDTH], int *playerX, int *playerY);
void movementS (struct tile board[HEIGHT][WIDTH], int *playerX, int *playerY);
struct ghost *inputGhost(int coorX, int coorY, struct tile board[HEIGHT][WIDTH], struct ghost *head);
struct ghost *append (struct ghost *new, struct ghost *head);
int winCondition (struct tile board[HEIGHT][WIDTH]);
void ghostMovement (struct tile board[HEIGHT][WIDTH], struct ghost *head);