/*
CF 636B - Balanced Array
https://codeforces.com/contest/1343/problem/B

Construct array where both halves sum equal
n ≤ 2e5

Key: Even numbers + odd numbers with last adjusted
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
        
        if(n % 4 != 0) {
            cout << "NO\n";
            continue;
        }
        
        cout << "YES\n";
        // First half: even numbers
        for(int i = 2; i <= n; i += 2) {
            cout << i << ' ';
        }
        // Second half: odd numbers except last
        for(int i = 1; i < n-2; i += 2) {
            cout << i << ' ';
        }
        // Last number balances the sum
        cout << n-1 + n/2 << '\n';
    }
    return 0;
}
