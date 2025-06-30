/*
CF 666A - Juggling Letters
https://codeforces.com/contest/1397/problem/A

Check if letters can form strings
n ≤ 1000

Key: All counts must be divisible by n
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
        vector<int> cnt(26);
        
        for(int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for(char c : s) cnt[c-'a']++;
        }
        
        bool possible = true;
        for(int x : cnt) {
            if(x % n != 0) possible = false;
        }
        
        cout << (possible ? "YES\n" : "NO\n");
    }
    return 0;
}
