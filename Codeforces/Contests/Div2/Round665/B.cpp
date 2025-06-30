/*
CF 665B - Ternary Sequence
https://codeforces.com/contest/1401/problem/B

Max sum after permuting arrays
n ≤ 1e5

Key: Match 2s with 1s first
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) {
        ll x1, y1, z1;
        ll x2, y2, z2;
        cin >> x1 >> y1 >> z1;
        cin >> x2 >> y2 >> z2;
        
        ll ans = 0;
        // Match 2s with 1s
        ll match = min(z1, y2);
        ans += 2 * match;
        z1 -= match;
        y2 -= match;
        
        // Match remaining 2s with 0s
        ll bad = max(0LL, z2 - (x1 + z1));
        ans -= 2 * bad;
        
        cout << ans << '\n';
    }
    return 0;
}
