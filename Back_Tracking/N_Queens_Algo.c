#include <stdio.h>
#include <stdlib.h>

#define N 4

void print_solution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int QueenSafe(int board[N][N], int row, int col) {
    int i, j;
    for (i = 0; i < col; i++) {
        if (board[row][i]) {
            return 0;
        }
    }
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return 0;
        }
    }
    for (i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j]) {
            return 0;
        }
    }
    return 1;
}

int NQueenBackTrack(int board[N][N], int col) {
    if (col >= N) {
        return 1;
    }

    for (int i = 0; i < N; i++) {
        if (QueenSafe(board, i, col)) {
            board[i][col] = 1;
            if (NQueenBackTrack(board, col + 1)) {
                return 1;
            }
            board[i][col] = 0;
        }
    }
    return 0;
}

int main() {
    int board[N][N] = {0};

    if (NQueenBackTrack(board, 0)) {
        printf("The Solution is:\n");
        print_solution(board);
    } else {
        printf("Solution not found\n");
    }
    return 0;
}