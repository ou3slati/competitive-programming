/*
CF 667C - Yet Another Array Restoration
https://codeforces.com/contest/1409/problem/C

Restore array from two elements
n ≤ 50, x,y ≤ 50

Key: Try all possible differences
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) {
        int n, x, y;
        cin >> n >> x >> y;
        
        int best_d = y-x;
        vector<int> best(n);
        
        for(int d = 1; d <= y-x; d++) {
            if((y-x) % d != 0) continue;
            
            vector<int> curr;
            int val = y;
            while(val > 0 && curr.size() < n) {
                curr.push_back(val);
                val -= d;
            }
            
            val = y + d;
            while(curr.size() < n) {
                curr.push_back(val);
                val += d;
            }
            
            if(find(curr.begin(), curr.end(), x) != curr.end()) {
                if(curr.back() < best.back() || best.empty()) {
                    best = curr;
                }
            }
        }
        
        for(int x : best) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}
