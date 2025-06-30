/*
CF 632C - Eugene and an Array
https://codeforces.com/contest/1333/problem/C

Count subarrays with non-zero sum
n ≤ 2e5, |a[i]| ≤ 1e9

Key: Track prefix sums, use two pointers
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
    
    map<ll,int> last;  // last position of prefix sum
    last[0] = 0;
    ll sum = 0;
    ll ans = 0;
    int left = 0;  // leftmost valid position
    
    for(int i = 0; i < n; i++) {
        sum += a[i];
        left = max(left, last[sum] + 1);
        ans += i - left + 1;
        last[sum] = i + 1;
    }
    
    cout << ans << '\n';
    return 0;
}
