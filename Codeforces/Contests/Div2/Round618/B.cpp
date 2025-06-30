/*
CF 618B - Assigning to Classes
https://codeforces.com/contest/1300/problem/B

Split 2N students into N+N, minimize skill difference
n ≤ 10^5, skills ≤ 10^9

Key: Optimal split has consecutive medians after sorting
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
        vector<int> a(2*n);
        for(int i = 0; i < 2*n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        cout << a[n] - a[n-1] << '\n';
    }
    return 0;
}
