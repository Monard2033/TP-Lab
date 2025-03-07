#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 40

typedef struct {
    int isMine;
    int isRevealed;
    int adjacentMines;
} Cell;

Cell board[MAX_SIZE][MAX_SIZE];
int rows, cols, mines;

void initBoard() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            board[i][j].isMine = 0;
            board[i][j].isRevealed = 0;
            board[i][j].adjacentMines = 0;
        }
    }
}

int isValidMinePlacement(int x, int y) {
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && board[nx][ny].isMine)
            return 0;
    }
    return 1;
}

void placeMines() {
    srand(time(NULL));
    int placed = 0;
    while (placed < mines) {
        int x = rand() % rows;
        int y = rand() % cols;
        if (!board[x][y].isMine && isValidMinePlacement(x, y)) {
            board[x][y].isMine = 1;
            placed++;
        }
    }
}

void calculateAdjacency() {
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j].isMine) continue;
            int count = 0;
            for (int k = 0; k < 8; k++) {
                int ni = i + dx[k], nj = j + dy[k];
                if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && board[ni][nj].isMine)
                    count++;
            }
            board[i][j].adjacentMines = count;
        }
    }
}

void revealCell(int x, int y) {
    if (x < 0 || x >= rows || y < 0 || y >= cols || board[x][y].isRevealed)
        return;

    board[x][y].isRevealed = 1;

    if (board[x][y].adjacentMines == 0) {
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && !board[nx][ny].isRevealed && !board[nx][ny].isMine && board[nx][ny].adjacentMines == 0) {
                revealCell(nx, ny);
            }
        }
    }
}

void displayBoard(int revealMines) {
    printf("   ");
    for (int j = 0; j < cols; j++) printf("%d ", j);
    printf("\n");
    
    for (int i = 0; i < rows; i++) {
        printf("%d  ", i);
        for (int j = 0; j < cols; j++) {
            if (revealMines && board[i][j].isMine) printf("* ");
            else if (!board[i][j].isRevealed) printf(". ");
            else if (board[i][j].isMine) printf("X ");
            else printf("%d ", board[i][j].adjacentMines);
        }
        printf("\n");
    }
}

int allCellsRevealed() {
    int revealedCells = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j].isRevealed) revealedCells++;
        }
    }
    return (revealedCells + mines == rows * cols);
}

void setDifficultyLevel(int difficulty, int boardSizeIndex) {
    // For Easy Level
    if (difficulty == 1) {
        switch (boardSizeIndex) {
            case 1: rows = 10; cols = 10; mines = 15; break;
            case 2: rows = 20; cols = 20; mines = 25; break;
            case 3: rows = 30; cols = 30; mines = 40; break;
            case 4: rows = 40; cols = 40; mines = 90; break;
        }
    }
    // For Normal Level
    else if (difficulty == 2) {
        switch (boardSizeIndex) {
            case 1: rows = 10; cols = 10; mines = 25; break;
            case 2: rows = 20; cols = 20; mines = 40; break;
            case 3: rows = 30; cols = 30; mines = 60; break;
            case 4: rows = 40; cols = 40; mines = 120; break;
        }
    }
    // For Hard Level
    else if (difficulty == 3) {
        switch (boardSizeIndex) {
            case 1: rows = 10; cols = 10; mines = 50; break;
            case 2: rows = 20; cols = 20; mines = 75; break;
            case 3: rows = 30; cols = 30; mines = 100; break;
            case 4: rows = 40; cols = 40; mines = 160; break;
        }
    }
    // For Expert Level
    else if (difficulty == 4) {
        switch (boardSizeIndex) {
            case 1: rows = 10; cols = 10; mines = 90; break;
            case 2: rows = 20; cols = 20; mines = 230; break;
            case 3: rows = 30; cols = 30; mines = 300; break;
            case 4: rows = 40; cols = 40; mines = 500; break;
        }
    } else {
        printf("Invalid difficulty level!\n");
        exit(1);
    }
}

int main() {
    int difficulty, boardSizeIndex;
    printf("Select Difficulty Level:\n1. Easy\n2. Normal\n3. Hard\n4. Expert\n");
    printf("Enter difficulty (1-4): ");
    scanf("%d", &difficulty);
    
    printf("Select Board Size (0-3):\n1. 10x10\n2. 20x20\n3. 30x30\n4. 40x40\n");
    printf("Enter board size index (0-3): ");
    scanf("%d", &boardSizeIndex);
    
    setDifficultyLevel(difficulty, boardSizeIndex);
    
    initBoard();
    placeMines();
    calculateAdjacency();
    
    int gameOver = 0;
    while (!gameOver) {
        displayBoard(0);
        int x, y;
        printf("Enter coordinates to reveal (row column): ");
        scanf("%d %d", &x, &y);
        
        if (board[x][y].isMine) {
            printf("Game Over! You hit a mine!\n");
            displayBoard(1);
            break;
        }
        
        revealCell(x, y);
        
        if (allCellsRevealed()) {
            printf("Congratulations! You cleared the board!\n");
            displayBoard(1);
            break;
        }
    }
    return 0;
}
