/*
CF 648B - Trouble Sort
https://codeforces.com/contest/1365/problem/B

Check if array can be sorted
n ≤ 500

Key: Can sort if both types exist
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
        bool has0 = false, has1 = false;
        
        for(int& x : a) cin >> x;
        for(int i = 0; i < n; i++) {
            int b;
            cin >> b;
            if(b) has1 = true;
            else has0 = true;
        }
        
        bool sorted = is_sorted(a.begin(), a.end());
        cout << (sorted || (has0 && has1) ? "Yes\n" : "No\n");
    }
    return 0;
}
