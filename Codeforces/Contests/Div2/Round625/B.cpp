/*
CF 625B - Journey Planning
https://codeforces.com/contest/1321/problem/B

Max sum from subsequence where b[i] = i + a[i]
n ≤ 2e5, |a[i]| ≤ 1e9

Key: Group by b[i]-i, take max group sum
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    map<ll,ll> group_sum;
    for(int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        group_sum[x - i] += x;
    }
    
    ll ans = 0;
    for(auto [k,v] : group_sum) {
        ans = max(ans, v);
    }
    
    cout << ans << '\n';
    return 0;
}
