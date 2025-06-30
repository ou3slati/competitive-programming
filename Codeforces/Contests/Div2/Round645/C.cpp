/*
CF 645C - Celex Update
https://codeforces.com/contest/1358/problem/C

Count paths between cells
x1,y1,x2,y2 ≤ 1e9

Key: (x2-x1)*(y2-y1)+1
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << (x2-x1)*(y2-y1)+1 << '\n';
    }
    return 0;
}
