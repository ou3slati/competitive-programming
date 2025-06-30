/*
CF 640C - K-th Not Divisible by n
https://codeforces.com/contest/1352/problem/C

Find k-th number not divisible by n
n,k ≤ 1e9

Key: Use floor division formula
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
        
        // k + floor(k/(n-1)) is k-th number
        cout << k + (k-1)/(n-1) << '\n';
    }
    return 0;
}
