/*
CF 634C - Two Teams
https://codeforces.com/contest/1335/problem/C

Max team size with unique and same skills
n ≤ 2e5, a[i] ≤ n

Key: Take most frequent + distinct others
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
        vector<int> freq(n + 1);
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            freq[x]++;
        }
        
        int max_freq = 0, distinct = 0;
        for(int i = 1; i <= n; i++) {
            if(freq[i]) distinct++;
            max_freq = max(max_freq, freq[i]);
        }
        
        cout << max(min(max_freq, distinct-1), 
                   min(max_freq-1, distinct)) << '\n';
    }
    return 0;
}
