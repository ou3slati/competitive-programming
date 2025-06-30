/*
CF 664A - Boboniu Likes to Color Balls
https://codeforces.com/contest/1395/problem/A

Check if balls can be colored
r,g,b,w ≤ 1e9

Key: Parity of colors matters
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) {
        int r, g, b, w;
        cin >> r >> g >> b >> w;
        
        int odd = (r%2) + (g%2) + (b%2) + (w%2);
        bool possible = odd <= 1;
        
        if(!possible && r > 0 && g > 0 && b > 0) {
            r--; g--; b--; w++;
            odd = (r%2) + (g%2) + (b%2) + (w%2);
            possible = odd <= 1;
        }
        
        cout << (possible ? "Yes\n" : "No\n");
    }
    return 0;
}
