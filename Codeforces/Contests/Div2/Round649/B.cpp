/*
CF 649B - Most socially-distanced subsequence
https://codeforces.com/contest/1364/problem/B

Min length subsequence with same alternation
n ≤ 1e5

Key: Take local min/max points
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
        vector<int> p(n);
        for(int& x : p) cin >> x;
        
        vector<int> ans = {p[0]};
        for(int i = 1; i < n-1; i++) {
            if((p[i] > p[i-1]) != (p[i+1] > p[i])) {
                ans.push_back(p[i]);
            }
        }
        ans.push_back(p[n-1]);
        
        cout << ans.size() << '\n';
        for(int x : ans) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}
