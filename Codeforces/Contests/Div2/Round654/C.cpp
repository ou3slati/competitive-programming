/*
CF 654C - Grid-00100
https://codeforces.com/contest/1371/problem/C

Build grid with constraints
n,m,a,b ≤ 1e18

Key: Check min/max cookie consumption
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) {
        ll v, c, n, m;
        cin >> v >> c >> n >> m;
        
        // Need m cookies of same type
        // Need enough total cookies
        bool possible = m <= min(v, c) && v + c >= n + m;
        
        cout << (possible ? "Yes\n" : "No\n");
    }
    return 0;
}
