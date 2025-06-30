/*
CF 636D - Constant Palindrome Sum
https://codeforces.com/contest/1343/problem/D

Min moves to make all pairs sum same
n ≤ 2e5, k ≤ 2e5

Key: Track ranges of possible sums
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
        vector<int> a(n);
        for(int& x : a) cin >> x;
        
        // Track sum ranges
        vector<int> change(2*k + 2);
        map<int,int> pairs;
        
        for(int i = 0; i < n/2; i++) {
            int x = a[i], y = a[n-1-i];
            int sum = x + y;
            pairs[sum]++;
            
            // Range of possible sums with one change
            int mn = min(x,y) + 1;
            int mx = max(x,y) + k;
            change[mn]++;
            change[mx+1]--;
            
            // Range with two changes
            change[2]++;
            change[2*k+1]--;
        }
        
        // Process prefix sums
        for(int i = 1; i <= 2*k; i++) {
            change[i] += change[i-1];
        }
        
        // Find minimum operations
        int ans = n;
        for(int sum = 2; sum <= 2*k; sum++) {
            int ops = change[sum] - pairs[sum];
            ans = min(ans, ops);
        }
        
        cout << ans << '\n';
    }
    return 0;
}
