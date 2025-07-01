/*
CF 672A - Cubes Sorting
https://codeforces.com/contest/1420/problem/A

Check if array can be sorted with bubble sort in less than n(n-1)/2 swaps
n ≤ 5e4

Key insights:
1. Array can be sorted if it's not strictly decreasing
2. Any non-decreasing adjacent pair allows sorting
3. Only strictly decreasing sequence needs max swaps
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
        vector<long long> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        // Check if strictly decreasing
        bool strictly_decreasing = true;
        for(int i = 0; i < n-1; i++) {
            if(a[i] <= a[i+1]) {
                strictly_decreasing = false;
                break;
            }
        }
        
        // If not strictly decreasing, we can sort with < n(n-1)/2 swaps
        cout << (strictly_decreasing ? "NO" : "YES") << '\n';
    }
    
    return 0;
}
