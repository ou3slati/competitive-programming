/*
CF 668B - Array Cancellation
https://codeforces.com/contest/1405/problem/B

Min cost to make array zero
n ≤ 1e5

Key: Track running balance
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) {
        int n;
        cin >> n;
        
        ll bal = 0, cost = 0;
        for(int i = 0; i < n; i++) {
            ll x;
            cin >> x;
            bal += x;
            cost = min(cost, bal);
        }
        
        cout << -cost << '\n';
    }
    return 0;
}
