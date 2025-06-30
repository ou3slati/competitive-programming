/*
CF 666C - Multiples of Length
https://codeforces.com/contest/1397/problem/C

Make array zero in three moves
n ≤ 1e5

Key: Use n-1, n-1, n operations
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
    
    if(n == 1) {
        cout << "1 1\n" << -a[0] << "\n1 1\n0\n1 1\n0\n";
        return 0;
    }
    
    // First n-1 elements
    cout << "1 " << n-1 << '\n';
    for(int i = 0; i < n-1; i++) {
        ll ops = ((-(a[i] % n)) + n) % n;
        cout << ops * n << ' ';
        a[i] += ops * n;
    }
    cout << '\n';
    
    // Last element
    cout << n << ' ' << n << '\n';
    ll ops = ((-(a[n-1] % n)) + n) % n;
    cout << ops * n << "\n";
    a[n-1] += ops * n;
    
    // All elements
    cout << "1 " << n << '\n';
    for(int i = 0; i < n; i++) {
        cout << -a[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}
