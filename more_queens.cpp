#include <bits/stdc++.h>
using namespace std;

bool Place(int k, int i, const vector<int>& x) {
    for (int j = 1; j < k; ++j) {
        if (x[j - 1] == i || abs(x[j - 1] - i) == abs(j - k)) {
            return false;
        }
    }
    return i >= 1 && i <= x.size();
}

void NQueen(int k, int n, vector<int>& x, int& count) {
    for (int i = 1; i <= n; ++i) {
        if (Place(k, i, x)) {
            x[k - 1] = i;
            if (k == n) {
                // Found a solution
                count++;
                cout << "Solution " << count << ": ";
                for (int val : x) {
                    cout << val << " ";
                }
                cout << endl;
            } else {
                NQueen(k + 1, n, x, count);
            }
        }
    }
}

int NQueenCount(int n, int queens) {
    int count = 0;
    vector<int> x(queens, 0);
    NQueen(1, queens, x, count);
    return count;
}

int main() {
    int n = 8;      // Size of the chessboard
    int queens = 5; // Number of queens

    if (queens > n) {
        cout << "Number of queens cannot exceed the size of the chessboard." << endl;
        return 1; // Exit with an error code
    }

    cout << "All possible placements of " << queens << " queens on a " << n << " x " << n << " chessboard so that they are non-attacking are: " << endl;

    int solutionsCount = NQueenCount(n, queens);

    cout << "Number of solutions: " << solutionsCount << endl;

    return 0;
}
