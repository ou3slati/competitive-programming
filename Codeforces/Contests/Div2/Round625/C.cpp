/*
CF 625C - Remove Adjacent
https://codeforces.com/contest/1321/problem/C

Remove char if greater than both neighbors
n ≤ 100, lowercase letters

Key: Always remove largest possible first
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    string s;
    cin >> n >> s;
    
    int removed = 0;
    for(char c = 'z'; c > 'a'; c--) {
        for(int i = 0; i < s.length(); i++) {
            bool can_remove = s[i] == c;
            if(i > 0) can_remove &= s[i] > s[i-1];
            if(i < s.length()-1) can_remove &= s[i] > s[i+1];
            
            if(can_remove) {
                s.erase(i, 1);
                removed++;
                i--;
            }
        }
    }
    
    cout << removed << '\n';
    return 0;
}
