/*
CF 659B - GameGame
https://codeforces.com/contest/1384/problem/B

Game with xor operations
n ≤ 2e5

Key: Count bits in each position
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
        vector<int> a(n);
        for(int& x : a) cin >> x;
        
        vector<int> bits(30);
        for(int x : a) {
            for(int i = 0; i < 30; i++) {
                if(x & (1 << i)) bits[i]++;
            }
        }
        
        bool first_wins = false;
        for(int i = 29; i >= 0; i--) {
            if(bits[i] % 2) {
                first_wins = true;
                break;
            }
        }
        
        cout << (first_wins ? "WIN\n" : "LOSE\n");
    }
    return 0;
}
