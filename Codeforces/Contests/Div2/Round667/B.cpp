/*
CF 667B - Minimum Product
https://codeforces.com/contest/1409/problem/B

Min product after limited decrements
a,b,x,y ≤ 1e9, n ≤ 1e9

Key: Try both decrement orders
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll a, ll b, ll x, ll y, ll n) {
    ll da = min(n, a - x);
    n -= da;
    a -= da;
    
    ll db = min(n, b - y);
    b -= db;
    
    return a * b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) {
        ll a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;
        
        cout << min(solve(a, b, x, y, n),
                   solve(b, a, y, x, n)) << '\n';
    }
    return 0;
}
