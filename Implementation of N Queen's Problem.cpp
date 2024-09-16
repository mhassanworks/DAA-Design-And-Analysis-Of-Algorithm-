#include <iostream>
#include <vector>
using namespace std;

// Function to check if placing the queen is safe
bool isSafe(vector<vector<int>> &board, int row, int col, int N) {
    // Check this row on the left side
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return false;
        }
    }

    // Check the upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check the lower diagonal on the left side
    for (int i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

// Function to solve the N Queen problem using backtracking
bool solveNQueensUtil(vector<vector<int>> &board, int col, int N) {
    if (col >= N) {
        return true;
    }

    // Try placing the queen in all rows one by one
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col, N)) {
            // Place the queen
            board[i][col] = 1;

            // Recur to place the rest of the queens
            if (solveNQueensUtil(board, col + 1, N)) {
                return true;
            }

            // Backtrack and remove the queen
            board[i][col] = 0;
        }
    }

    return false;
}

// Function to solve the N Queen problem
bool solveNQueens(int N) {
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (!solveNQueensUtil(board, 0, N)) {
        cout << "Solution does not exist" << endl;
        return false;
    }

    // Print the solution
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return true;
}

int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;

    solveNQueens(N);

    return 0;
}
