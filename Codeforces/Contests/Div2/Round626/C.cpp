/*
CF 626C - Unusual Competitions
https://codeforces.com/contest/1323/problem/C

Fix bracket sequence with min operations
n ≤ 1e6

Key: Process invalid segments between valid prefixes
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    string s;
    cin >> n >> s;
    
    int bal = 0, ans = 0;
    for(char c : s) bal += (c == '(' ? 1 : -1);
    
    if(bal != 0) {
        cout << "-1\n";
        return 0;
    }
    
    bal = 0;
    int start = -1;
    for(int i = 0; i < n; i++) {
        bal += (s[i] == '(' ? 1 : -1);
        if(bal < 0 && start == -1) start = i;
        if(bal == 0 && start != -1) {
            ans += i - start + 1;
            start = -1;
        }
    }
    
    cout << ans << '\n';
    return 0;
}
