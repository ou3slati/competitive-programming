/*
CF 647B - Johnny and His Hobbies
https://codeforces.com/contest/1362/problem/B

Find k where s⊕k gives permutation of s
n ≤ 1024

Key: Try all k up to 1024
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
        vector<int> s(n);
        for(int& x : s) cin >> x;
        sort(s.begin(), s.end());
        
        int ans = -1;
        for(int k = 1; k <= 1024; k++) {
            vector<int> xored;
            for(int x : s) xored.push_back(x ^ k);
            sort(xored.begin(), xored.end());
            if(xored == s) {
                ans = k;
                break;
            }
        }
        
        cout << ans << '\n';
    }
    return 0;
}
