/*
CF 668C - Balanced Bitstring
https://codeforces.com/contest/1405/problem/C

Check if string can be valid
n ≤ 3e5

Key: Fix k-periodic positions
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        
        bool possible = true;
        vector<char> fixed(k, '?');
        
        // Fix k-periodic positions
        for(int i = 0; i < n && possible; i++) {
            int pos = i % k;
            if(s[i] == '?') continue;
            
            if(fixed[pos] == '?') fixed[pos] = s[i];
            else if(fixed[pos] != s[i]) possible = false;
        }
        
        // Count fixed positions
        int ones = 0, zeros = 0;
        for(char c : fixed) {
            if(c == '1') ones++;
            if(c == '0') zeros++;
        }
        
        // Check if balanced possible
        possible &= ones <= k/2 && zeros <= k/2;
        cout << (possible ? "YES\n" : "NO\n");
    }
    return 0;
}
