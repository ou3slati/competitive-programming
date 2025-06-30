/*
CF 662A - Rainbow Dash, Fluttershy and Chess Coloring
https://codeforces.com/contest/1393/problem/A

Min moves to color nxn board
n ≤ 1e9

Key: Need ⌈n/2⌉ + 1 colors
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << (n+1)/2 + 1 << '\n';
    }
    return 0;
}
