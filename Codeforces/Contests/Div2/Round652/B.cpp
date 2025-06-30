/*
CF 652B - AccurateLee
https://codeforces.com/contest/1369/problem/B

Min string after operations
n ≤ 1e5

Key: Keep prefix 0s and suffix 1s
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) {
        int n;
        string s;
        cin >> n >> s;
        
        int zeros = 0;
        while(zeros < n && s[zeros] == '0') zeros++;
        
        int ones = n-1;
        while(ones >= 0 && s[ones] == '1') ones--;
        
        if(zeros > ones) cout << s << '\n';
        else cout << string(zeros, '0') + "0" + string(n-ones-1, '1') << '\n';
    }
    return 0;
}
