/*
CF 663B - Fix You
https://codeforces.com/contest/1391/problem/B

Min changes to make path valid
n,m ≤ 100

Key: Only last row/col matter
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            string s;
            cin >> s;
            if(i < n-1 && s[m-1] == 'R') ans++;
            if(i == n-1) {
                for(int j = 0; j < m-1; j++) {
                    if(s[j] == 'D') ans++;
                }
            }
        }
        
        cout << ans << '\n';
    }
    return 0;
}
