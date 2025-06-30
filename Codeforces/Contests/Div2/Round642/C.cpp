/*
CF 642C - Board Moves
https://codeforces.com/contest/1353/problem/C

Min moves to center for nxn board
n ≤ 5e5, n odd

Key: Each layer costs 8*i*i moves
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
        ll ans = 0;
        for(ll i = 1; i <= n/2; i++) {
            ans += i * (8*i);
        }
        cout << ans << '\n';
    }
    return 0;
}
