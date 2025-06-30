/*
CF 660B - Captain Flint and a Long Voyage
https://codeforces.com/contest/1388/problem/B

Construct number with max binary value
n ≤ 1e5

Key: Put 8s at the end
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
        
        int eights = (n + 3) / 4;
        for(int i = 0; i < n-eights; i++) {
            cout << '9';
        }
        for(int i = 0; i < eights; i++) {
            cout << '8';
        }
        cout << '\n';
    }
    return 0;
}
