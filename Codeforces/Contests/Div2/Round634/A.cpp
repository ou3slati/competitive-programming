/*
CF 634A - Candies and Two Sisters
https://codeforces.com/contest/1335/problem/A

Split n candies with b > a
n ≤ 2e9

Key: (n-1)/2 valid splits
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
        cout << (n-1)/2 << '\n';
    }
    return 0;
}
