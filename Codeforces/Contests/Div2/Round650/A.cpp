/*
CF 650A - Short Substrings
https://codeforces.com/contest/1367/problem/A

Recover string from all len-2 substrings
|b| ≤ 100

Key: Each char except first/last appears twice
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) {
        string b;
        cin >> b;
        string a;
        a += b[0];
        for(int i = 1; i < b.length(); i += 2) {
            a += b[i];
        }
        cout << a << '\n';
    }
    return 0;
}
