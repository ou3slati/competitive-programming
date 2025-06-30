/*
CF 661B - Gifts Fixing
https://codeforces.com/contest/1399/problem/B

Min moves to equalize arrays
n ≤ 50

Key: Take max of required moves
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
        vector<int> a(n), b(n);
        
        int min_a = 1e9, min_b = 1e9;
        for(int& x : a) {
            cin >> x;
            min_a = min(min_a, x);
        }
        for(int& x : b) {
            cin >> x;
            min_b = min(min_b, x);
        }
        
        ll ans = 0;
        for(int i = 0; i < n; i++) {
            ans += max(a[i] - min_a, b[i] - min_b);
        }
        
        cout << ans << '\n';
    }
    return 0;
}
