/*
CF 649C - Ehab and Prefix MEXs
https://codeforces.com/contest/1364/problem/C

Find array with given MEX prefix array
n ≤ 1e5

Key: Use unused numbers for jumps
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n), b(n, -1);
    set<int> unused;
    
    for(int i = 0; i <= n; i++) unused.insert(i);
    for(int& x : a) {
        cin >> x;
        unused.erase(x);
    }
    
    if(a[0] > 1) {
        cout << "-1\n";
        return 0;
    }
    
    for(int i = n-1; i >= 0; i--) {
        if(i == 0 || a[i] != a[i-1]) {
            b[i] = a[i]-1;
            unused.erase(a[i]-1);
        }
    }
    
    for(int i = 0; i < n; i++) {
        if(b[i] == -1) {
            auto it = unused.begin();
            b[i] = *it;
            unused.erase(it);
        }
    }
    
    for(int x : b) cout << x << ' ';
    cout << '\n';
    
    return 0;
}
