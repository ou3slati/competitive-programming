/*
CF 641C - Orac and LCM
https://codeforces.com/contest/1349/problem/C

Find LCM property
n ≤ 2e5, a[i] ≤ 2e5

Key: Prime factorization analysis
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for(int& x : a) cin >> x;
    
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            ll curr_lcm = lcm(a[i], a[j]);
            if(ans == 0) ans = curr_lcm;
            else ans = gcd(ans, curr_lcm);
        }
    }
    
    cout << ans << '\n';
    return 0;
}
