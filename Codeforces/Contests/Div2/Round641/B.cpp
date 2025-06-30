/*
CF 641B - Orac and Models
https://codeforces.com/contest/1349/problem/B

Longest subsequence with divisibility
n ≤ 1e5

Key: DP on divisors
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> s(n+1), dp(n+1, 1);
        for(int i = 1; i <= n; i++) cin >> s[i];
        
        int ans = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = i*2; j <= n; j += i) {
                if(s[j] > s[i]) {
                    dp[j] = max(dp[j], dp[i] + 1);
                    ans = max(ans, dp[j]);
                }
            }
        }
        
        cout << ans << '\n';
    }
    return 0;
}
