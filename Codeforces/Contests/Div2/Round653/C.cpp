/*
CF 653C - Move Brackets
https://codeforces.com/contest/1374/problem/C

Min moves to make brackets valid
n ≤ 50

Key: Count unmatched opens
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
        
        int open = 0, ans = 0;
        for(char c : s) {
            if(c == '(') open++;
            else {
                open--;
                if(open < 0) {
                    ans++;
                    open = 0;
                }
            }
        }
        
        cout << ans << '\n';
    }
    return 0;
}
