/*
CF 625A - Contest for Robots
https://codeforces.com/contest/1321/problem/A

Compare robot arrays, need wins > losses
n ≤ 100, values binary

Key: Only positions where robot1 wins matter
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    int wins = 0, losses = 0;
    vector<int> r1(n), r2(n);
    
    for(int& x : r1) cin >> x;
    for(int& x : r2) cin >> x;
    
    for(int i = 0; i < n; i++) {
        if(r1[i] && !r2[i]) wins++;
        if(!r1[i] && r2[i]) losses++;
    }
    
    if(!wins) cout << "-1\n";
    else cout << (losses + 1 + wins - 1) / wins << '\n';
    
    return 0;
}
