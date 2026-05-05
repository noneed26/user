#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
    for (int i = 0; i < col; i++)
        if (board[row][i]) return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;
    for (int i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j]) return false;
    return true;
}

void solveNQUtil(vector<vector<int>>& board, int col, int N, vector<vector<vector<int>>>& sols) {
    if (col >= N) {
        sols.push_back(board);
        return;
    }
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col, N)) {
            board[i][col] = 1;
            solveNQUtil(board, col + 1, N, sols);
            board[i][col] = 0;
        }
    }
}

int main() {
/*
Sample Input:
4
*/
    int N;
    cout << "Enter board size (N): ";
    cin >> N;
    vector<vector<int>> board(N, vector<int>(N, 0));
    vector<vector<vector<int>>> sols;
    solveNQUtil(board, 0, N, sols);

    for (const auto& sol : sols) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) cout << (sol[i][j] ? "Q " : ". ");
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}

// Time Complexity: O(N!)
// Space Complexity: O(N^2) for the board
