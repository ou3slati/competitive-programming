/*
CF 650C - Social Distance
https://codeforces.com/contest/1367/problem/C

Max people with k distance
n ≤ 2e5

Key: Greedily place from left to right
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
        
        int ans = 0;
        int last = -k-1;  // position of last person
        
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                last = i;
                continue;
            }
            
            if(i - last > k && (i == n-1 || s[i+1] != '1' && i + k < n)) {
                ans++;
                last = i;
            }
        }
        
        cout << ans << '\n';
    }
    return 0;
}
