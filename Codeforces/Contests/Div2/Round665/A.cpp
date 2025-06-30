/*
CF 665A - Distance and Axis
https://codeforces.com/contest/1401/problem/A

Min moves to make |pos - point| = k
n,k ≤ 1e9

Key: Check n < k and parity
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        cout << (n < k ? k-n : (n-k)%2) << '\n';
    }
    return 0;
}
