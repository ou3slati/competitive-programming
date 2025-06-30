/*
CF 661A - Remove Smallest
https://codeforces.com/contest/1399/problem/A

Check if array can be emptied
n ≤ 50

Key: Sort and check adjacent
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
        for(int& x : a) cin >> x;
        
        sort(a.begin(), a.end());
        bool possible = true;
        for(int i = 1; i < n; i++) {
            if(a[i] - a[i-1] > 1) {
                possible = false;
                break;
            }
        }
        
        cout << (possible ? "YES\n" : "NO\n");
    }
    return 0;
}
