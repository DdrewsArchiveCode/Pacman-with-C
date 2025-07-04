// Header file for define, and function prototype
#define WIDTH 10
#define HEIGHT 10
#define GHOSTMAX 100

// Struct 
struct ghost {
    int coorX;
    int coorY;
    int ghost;
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
void initializeGhost (struct ghost gh[GHOSTMAX]);
void printBoard (struct tile board[HEIGHT][WIDTH]);

//Constant
#define TRUE 1
#define FALSE 0
#define EXTRAFALSE 2
#define MAXCAP 10
#define MINCAP 0
#define GHOSTMOVEOPTION 4
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
                int *playerY, struct ghost gh[GHOSTMAX]);
void movementMechanic (struct tile board[HEIGHT][WIDTH], int *playerX, 
                        int *playerY, struct ghost gh[GHOSTMAX]);
void inputWall(int coorX, int coorY, struct tile board[HEIGHT][WIDTH]);
void movementW(struct tile board[HEIGHT][WIDTH], int *playerX, int *playerY);
void movementA (struct tile board[HEIGHT][WIDTH], int *playerX, int *playerY);
void movementD (struct tile board[HEIGHT][WIDTH], int *playerX, int *playerY);
void movementS (struct tile board[HEIGHT][WIDTH], int *playerX, int *playerY);
int winCondition (struct tile board[HEIGHT][WIDTH]);
void ghostMovement (struct tile board[HEIGHT][WIDTH], struct ghost gh[GHOSTMAX]);
int validCheck (struct tile board[HEIGHT][WIDTH], 
                char input, int *coorX, int *coorY);
int checkGhost(struct tile board[HEIGHT][WIDTH], int move, struct ghost[GHOSTMAX]);
void computingMovementMechanic (struct tile board[HEIGHT][WIDTH], char mechanic, 
                                int *playerX, int *playerY, int *checker, struct ghost gh[GHOSTMAX]);
void removePlayer (struct tile board[HEIGHT][WIDTH]);
void inputGhost (struct tile board[HEIGHT][WIDTH], struct ghost gh[GHOSTMAX], 
                int coorX, int coorY);