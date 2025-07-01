/*
CF 671A - Digit Game
https://codeforces.com/contest/1419/problem/A

Winner in digit removal game
n ≤ 2000

Key: Check remaining digit parity
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
        
        bool raze = false, breach = false;
        for(int i = 0; i < n; i++) {
            int d = s[i] - '0';
            if(i % 2 == 0 && d % 2 == 1) raze = true;
            if(i % 2 == 1 && d % 2 == 0) breach = true;
        }
        
        if(n % 2 == 1) {
            cout << (raze ? "1\n" : "2\n");
        } else {
            cout << (breach ? "2\n" : "1\n");
        }
    }
    return 0;
}
