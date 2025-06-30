/*
CF 645B - Maria Breaks the Self-isolation
https://codeforces.com/contest/1358/problem/B

Max group size possible
n ≤ 1e5, a[i] ≤ 1e5

Key: Sort and check suffix conditions
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
        
        sort(a.begin(), a.end());
        int ans = 1;
        for(int i = n-1; i >= 0; i--) {
            if(a[i] <= i+1) {
                ans = i+2;
                break;
            }
        }
        
        cout << ans << '\n';
    }
    return 0;
}
