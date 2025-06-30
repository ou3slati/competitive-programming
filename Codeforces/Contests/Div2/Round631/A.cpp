/*
CF 631A - Dreamoon and Ranking Collection
https://codeforces.com/contest/1330/problem/A

Find min missing after adding x new numbers
n,x ≤ 100, a[i] ≤ 100

Key: Mark present, fill smallest gaps
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        vector<bool> has(201);
        
        for(int i = 0; i < n; i++) {
            int v;
            cin >> v;
            has[v] = true;
        }
        
        int pos = 1;
        while(x || has[pos]) {
            if(!has[pos]) x--;
            pos++;
        }
        
        cout << pos-1 << '\n';
    }
    return 0;
}
