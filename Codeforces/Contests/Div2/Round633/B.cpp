/*
CF 633B - Sorted Adjacent Differences
https://codeforces.com/contest/1339/problem/B

Rearrange to minimize adjacent differences
n ≤ 1e5, |a[i]| ≤ 1e9

Key: Take middle elements outwards
*/

#include <bits/stdc++.h>
using namespace std;

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
        sort(a.begin(), a.end());
        
        vector<int> ans;
        int l = (n-1)/2, r = n/2;
        while(l >= 0 || r < n) {
            if(l >= 0) ans.push_back(a[l--]);
            if(r < n && r > (n-1)/2) ans.push_back(a[r++]);
        }
        
        for(int x : ans) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}
