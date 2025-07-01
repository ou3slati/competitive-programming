/*
CF 671D2 - Sage's Birthday (hard version)
https://codeforces.com/contest/1419/problem/D2

Maximize number of elements strictly less than both neighbors
n ≤ 1e5

Key insights:
1. Binary search on number of peaks possible
2. Place smaller elements in odd positions
3. Place larger elements in even positions and remaining positions
4. Verify if arrangement works
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    int left = 0, right = (n-1)/2;
    int ans = 0;
    vector<int> result;
    
    // Binary search on number of peaks
    while(left <= right) {
        int mid = (left + right) / 2;
        vector<int> curr(n);
        
        // Place smaller elements in odd positions
        int j = 0;
        for(int i = 1; i < n && j < mid; i += 2) {
            curr[i] = a[j++];
        }
        
        // Place larger elements starting from end
        j = n - mid - 1;
        for(int i = 0; i < n && j < n; i += 2) {
            curr[i] = a[j++];
        }
        
        // Fill remaining positions
        j = mid;
        for(int i = 2*mid + 1; i < n; i++) {
            curr[i] = a[j++];
        }
        
        // Count valid peaks
        int peaks = 0;
        for(int i = 1; i < n-1; i++) {
            if(curr[i] < curr[i-1] && curr[i] < curr[i+1]) {
                peaks++;
            }
        }
        
        if(peaks >= mid) {
            ans = mid;
            result = curr;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    cout << ans << '\n';
    for(int x : result) {
        cout << x << ' ';
    }
    cout << '\n';
    
    return 0;
}
