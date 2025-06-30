/*
CF 646B - Substring Removal Game
https://codeforces.com/contest/1363/problem/B

Max score in alternating removal game
|s| ≤ 100

Key: Take largest blocks of 1s
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) {
        string s;
        cin >> s;
        
        vector<int> blocks;
        int curr = 1;
        for(int i = 1; i <= s.length(); i++) {
            if(i < s.length() && s[i] == s[i-1]) curr++;
            else {
                if(s[i-1] == '1') blocks.push_back(curr);
                curr = 1;
            }
        }
        
        sort(blocks.rbegin(), blocks.rend());
        int ans = 0;
        for(int i = 0; i < blocks.size(); i += 2) {
            ans += blocks[i];
        }
        
        cout << ans << '\n';
    }
    return 0;
}
