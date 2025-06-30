/*
CF 642A - Most Unstable Array
https://codeforces.com/contest/1353/problem/A

Maximize array instability
n,m ≤ 100

Key: [0,m,0] for n=2, [0,m,0,...] for n>2
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
        if(n == 1) cout << "0\n";
        else if(n == 2) cout << m << '\n';
        else cout << 2*m << '\n';
    }
    return 0;
}
