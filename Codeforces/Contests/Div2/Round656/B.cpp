/*
CF 656B - Universal Solution
https://codeforces.com/contest/1385/problem/B

Reconstruct array from pairs
n ≤ 50

Key: Take first occurrence of each number
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
        vector<bool> seen(n+1);
        
        for(int i = 0; i < 2*n; i++) {
            int x;
            cin >> x;
            if(!seen[x]) {
                cout << x << ' ';
                seen[x] = true;
            }
        }
        cout << '\n';
    }
    return 0;
}
