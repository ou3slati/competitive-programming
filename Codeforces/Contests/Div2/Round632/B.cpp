/*
CF 632B - Kind Anton
https://codeforces.com/contest/1333/problem/B

Check if array transformable using -1,0,1
n ≤ 1e5, |a[i]| ≤ 1e9

Key: Track available numbers from left
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
        vector<int> a(n), b(n);
        for(int& x : a) cin >> x;
        for(int& x : b) cin >> x;
        
        bool has_pos = false, has_neg = false;
        bool possible = true;
        
        for(int i = 0; i < n; i++) {
            if(a[i] != b[i]) {
                if(b[i] > a[i] && !has_pos) possible = false;
                if(b[i] < a[i] && !has_neg) possible = false;
            }
            if(a[i] > 0) has_pos = true;
            if(a[i] < 0) has_neg = true;
        }
        
        cout << (possible ? "YES" : "NO") << '\n';
    }
    return 0;
}
