/*
CF 629B - K-th Beautiful String
https://codeforces.com/contest/1328/problem/B

Find k-th string with exactly two 'b's
n ≤ 2e5, k ≤ n*(n-1)/2

Key: Position of second b determines order
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
        k--;  // 0-based
        
        // Find position of second b
        int pos = 0;
        while(pos * (pos + 1) / 2 <= k) pos++;
        pos--;
        
        // Find position of first b
        int first = k - pos * (pos + 1) / 2;
        
        string s(n, 'a');
        s[n - pos - 2] = 'b';
        s[n - first - 1] = 'b';
        cout << s << '\n';
    }
    return 0;
}
