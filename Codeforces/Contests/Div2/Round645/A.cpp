/*
CF 645A - Park Lighting
https://codeforces.com/contest/1358/problem/A

Min lamps to light nxm park
n,m ≤ 100

Key: Ceil of total squares / 2
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
        cout << (n * m + 1) / 2 << '\n';
    }
    return 0;
}
