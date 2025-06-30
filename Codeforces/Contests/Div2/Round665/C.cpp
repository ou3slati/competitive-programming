/*
CF 665C - Mere Array
https://codeforces.com/contest/1401/problem/C

Check if array sortable with gcd rule
n ≤ 1e5

Key: Elements not divisible by min are fixed
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
        vector<int> a(n), s(n);
        
        int mn = INT_MAX;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            s[i] = a[i];
            mn = min(mn, a[i]);
        }
        
        sort(s.begin(), s.end());
        bool possible = true;
        
        for(int i = 0; i < n; i++) {
            if(a[i] != s[i] && a[i] % mn != 0) {
                possible = false;
                break;
            }
        }
        
        cout << (possible ? "YES\n" : "NO\n");
    }
    return 0;
}
