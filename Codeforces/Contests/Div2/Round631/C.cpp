/*
CF 631C - Dreamoon Likes Coloring
https://codeforces.com/contest/1330/problem/C

Color segments with constraints
n,m ≤ 1e5

Key: Place segments from right to left
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<int> l(m);
    long long sum = 0;
    for(int i = 0; i < m; i++) {
        cin >> l[i];
        sum += l[i];
    }
    
    if(sum < n) {
        cout << "-1\n";
        return 0;
    }
    
    vector<int> pos(m);
    int curr = n;
    for(int i = m-1; i >= 0; i--) {
        pos[i] = max(i+1, curr - l[i] + 1);
        if(pos[i] + l[i] - 1 > n) {
            cout << "-1\n";
            return 0;
        }
        curr = pos[i];
    }
    
    if(pos[0] > 1) {
        cout << "-1\n";
        return 0;
    }
    
    for(int x : pos) cout << x << ' ';
    cout << '\n';
    
    return 0;
}
