/*
Problem: Sifid and Strange Subsequences
Link: https://codeforces.com/contest/1529/problem/B
Contest: Codeforces Round #722 (Div. 2)
Approach: Number Theory - Uses sieve for prime factorization and dynamic programming
         1. Precompute smallest prime factors using sieve
         2. Calculate number of divisors for each number
         3. Use DP to compute cumulative sum of divisor counts
Time: O(N log log N) for sieve + O(N log N) for divisor calculation
Space: O(N) for sieve and DP array
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define pb push_back
#define sz(x) (int)(x).size()

const int MOD = 998244353;
const int MX = 1e6 + 10;

// Calculate smallest prime factor for each number
vector<int> computeSPF() {
    vector<int> spf(MX, -1);
    for(int i = 2; i < MX; i++) {
        if(spf[i] == -1) {
            for(int j = i; j < MX; j += i) {
                if(spf[j] == -1) spf[j] = i;
            }
        }
    }
    return spf;
}

// Calculate number of divisors using prime factorization
int countDivisors(int x, const vector<int>& spf) {
    int result = 1;
    while(x > 1) {
        int prime = spf[x];
        int count = 0;
        
        // Count power of current prime factor
        while(spf[x] == prime) {
            count++;
            x /= prime;
        }
        
        result *= (count + 1);
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // Precompute smallest prime factors
    vector<int> spf = computeSPF();
    
    int N;
    cin >> N;
    
    // DP array to store results
    vector<ll> dp(N + 1);
    dp[1] = 1;
    
    // Cumulative sum for optimization
    ll sum = 1;
    
    // Compute for each number from 2 to N
    FOR(i, 2, N + 1) {
        // Current number's contribution
        dp[i] = countDivisors(i, spf);
        
        // Add contribution from previous numbers
        dp[i] = (dp[i] + sum) % MOD;
        
        // Update cumulative sum
        sum = (sum + dp[i]) % MOD;
    }
    
    cout << dp[N] << endl;
    return 0;
}
