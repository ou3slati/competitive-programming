/*
CF 663A - Suborrays
https://codeforces.com/contest/1391/problem/A

Construct array with all subarrays good
n ≤ 100

Key: Any permutation works
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
        for(int i = 1; i <= n; i++) {
            cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}
