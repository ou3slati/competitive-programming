/*
CF 629A - Divisibility Problem
https://codeforces.com/contest/1328/problem/A

Min moves to make a divisible by b
a,b ≤ 1e9

Key: Next multiple minus current
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        long long a, b;
        cin >> a >> b;
        cout << (b - a % b) % b << '\n';
    }
    return 0;
}
