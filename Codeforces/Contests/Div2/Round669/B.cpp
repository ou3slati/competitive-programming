/*
CF 669B - Big Vova
https://codeforces.com/contest/1407/problem/B

Rearrange array to maximize GCDs
n ≤ 1000

Key: Take max GCD with prefix
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
        
        vector<bool> used(n);
        vector<int> ans;
        int curr_gcd = 0;
        
        for(int i = 0; i < n; i++) {
            int best = -1, max_gcd = 0;
            for(int j = 0; j < n; j++) {
                if(!used[j]) {
                    int gcd = __gcd(curr_gcd, a[j]);
                    if(gcd > max_gcd) {
                        max_gcd = gcd;
                        best = j;
                    }
                }
            }
            used[best] = true;
            ans.push_back(a[best]);
            curr_gcd = max_gcd;
        }
        
        for(int x : ans) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}
