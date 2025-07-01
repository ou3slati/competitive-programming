/*
CF 672E - Battle Lemmings
https://codeforces.com/contest/1420/problem/E

Optimize lemming grouping with limited swaps
n ≤ 70, values are 0/1

Key insights:
1. Use DP with state compression
2. Track suffix counts of zeros
3. Consider value at current position and remaining swaps
4. Maximize score for each number of swaps
*/

#include <bits/stdc++.h>
using namespace std;

// dp[pos][val][swaps][zeros] = max score
long long dp[71][2][71*70+1][71];
vector<int> suffix_zeros;

long long solve(int pos, int val, int swaps, int zero_count, 
               const vector<int>& arr, int n) {
    if(pos == n-1) return 0;
    if(dp[pos][val][swaps][zero_count] != -1) 
        return dp[pos][val][swaps][zero_count];
    
    long long ans = 0;
    
    // Don't swap - continue with next position
    ans = solve(pos+1, arr[pos+1], swaps, 
               (val == 1) ? 0 : zero_count + 1, 
               arr, n);
    if(val == 1) {
        ans += zero_count * suffix_zeros[pos+1];
    }
    
    // Try swap if possible and beneficial
    if(swaps > 0 && val != arr[pos+1]) {
        long long swap_score = solve(pos+1, val, swaps-1,
                                   (arr[pos+1] == 1) ? 0 : zero_count + 1,
                                   arr, n);
        if(arr[pos+1] == 1) {
            swap_score += zero_count * suffix_zeros[pos];
        }
        ans = max(ans, swap_score);
    }
    
    return dp[pos][val][swaps][zero_count] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Precompute suffix counts of zeros
    suffix_zeros.resize(n);
    for(int i = n-1; i >= 0; i--) {
        suffix_zeros[i] = (a[i] == 0 ? 1 : 0);
        if(i < n-1) suffix_zeros[i] += suffix_zeros[i+1];
    }
    
    // Try all possible numbers of swaps
    int max_swaps = (n * (n-1)) / 2;
    memset(dp, -1, sizeof(dp));
    
    for(int k = 0; k <= max_swaps; k++) {
        cout << solve(0, a[0], k, 0, a, n) << ' ';
    }
    cout << '\n';
    
    return 0;
}
