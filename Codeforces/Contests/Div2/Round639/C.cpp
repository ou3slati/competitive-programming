/*
CF 639C - Hilbert's Hotel
https://codeforces.com/contest/1345/problem/C

Check if all rooms unique after shifts
n ≤ 2e5, |a[i]| ≤ 1e9

Key: Use modulo arithmetic carefully
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<bool> used(n);
        bool valid = true;
        
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            int room = ((i + x) % n + n) % n;
            if(used[room]) valid = false;
            used[room] = true;
        }
        
        cout << (valid ? "YES\n" : "NO\n");
    }
    return 0;
}
