/*
CF 665A - Distance and Axis
https://codeforces.com/contest/1401/problem/A

Move point to satisfy |pos - point| = K
n,k ≤ 10^9

Key: When n ≥ k, need same parity for n-k
When n < k, must reach k
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        cout << (n < k ? k-n : (n-k)%2) << '\n';
    }
    return 0;
}
