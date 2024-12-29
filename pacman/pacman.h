// Header file for define, and function prototype
#define WIDTH 10
#define HEIGHT 10

// Struct 
struct ghost {
    int coorX;
    int coorY;
    struct ghost *next;
};

struct tile {
    char space;
    int ghost;
    int player;
};

// Define the characters for the board
#define EMPTY ' '
#define WALL '#'
#define DOT '.'

void initializeBoard (struct tile board[HEIGHT][WIDTH]);
void printBoard (struct tile board[HEIGHT][WIDTH]);

/* 
    Starting from this line, all of 
    them is my own decalration
*/

//Constant
#define TRUE 1
#define FALSE 0
#define EXTRAFALSE 2
#define MAXCAP 10
#define MINCAP 0
#define GHOSTMOVEOPTION 3
#define GHOSTW 1
#define GHOSTA 2
#define GHOSTS 3
#define GHOSTD 0
#define moveW 'w'
#define moveA 'a'
#define moveS 's'
#define moveD 'd'

//Function Prototype
void levelBuild (struct tile board[HEIGHT][WIDTH], int *playerX, 
                int *playerY, struct ghost *head);
void movementMechanic (struct tile board[HEIGHT][WIDTH], 
                        int *playerX, int *playerY);
void inputWall(int coorX, int coorY, struct tile board[HEIGHT][WIDTH]);
void movementW(struct tile board[HEIGHT][WIDTH], int *playerX, int *playerY);
void movementA (struct tile board[HEIGHT][WIDTH], int *playerX, int *playerY);
void movementD (struct tile board[HEIGHT][WIDTH], int *playerX, int *playerY);
void movementS (struct tile board[HEIGHT][WIDTH], int *playerX, int *playerY);
struct ghost *inputGhost(int coorX, int coorY, 
                    struct tile board[HEIGHT][WIDTH], struct ghost *head);
struct ghost *append (struct ghost *new, struct ghost *head);
int winCondition (struct tile board[HEIGHT][WIDTH]);
void ghostMovement (struct tile board[HEIGHT][WIDTH], struct ghost *head);
int validCheck (struct tile board[HEIGHT][WIDTH], 
                char input, int *coorX, int *coorY);
int checkGhost(struct tile board[HEIGHT][WIDTH], int move, 
                struct ghost *tmp);
