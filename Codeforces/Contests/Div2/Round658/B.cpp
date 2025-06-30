/*
CF 658B - Sequential Nim
https://codeforces.com/contest/1382/problem/B

Game with removing stones
n ≤ 1e5

Key: Count consecutive ones
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
        
        int ones = 0;
        while(ones < n && a[ones] == 1) ones++;
        
        if(ones == n) cout << (n%2 ? "First\n" : "Second\n");
        else cout << (ones%2 ? "Second\n" : "First\n");
    }
    return 0;
}
