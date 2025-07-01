/*
CF 672C1 - Pokémon Army (easy version)
https://codeforces.com/contest/1420/problem/C1

Find maximum value of alternating subsequence
n ≤ 3e5, a[i] ≤ 1e9

Key insights:
1. Optimal solution alternates between adding and subtracting
2. Use DP with state (index, isAdding)
3. For each position, can either continue current state or switch
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        // dp[i][0] = max value ending at i with last element subtracted
        // dp[i][1] = max value ending at i with last element added
        vector<vector<long long>> dp(n, vector<long long>(2));
        
        dp[0][0] = 0;
        dp[0][1] = a[0];
        
        for(int i = 1; i < n; i++) {
            // If we're subtracting at i
            dp[i][0] = max(dp[i-1][0],         // don't use a[i]
                          dp[i-1][1] - a[i]);   // use a[i]
            
            // If we're adding at i
            dp[i][1] = max(dp[i-1][1],         // don't use a[i]
                          dp[i-1][0] + a[i]);   // use a[i]
        }
        
        cout << max(dp[n-1][0], dp[n-1][1]) << '\n';
    }
    
    return 0;
}
