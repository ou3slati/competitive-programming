/*
CF 644A - Minimal Square
https://codeforces.com/contest/1360/problem/A

Min square containing two rectangles
a,b ≤ 100

Key: Side = max(2*min, max)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        int side = max({2*min(a,b), max(a,b)});
        cout << side * side << '\n';
    }
    return 0;
}
