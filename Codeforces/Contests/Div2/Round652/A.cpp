/*
CF 652A - FashionabLee
https://codeforces.com/contest/1369/problem/A

Check if regular n-gon is fashionable
n ≤ 1e9

Key: Multiple of 4 has perpendicular diagonals
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
        cout << (n % 4 == 0 ? "YES\n" : "NO\n");
    }
    return 0;
}
