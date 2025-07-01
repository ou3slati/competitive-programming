/*
CF 672D - Rescue Nibel!
https://codeforces.com/contest/1420/problem/D

Count number of ways to choose k overlapping intervals
n ≤ 3e5, k ≤ n, coordinates ≤ 1e9

Key insights:
1. Sort events by time (start/end)
2. Track active intervals
3. Use combinations for each valid position
4. Handle modulo arithmetic carefully
*/

#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

// Calculate x^p modulo MOD
long long modpow(long long x, long long p, long long mod = MOD) {
    long long res = 1;
    while(p > 0) {
        if(p & 1) res = (res * x) % mod;
        x = (x * x) % mod;
        p >>= 1;
    }
    return res;
}

// Calculate modular inverse using Fermat's little theorem
long long modinv(long long x, long long mod = MOD) {
    return modpow(x, mod-2, mod);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    
    // Store events (time, type)
    // type 1 = start, type 2 = end
    vector<pair<int, int>> events;
    for(int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        events.push_back({l, 1});
        events.push_back({r, 2});
    }
    sort(events.begin(), events.end());
    
    // Precompute combinations C(i,k-1)
    vector<long long> comb(n+1);
    comb[k-1] = 1;
    for(int i = k; i <= n; i++) {
        comb[i] = (comb[i-1] * i) % MOD;
        comb[i] = (comb[i] * modinv(i-(k-1))) % MOD;
    }
    
    // Process events
    long long ans = 0;
    int active = 0;
    for(auto [time, type] : events) {
        if(type == 2) {
            active--;
            continue;
        }
        active++;
        if(active >= k) {
            ans = (ans + comb[active-1]) % MOD;
        }
    }
    
    cout << ans << '\n';
    
    return 0;
}
