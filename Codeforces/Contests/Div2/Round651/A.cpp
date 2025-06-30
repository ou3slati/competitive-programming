/*
CF 651A - Maximum GCD
https://codeforces.com/contest/1370/problem/A

Max GCD of two numbers up to n
n ≤ 4e5

Key: n/2 with n gives max GCD
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
        cout << n/2 << '\n';
    }
    return 0;
}
