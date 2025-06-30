/*
CF 666B - Power Sequence
https://codeforces.com/contest/1397/problem/B

Min cost to make geometric sequence
n ≤ 1e5

Key: Try small bases, estimate max
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<ll> a(n);
    for(ll& x : a) cin >> x;
    sort(a.begin(), a.end());
    
    ll ans = 1e18;
    for(ll c = 1; ; c++) {
        ll curr = 1, sum = 0;
        bool overflow = false;
        
        for(int i = 0; i < n; i++) {
            sum += abs(a[i] - curr);
            if(curr > (ll)2e18/c) {
                overflow = true;
                break;
            }
            curr *= c;
        }
        
        if(overflow || sum > ans) break;
        ans = sum;
    }
    
    cout << ans << '\n';
    return 0;
}
