/*
CF 637B - Nastya and Door
https://codeforces.com/contest/1341/problem/B

Find window with max peaks
n ≤ 2e5

Key: Sliding window on precomputed peaks
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
        
        vector<bool> peak(n);
        int peaks = 0;
        for(int i = 1; i < n-1; i++) {
            peak[i] = (a[i] > a[i-1] && a[i] > a[i+1]);
            if(i < k-1) peaks += peak[i];
        }
        
        int max_peaks = peaks, best_l = 1;
        for(int l = 2; l <= n-k+1; l++) {
            if(peak[l+k-2]) peaks++;
            if(peak[l-1]) peaks--;
            if(peaks > max_peaks) {
                max_peaks = peaks;
                best_l = l;
            }
        }
        
        cout << max_peaks+1 << ' ' << best_l << '\n';
    }
    return 0;
}
