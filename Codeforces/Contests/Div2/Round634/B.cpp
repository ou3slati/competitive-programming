/*
CF 634B - Construct String
https://codeforces.com/contest/1335/problem/B

Build string with fixed substring frequencies
n,a,b ≤ 1000

Key: Repeat pattern of length a with b chars
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        int n, a, b;
        cin >> n >> a >> b;
        
        string s;
        for(int i = 0; i < n; i++) {
            s += (char)('a' + i % b);
        }
        cout << s << '\n';
    }
    return 0;
}
