/*
CF 630C - K-Complete Word
https://codeforces.com/contest/1332/problem/C

Make string palindrome with period k
n ≤ 2e5, k ≤ n

Key: Characters at positions equal mod k must match
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        
        int ans = 0;
        // Process each group of positions mod k
        for(int i = 0; i < k/2; i++) {
            vector<int> freq(26);
            int total = 0;
            
            // Count frequencies in symmetric positions
            for(int j = i; j < n; j += k) {
                freq[s[j] - 'a']++;
                freq[s[j + (k-2*i-1)] - 'a']++;
                total += 2;
            }
            
            // Find most frequent character
            int max_freq = 0;
            for(int f : freq) max_freq = max(max_freq, f);
            ans += total - max_freq;
        }
        
        // Handle middle character for odd k
        if(k % 2) {
            vector<int> freq(26);
            int total = 0;
            for(int j = k/2; j < n; j += k) {
                freq[s[j] - 'a']++;
                total++;
            }
            int max_freq = 0;
            for(int f : freq) max_freq = max(max_freq, f);
            ans += total - max_freq;
        }
        
        cout << ans << '\n';
    }
    return 0;
}
