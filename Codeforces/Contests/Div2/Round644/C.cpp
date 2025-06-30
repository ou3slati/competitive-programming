/*
CF 644C - Similar Pairs
https://codeforces.com/contest/1360/problem/C

Group into similar pairs
n ≤ 50, a[i] ≤ 100

Key: Count parities and check adjacents
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
        vector<int> a(n);
        int odd = 0;
        for(int& x : a) {
            cin >> x;
            odd += x % 2;
        }
        
        if(odd % 2) {
            cout << "NO\n";
            continue;
        }
        
        sort(a.begin(), a.end());
        bool found = odd % 2 == 0;
        for(int i = 1; i < n && !found; i++) {
            if(a[i] - a[i-1] == 1) found = true;
        }
        
        cout << (found ? "YES\n" : "NO\n");
    }
    return 0;
}
