/*
CF 654B - Magical Calendar
https://codeforces.com/contest/1371/problem/B

Count valid segments in n days
n,r ≤ 1e9

Key: Triangle numbers with special case
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) {
        ll n, r;
        cin >> n >> r;
        
        if(r >= n) {
            cout << (n * (n-1))/2 + 1 << '\n';
        } else {
            cout << (r * (r+1))/2 << '\n';
        }
    }
    return 0;
}
