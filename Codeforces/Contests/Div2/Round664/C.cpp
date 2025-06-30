/*
CF 664C - Boboniu and Bit Operations
https://codeforces.com/contest/1395/problem/C

Find min AND of all ORs
n,m ≤ 200, a[i],b[i] < 512

Key: Try bits from MSB to LSB
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int& x : a) cin >> x;
    for(int& x : b) cin >> x;
    
    int ans = 0;
    for(int bit = 8; bit >= 0; bit--) {
        bool possible = false;
        for(int x : a) {
            bool found = false;
            for(int y : b) {
                if(((x|y) & ((1<<(bit+1))-1)) == ans) {
                    found = true;
                    break;
                }
            }
            if(!found) {
                possible = true;
                break;
            }
        }
        if(possible) ans |= (1<<bit);
    }
    
    cout << ans << '\n';
    return 0;
}
