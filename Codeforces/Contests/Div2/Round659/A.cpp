/*
CF 659A - Common Prefixes
https://codeforces.com/contest/1384/problem/A

Construct strings with given LCP
n ≤ 100

Key: Build with alternating chars
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
        vector<int> a(n);
        for(int& x : a) cin >> x;
        
        string curr(50, 'a');
        cout << curr << '\n';
        
        for(int x : a) {
            curr[x] = curr[x] == 'a' ? 'b' : 'a';
            cout << curr << '\n';
        }
    }
    return 0;
}
