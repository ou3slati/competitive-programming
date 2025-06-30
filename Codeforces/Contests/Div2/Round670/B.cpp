/*
CF 670B - Maximum Product
https://codeforces.com/contest/1406/problem/B

Max product of 5 numbers
n ≤ 1e5

Key: Try all sign combinations
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
        vector<ll> a(n);
        for(ll& x : a) cin >> x;
        sort(a.begin(), a.end());
        
        ll ans = -1e18;
        // Try all combinations of positive/negative numbers
        ans = max(ans, a[n-1]*a[n-2]*a[n-3]*a[n-4]*a[n-5]);
        ans = max(ans, a[0]*a[1]*a[n-1]*a[n-2]*a[n-3]);
        ans = max(ans, a[0]*a[1]*a[2]*a[3]*a[n-1]);
        
        cout << ans << '\n';
    }
    return 0;
}
