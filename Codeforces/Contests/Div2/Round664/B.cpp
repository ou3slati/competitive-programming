/*
CF 664B - Boboniu Plays Chess
https://codeforces.com/contest/1395/problem/B

Visit all cells in chess board
n,m ≤ 100

Key: Visit row by row with snake pattern
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, sx, sy;
    cin >> n >> m >> sx >> sy;
    
    cout << sx << ' ' << sy << '\n';
    
    // First row
    for(int j = 1; j <= m; j++) {
        if(j != sy) cout << sx << ' ' << j << '\n';
    }
    
    // Other rows
    for(int i = 1; i <= n; i++) {
        if(i != sx) {
            if(i % 2 == sx % 2) {
                for(int j = 1; j <= m; j++) {
                    cout << i << ' ' << j << '\n';
                }
            } else {
                for(int j = m; j >= 1; j--) {
                    cout << i << ' ' << j << '\n';
                }
            }
        }
    }
    
    return 0;
}
