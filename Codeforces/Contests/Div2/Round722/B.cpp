/*
CF 722B - Sifid and Strange Subsequences
https://codeforces.com/contest/1529/problem/B

Max subsequence where |any two elements| ≥ min(subsequence)
n ≤ 10^5, |a[i]| ≤ 10^9

Key: Sort, take all negatives + smallest positive if valid
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
        
        int ans = 0;
        int min_diff = INT_MAX;
        
        // Count negatives and zero
        while(ans < n && a[ans] <= 0) {
            if(ans > 0) min_diff = min(min_diff, a[ans] - a[ans-1]);
            ans++;
        }
        
        // Add smallest positive if possible
        if(ans < n && (ans == 0 || a[ans] >= min_diff)) ans++;
        
        cout << ans << '\n';
    }
    return 0;
}
