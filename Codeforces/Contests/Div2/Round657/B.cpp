/*
CF 657B - Distance and Axis
https://codeforces.com/contest/1387/problem/B

Min moves to make |pos - point| = k
n,k ≤ 1e9

Key: Check parity of n-k
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        
        if(n < k) cout << k-n << '\n';
        else cout << (n-k) % 2 << '\n';
    }
    return 0;
}
