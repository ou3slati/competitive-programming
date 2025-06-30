/*
CF 637A - Nastya and Rice
https://codeforces.com/contest/1341/problem/A

Check if rice amount possible
n,a,b,c,d ≤ 1e4

Key: Check min/max bounds
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        int n, a, b, c, d;
        cin >> n >> a >> b >> c >> d;
        
        int min_grain = n * (a-b);
        int max_grain = n * (a+b);
        
        cout << (min_grain <= c+d && max_grain >= c-d ? "Yes\n" : "No\n");
    }
    return 0;
}
