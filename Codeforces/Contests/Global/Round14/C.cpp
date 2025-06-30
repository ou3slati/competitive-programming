/*
Global 14C - Phoenix and Towers
https://codeforces.com/contest/1515/problem/C

Distribute N blocks to M towers, max height diff ≤ X
n,m ≤ 10^5, h[i],x ≤ 10^9

Key: Greedy - always add to shortest tower
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        int n, m, x;
        cin >> n >> m >> x;
        
        set<pair<int,int>> towers;  // {height, index}
        for(int i = 1; i <= m; i++) towers.insert({0, i});
        
        cout << "YES\n";
        for(int i = 0; i < n; i++) {
            int h;
            cin >> h;
            auto [height, idx] = *towers.begin();
            towers.erase(towers.begin());
            towers.insert({height + h, idx});
            cout << idx << ' ';
        }
        cout << '\n';
    }
    return 0;
}
