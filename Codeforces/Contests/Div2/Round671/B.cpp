/*
CF 671B - Stairs
https://codeforces.com/contest/1419/problem/B

Count max complete stairs possible
x ≤ 1e18

Key: Each stair uses 2^k-1 blocks
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) {
        ll x;
        cin >> x;
        
        ll curr = 1, total = 0;
        int ans = 0;
        
        while(total + (curr * (curr + 1))/2 <= x) {
            total += (curr * (curr + 1))/2;
            curr = curr * 2 + 1;
            ans++;
        }
        
        cout << ans << '\n';
    }
    return 0;
}
