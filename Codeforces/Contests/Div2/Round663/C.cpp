/*
CF 663C - Cyclic Permutations
https://codeforces.com/contest/1391/problem/C

Count bad permutations
n ≤ 1e6

Key: All but sorted are good
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    ll fact = 1;
    ll pow2 = 1;
    
    for(int i = 1; i < n; i++) {
        fact = fact * (i+1) % MOD;
        pow2 = pow2 * 2 % MOD;
    }
    
    cout << (fact - pow2 + MOD) % MOD << '\n';
    return 0;
}
