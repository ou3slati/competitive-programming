/*
CF 655A - Omkar and Completion
https://codeforces.com/contest/1372/problem/A

Construct array with all pairwise GCDs = 1
n ≤ 1000

Key: All ones works
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
        for(int i = 0; i < n; i++) {
            cout << "1 ";
        }
        cout << '\n';
    }
    return 0;
}
