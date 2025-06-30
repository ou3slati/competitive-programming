/*
CF 647C - Johnny and Another Rating Drop
https://codeforces.com/contest/1362/problem/C

Sum of bits changed from 0 to n
n ≤ 1e18

Key: Each bit contributes 2^i times
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        
        ll ans = 0;
        for(int i = 0; i < 60; i++) {
            ans += (n >> i);
        }
        
        cout << ans << '\n';
    }
    return 0;
}
