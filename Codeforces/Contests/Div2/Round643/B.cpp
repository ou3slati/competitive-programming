/*
CF 643B - Game With Array
https://codeforces.com/contest/1355/problem/B

Make array with sum S and no subset sum N
n,s ≤ 1e9

Key: [1,1,...,S-N+1]
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) {
        int n, s;
        cin >> n >> s;
        
        if(2*n <= s) {
            cout << "YES\n";
            for(int i = 0; i < n-1; i++) cout << "2 ";
            cout << s-2*(n-1) << "\n1\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
