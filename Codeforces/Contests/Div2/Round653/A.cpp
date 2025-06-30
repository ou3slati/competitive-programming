/*
CF 653A - Required Remainder
https://codeforces.com/contest/1374/problem/A

Find max n ≤ x where n%x = y
x,y ≤ 1e9

Key: Use floor division and add back
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) {
        int x, y, n;
        cin >> x >> y >> n;
        cout << n - ((n-y) % x + x) % x << '\n';
    }
    return 0;
}
