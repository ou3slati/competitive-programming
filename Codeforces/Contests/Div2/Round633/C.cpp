/*
CF 633C - Powered Addition
https://codeforces.com/contest/1339/problem/C

Min operations to make array increasing
n ≤ 1e5, |a[i]| ≤ 1e9

Key: Binary lifting on required power
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for(ll& x : a) cin >> x;
        
        ll max_diff = 0;
        ll curr_max = a[0];
        
        for(int i = 1; i < n; i++) {
            max_diff = max(max_diff, curr_max - a[i]);
            curr_max = max(curr_max, a[i]);
        }
        
        int ans = 0;
        while((1LL << ans) - 1 < max_diff) ans++;
        cout << ans << '\n';
    }
    return 0;
}
