/*
CF 631B - Dreamoon Likes Permutations
https://codeforces.com/contest/1330/problem/B

Find all ways to split into two permutations
n ≤ 2e5

Key: Check prefix and suffix permutations
*/

#include <bits/stdc++.h>
using namespace std;

bool is_perm(vector<int>& a, int l, int r) {
    vector<bool> seen(r-l+1);
    for(int i = l; i <= r; i++) {
        if(a[i] > r-l+1 || seen[a[i]-1]) return false;
        seen[a[i]-1] = true;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int& x : a) cin >> x;
        
        vector<pair<int,int>> ans;
        for(int i = 1; i < n; i++) {
            if(is_perm(a, 0, i-1) && is_perm(a, i, n-1)) {
                ans.push_back({i, n-i});
            }
        }
        
        cout << ans.size() << '\n';
        for(auto [l1, l2] : ans) {
            cout << l1 << ' ' << l2 << '\n';
        }
    }
    return 0;
}
