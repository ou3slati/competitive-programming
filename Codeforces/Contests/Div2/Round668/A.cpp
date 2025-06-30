/*
CF 668A - Permutation Forgery
https://codeforces.com/contest/1405/problem/A

Find array with same adjacent sums
n ≤ 100

Key: Reverse is always valid
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for(int& x : p) cin >> x;
        
        reverse(p.begin(), p.end());
        for(int x : p) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}
