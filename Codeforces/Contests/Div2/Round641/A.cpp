/*
CF 641A - Orac and Factors
https://codeforces.com/contest/1349/problem/A

Find next number after operations
n ≤ 1e9, k ≤ 1e9

Key: Find smallest divisor first
*/

#include <bits/stdc++.h>
using namespace std;

int smallest_divisor(int n) {
    for(int i = 2; i*i <= n; i++)
        if(n % i == 0) return i;
    return n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        cout << n + smallest_divisor(n) + 2*(k-1) << '\n';
    }
    return 0;
}
