/*
CF 672B - Rock and Lever
https://codeforces.com/contest/1420/problem/B

Count pairs where (a[i] & a[j]) >= (a[i] ⊕ a[j])
n ≤ 1e5, a[i] ≤ 1e9

Key insights:
1. Condition equivalent to MSB position being same
2. Group numbers by highest set bit
3. Use combinations within each group
*/

#include <bits/stdc++.h>
using namespace std;

// Returns position of highest set bit (0-based)
int highest_bit(int x) {
    for(int i = 31; i >= 0; i--) {
        if(x & (1 << i)) return i;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        // Count numbers by highest bit position
        vector<long long> count(32);
        for(int x : a) {
            count[highest_bit(x)]++;
        }
        
        // Sum up combinations from each group
        long long ans = 0;
        for(long long c : count) {
            ans += (c * (c-1)) / 2;
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}
