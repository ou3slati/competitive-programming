/*
CF 658A - Common Subsequence
https://codeforces.com/contest/1382/problem/A

Find any common subsequence
n,m ≤ 1000

Key: Check for any common element
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
        
        vector<bool> seen(1001);
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            seen[x] = true;
        }
        
        int common = -1;
        for(int i = 0; i < m; i++) {
            int x;
            cin >> x;
            if(seen[x]) common = x;
        }
        
        if(common == -1) cout << "NO\n";
        else {
            cout << "YES\n1 " << common << '\n';
        }
    }
    return 0;
}
