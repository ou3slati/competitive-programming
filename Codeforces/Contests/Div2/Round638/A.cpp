/*
CF 638A - Phoenix and Balance
https://codeforces.com/contest/1348/problem/A

Split 2^1..2^n into equal sums
n ≤ 30

Key: First n-1 vs last one
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
        int sum1 = 1 << n;
        int sum2 = 0;
        
        for(int i = 1; i < n/2; i++) {
            sum1 += 1 << i;
        }
        for(int i = n/2; i < n; i++) {
            sum2 += 1 << i;
        }
        
        cout << abs(sum1 - sum2) << '\n';
    }
    return 0;
}
