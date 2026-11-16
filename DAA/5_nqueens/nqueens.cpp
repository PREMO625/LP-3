#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

bool safe(int row, int col, const vector<int>& queenColumn) {
    for (int r = 0; r < row; ++r)
        if (queenColumn[r] == col || abs(queenColumn[r] - col) == row - r)
            return false;
    return true;
}

void solve(int row, int n, int fixedRow, int fixedCol,
           vector<int>& queenColumn, int& solutions) {
    if (row == n) {
        cout << "\nSolution " << ++solutions << ":\n";
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c)
                cout << (queenColumn[r] == c ? 'Q' : '.');
            cout << '\n';
        }
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (row == fixedRow && col != fixedCol)
            continue;
        if (safe(row, col, queenColumn)) {
            queenColumn[row] = col;
            solve(row + 1, n, fixedRow, fixedCol, queenColumn, solutions);
        }
    }
}

int main() {
    int n, row, col;
    cout << "Enter the number of queens: ";
    if (!(cin >> n) || n < 1) {
        cerr << "The number of queens must be a positive integer.\n";
        return 1;
    }

    cout << "Enter the first queen's row and column (1-" << n << "): ";
    if (!(cin >> row >> col) || row < 1 || row > n || col < 1 || col > n) {
        cerr << "The queen position must be within the matrix.\n";
        return 1;
    }

    vector<int> queenColumn(n);
    int solutions = 0;
    solve(0, n, row - 1, col - 1, queenColumn, solutions);
    cout << "\nTotal solutions: " << solutions << '\n';
}
