/*
CF 656A - Three Pairwise Maximums
https://codeforces.com/contest/1385/problem/A

Find a,b,c given their maximums
x,y,z ≤ 1e9

Key: Two max values must be equal
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) {
        vector<int> x(3);
        for(int& v : x) cin >> v;
        sort(x.begin(), x.end());
        
        if(x[1] != x[2]) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            cout << x[0] << ' ' << x[0] << ' ' << x[2] << '\n';
        }
    }
    return 0;
}
