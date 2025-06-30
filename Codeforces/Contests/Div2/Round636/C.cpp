/*
CF 636C - Alternating Subsequence
https://codeforces.com/contest/1343/problem/C

Max sum with alternating signs
n ≤ 2e5, |a[i]| ≤ 1e9

Key: Take max in each sign group
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
        
        ll sum = 0;
        int curr_max = a[0];
        
        for(int i = 1; i < n; i++) {
            if((a[i] > 0) == (curr_max > 0)) {
                curr_max = max(curr_max, a[i]);
            } else {
                sum += curr_max;
                curr_max = a[i];
            }
        }
        sum += curr_max;
        
        cout << sum << '\n';
    }
    return 0;
}
