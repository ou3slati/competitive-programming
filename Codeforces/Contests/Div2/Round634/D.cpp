/*
CF 634D - Anti-Sudoku
https://codeforces.com/contest/1335/problem/D

Break sudoku by changing one per block
9x9 grid

Key: Change diagonal in each 3x3 block
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        vector<string> grid(9);
        for(auto& row : grid) cin >> row;
        
        // Change one digit in each 3x3 block
        for(int i = 0; i < 9; i++) {
            int r = i/3*3 + i%3;
            int c = i/3*3 + (i+1)%3;
            if(grid[r][c] == '9') grid[r][c] = '1';
            else grid[r][c]++;
        }
        
        for(const auto& row : grid) cout << row << '\n';
    }
    return 0;
}
