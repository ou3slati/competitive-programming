/*
CF 649A - XXXXX
https://codeforces.com/contest/1364/problem/A

Longest subarray with sum not divisible by x
n ≤ 1e5

Key: Check prefix sums from both ends
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        int sum = 0;
        for(int& v : a) {
            cin >> v;
            sum = (sum + v) % x;
        }
        
        if(sum != 0) {
            cout << n << '\n';
            continue;
        }
        
        int first = n, last = -1;
        sum = 0;
        for(int i = 0; i < n; i++) {
            sum = (sum + a[i]) % x;
            if(sum != 0) first = i + 1;
        }
        
        sum = 0;
        for(int i = n-1; i >= 0; i--) {
            sum = (sum + a[i]) % x;
            if(sum != 0) last = n - i;
        }
        
        int ans = max(first, last);
        cout << (ans ? ans : -1) << '\n';
    }
    return 0;
}
