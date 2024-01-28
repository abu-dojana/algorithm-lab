#include <bits/stdc++.h>
using namespace std;


bool Place(int k, int i, const vector<int>& x) {
    for (int j = 1; j < k; ++j) {
        if (x[j - 1] == i || abs(x[j - 1] - i) == abs(j - k)) {
            return false;
        }
    }
    return true;
}

void NQueen(int k, int n, vector<int>& x) {
    for (int i = 1; i <= n; ++i) {
        if (Place(k, i, x)) {
            x[k - 1] = i;
            if (k == n) {
                for (int val : x) {
                    cout << val << " ";
                }
                cout << endl;
            } else {
                NQueen(k + 1, n, x);
            }
        }
    }
}



int main() {
    int n = 8;  // Number of queens

    cout << "All possible placements of " << n << " queens on a " << n << " x " << n << " chessboard so that they are non-attacking are: " << endl;

    vector<int> x(n, 0);  // x[i] = j means queen at i-th row is placed at j-th column
    NQueen(1, n, x);
    return 0;
}



/*
Algorithm:

1. NQueen(k,n)
2. //using backtracking, this procedure prints all possible placements of n queens on an n x n chessboard so that they are non-attacking
3. for i = 1 to n do
4.  if Place(k,i) then
5.      x[k] = i
6.      if k = n then write x[1:n]
7.      else NQueen(k+1,n)
8. end if
9. end for


Algorithm:
1. Place(k,i)
2. //Returns true if a queen can be placed in k th row and i th column, otherwise it returns false. x[] is a global array whose first k-1 values have been set. Abs(r) returns the absolute value of r.
3. for j = 1 to k-1 do
4.  if (x[j] = i)  //two in the same column
5.      or (Abs(x[j] - i) = Abs(j - k)) //or in the same diagonal
6.      then return false
7.   end if
8. return true
9. end for

*/