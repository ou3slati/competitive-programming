/*
CF 630A - Exercising Walk
https://codeforces.com/contest/1332/problem/A

Check if walk possible within bounds
a,b,c,d,x,y,x1,y1,x2,y2 ≤ 1e9

Key: Need space for each direction used
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        int a, b, c, d;  // left, right, down, up
        cin >> a >> b >> c >> d;
        
        int x, y, x1, y1, x2, y2;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;
        
        bool possible = true;
        
        // Check horizontal movement
        int dx = b - a;  // net right movement
        if(x + dx < x1 || x + dx > x2) possible = false;
        if(a + b > 0 && x1 == x2) possible = false;
        
        // Check vertical movement
        int dy = d - c;  // net up movement
        if(y + dy < y1 || y + dy > y2) possible = false;
        if(c + d > 0 && y1 == y2) possible = false;
        
        cout << (possible ? "Yes" : "No") << '\n';
    }
    return 0;
}
