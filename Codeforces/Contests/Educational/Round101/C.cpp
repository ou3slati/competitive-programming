/*
EDU 101C - Building a Fence
https://codeforces.com/contest/1469/problem/C

Check if fence possible with height constraints
n ≤ 2e5, h[i],k ≤ 1e9

Key: Track min/max possible height at each position
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
        cin >> n >> k;
        vector<int> h(n);
        for(int i = 0; i < n; i++) cin >> h[i];
        
        bool possible = true;
        long long minH = h[0], maxH = h[0];
        
        for(int i = 1; i < n; i++) {
            minH = max(h[i], minH - (k-1));
            maxH = min(h[i] + k-1, maxH + k-1);
            if(minH > maxH) {
                possible = false;
                break;
            }
            if(i == n-1 && h[i] != minH) possible = false;
        }
        
        cout << (possible ? "YES" : "NO") << '\n';
    }
    return 0;
}
