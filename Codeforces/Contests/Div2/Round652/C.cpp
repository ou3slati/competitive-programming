/*
CF 652C - RationalLee
https://codeforces.com/contest/1369/problem/C

Max sum with k friends
n ≤ 2e5

Key: Give max to 1s, min to others greedily
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), w(k);
        for(int& x : a) cin >> x;
        for(int& x : w) cin >> x;
        
        sort(a.rbegin(), a.rend());
        sort(w.begin(), w.end());
        
        ll ans = 0;
        int pos = 0;
        
        // Give max numbers to friends who want 1
        for(int i = 0; i < k; i++) {
            if(w[i] == 1) {
                ans += 2LL * a[pos++];
            }
        }
        
        // Give min numbers to others
        int right = n-1;
        for(int i = k-1; i >= 0; i--) {
            if(w[i] > 1) {
                ans += a[pos++];  // max for first
                ans += a[right];  // min for others
                right -= w[i]-1;
            }
        }
        
        cout << ans << '\n';
    }
    return 0;
}
