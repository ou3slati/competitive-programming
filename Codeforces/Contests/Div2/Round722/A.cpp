/*
CF 722A - Eshag Loves Big Arrays
https://codeforces.com/contest/1529/problem/A

Make array mean = minimum in array
n ≤ 100, a[i] ≤ 100

Key: Only elements equal to min can stay
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
        int mn = INT_MAX, cnt = 0;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            if(x < mn) mn = x, cnt = 1;
            else if(x == mn) cnt++;
        }
        cout << n - cnt << '\n';
    }
    return 0;
}
