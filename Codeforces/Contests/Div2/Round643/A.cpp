/*
CF 643A - Sequence with Digits
https://codeforces.com/contest/1355/problem/A

Find sequence based on min/max digit
a₁ ≤ 1e18, k ≤ 1e16

Key: Stop when min digit is 0
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<int,int> get_min_max(ll n) {
    int mn = 9, mx = 0;
    while(n) {
        int d = n % 10;
        mn = min(mn, d);
        mx = max(mx, d);
        n /= 10;
    }
    return {mn, mx};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) {
        ll a, k;
        cin >> a >> k;
        k--;
        while(k-- && get_min_max(a).first) {
            auto [mn, mx] = get_min_max(a);
            a += mn * mx;
        }
        cout << a << '\n';
    }
    return 0;
}
