/*
CF 642B - Two Arrays And Swaps
https://codeforces.com/contest/1353/problem/B

Max sum after k swaps
n,k ≤ 30

Key: Sort both, swap largest with smallest
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for(int& x : a) cin >> x;
        for(int& x : b) cin >> x;
        
        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());
        
        for(int i = 0; i < k && i < n && b[i] > a[i]; i++) {
            swap(a[i], b[i]);
        }
        
        cout << accumulate(a.begin(), a.end(), 0) << '\n';
    }
    return 0;
}
