/*
CF 667A - Yet Another Two Integers Problem
https://codeforces.com/contest/1409/problem/A

Min moves to make a=b with ±1..10
a,b ≤ 1e9

Key: Use max steps possible
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
        int diff = abs(a - b);
        cout << (diff + 9) / 10 << '\n';
    }
    return 0;
}
