/*
CF 644B - Honest Coach
https://codeforces.com/contest/1360/problem/B

Min difference between teams
n ≤ 50, s[i] ≤ 1000

Key: Sort and check adjacent
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> s(n);
        for(int& x : s) cin >> x;
        
        sort(s.begin(), s.end());
        int ans = 1000;
        for(int i = 1; i < n; i++) {
            ans = min(ans, s[i] - s[i-1]);
        }
        cout << ans << '\n';
    }
    return 0;
}
