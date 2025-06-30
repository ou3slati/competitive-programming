/*
CF 654A - Magical Sticks
https://codeforces.com/contest/1371/problem/A

Min sticks to make pairs sum n+1
n ≤ 1e9

Key: Ceil(n/2) pairs needed
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
        cout << (n + 1) / 2 << '\n';
    }
    return 0;
}
