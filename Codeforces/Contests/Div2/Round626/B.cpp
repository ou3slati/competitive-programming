/*
CF 626B - Count Subrectangles
https://codeforces.com/contest/1323/problem/B

Count subrectangles with area d
n,m ≤ 4e4, d ≤ 1e9

Key: For each divisor of d, count valid dimensions
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Count consecutive ones segments of each length
vector<ll> count_segments(vector<int>& a) {
    int n = a.size();
    vector<ll> cnt(n + 1);
    int len = 0;
    
    for(int i = 0; i <= n; i++) {
        if(i < n && a[i]) {
            len++;
        } else if(len) {
            for(int j = 1; j <= len; j++) {
                cnt[j] += len - j + 1;
            }
            len = 0;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, d;
    cin >> n >> m >> d;
    
    vector<int> a(n), b(m);
    for(int& x : a) cin >> x;
    for(int& x : b) cin >> x;
    
    auto cnt_a = count_segments(a);
    auto cnt_b = count_segments(b);
    
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        if(d % i == 0 && d/i <= m) {
            ans += cnt_a[i] * cnt_b[d/i];
        }
    }
    
    cout << ans << '\n';
    return 0;
}
