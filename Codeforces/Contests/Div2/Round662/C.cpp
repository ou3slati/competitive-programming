/*
CF 662C - Pinkie Pie Eats Patty-cakes
https://codeforces.com/contest/1393/problem/C

Max distance between same numbers
n ≤ 1e5

Key: Use most frequent numbers first
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
        vector<int> cnt(n+1);
        
        int max_freq = 0;
        int freq_count = 0;
        
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            cnt[x]++;
            if(cnt[x] > max_freq) {
                max_freq = cnt[x];
                freq_count = 1;
            } else if(cnt[x] == max_freq) {
                freq_count++;
            }
        }
        
        // max_freq groups of size max_freq
        // remaining positions = n - max_freq*freq_count
        // these can be distributed between max_freq-1 gaps
        cout << (n - max_freq*freq_count)/(max_freq-1) + freq_count - 1 << '\n';
    }
    return 0;
}
