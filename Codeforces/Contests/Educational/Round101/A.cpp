/*
EDU 101A - Regular Bracket Sequence
https://codeforces.com/contest/1469/problem/A

Check if ?s can be filled to make valid brackets
|s| ≤ 50

Key: Need even length and valid endpoints
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        bool possible = s.length() % 2 == 0 && s[0] != ')' && s.back() != '(';
        cout << (possible ? "YES" : "NO") << '\n';
    }
    return 0;
}
