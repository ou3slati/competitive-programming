/*
CF 647A - Johnny and Ancient Computer
https://codeforces.com/contest/1362/problem/A

Min operations to transform a to b
a,b ≤ 1e18

Key: Check if ratio is power of 2
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) {
        ll a, b;
        cin >> a >> b;
        
        if(a > b) swap(a, b);
        if(b % a != 0) {
            cout << "-1\n";
            continue;
        }
        
        ll ratio = b/a;
        if((ratio & (ratio-1)) != 0) {
            cout << "-1\n";
            continue;
        }
        
        int ops = 0;
        while(ratio > 1) {
            ops += ratio % 8 == 0 ? 1 : (ratio % 4 == 0 ? 2 : 3);
            ratio /= 8;
        }
        
        cout << ops << '\n';
    }
    return 0;
}
