/*
CF 639A - Puzzle Pieces
https://codeforces.com/contest/1345/problem/A

Check if grid can be filled
n,m ≤ 1e5

Key: Only 1×n or 1×2 possible
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        cout << (n == 1 || m == 1 || (n == 2 && m == 2) ? "YES\n" : "NO\n");
    }
    return 0;
}
