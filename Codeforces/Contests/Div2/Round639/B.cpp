/*
CF 639B - Card Constructions
https://codeforces.com/contest/1345/problem/B

Max pyramids from n cards
n ≤ 1e9

Key: Greedy with precomputed sizes
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // Precompute pyramid sizes
    vector<int> pyramid;
    for(int h = 1; ; h++) {
        int cards = (h * (3*h + 1)) / 2;
        if(cards > 1e9) break;
        pyramid.push_back(cards);
    }
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        
        int ans = 0;
        while(n >= 2) {
            auto it = upper_bound(pyramid.begin(), pyramid.end(), n);
            if(it == pyramid.begin()) break;
            --it;
            n -= *it;
            ans++;
        }
        
        cout << ans << '\n';
    }
    return 0;
}
