/*
CF 636A - Candies
https://codeforces.com/contest/1343/problem/A

Find x where n/x is integer and x = 2^k - 1
n ≤ 1e9

Key: Try all k up to 30
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
        
        for(int k = 2; k < 31; k++) {
            int x = (1 << k) - 1;
            if(n % x == 0) {
                cout << n/x << '\n';
                break;
            }
        }
    }
    return 0;
}
