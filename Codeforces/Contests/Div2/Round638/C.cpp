/*
CF 638C - Phoenix and Distribution
https://codeforces.com/contest/1348/problem/C

Make lexicographically smallest string
n ≤ 1e5

Key: Sort and analyze first different char
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
        string s;
        cin >> n >> k >> s;
        sort(s.begin(), s.end());
        
        if(s[0] != s[k-1]) {
            cout << s[k-1] << '\n';
            continue;
        }
        
        cout << s[0];
        if(s[k] != s[n-1]) {
            for(int i = k; i < n; i++) cout << s[i];
        } else {
            for(int i = 0; i < (n-k+k-1)/k; i++) cout << s[k];
        }
        cout << '\n';
    }
    return 0;
}
