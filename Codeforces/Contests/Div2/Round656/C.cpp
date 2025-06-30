/*
CF 656C - Make It Good
https://codeforces.com/contest/1385/problem/C

Min prefix to remove to make good
n ≤ 2e5

Key: Find rightmost peak
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int& x : a) cin >> x;
        
        int pos = n-1;
        while(pos > 0 && a[pos-1] >= a[pos]) pos--;
        while(pos > 0 && a[pos-1] <= a[pos]) pos--;
        
        cout << pos << '\n';
    }
    return 0;
}
