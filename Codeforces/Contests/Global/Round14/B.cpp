/*
Global 14B - Phoenix and Puzzle
https://codeforces.com/contest/1515/problem/B

Check if N can be split into identical right triangles
n ≤ 10^9

Key: Only possible if N/2 or N/4 is perfect square
*/

#include <bits/stdc++.h>
using namespace std;

bool isSquare(long long x) {
    if(x < 0) return false;
    long long s = sqrt(x);
    return s * s == x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        bool possible = (n % 2 == 0 && isSquare(n/2)) || 
                       (n % 4 == 0 && isSquare(n/4));
        cout << (possible ? "YES" : "NO") << '\n';
    }
    return 0;
}
