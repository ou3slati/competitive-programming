/*
CF 669C - Chocolate Bunny
https://codeforces.com/contest/1407/problem/C

Find array using mod queries
n ≤ 1e4

Key: Use properties of modulo
*/

#include <bits/stdc++.h>
using namespace std;

int query(int i, int j) {
    cout << "? " << i+1 << " " << j+1 << endl;
    int res;
    cin >> res;
    return res;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> ans(n, -1);
    int pos = 0;
    
    for(int i = 1; i < n; i++) {
        int mod1 = query(pos, i);
        int mod2 = query(i, pos);
        
        if(mod1 > mod2) {
            ans[pos] = mod1;
            pos = i;
        } else {
            ans[i] = mod2;
        }
    }
    
    ans[pos] = n;
    
    cout << "! ";
    for(int x : ans) cout << x << " ";
    cout << endl;
    
    return 0;
}
