/*
CF 632A - Little Artem
https://codeforces.com/contest/1333/problem/A

Create n×m board with more B than W
n,m ≤ 100

Key: Fill with B except one W in corner
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        
        cout << "W";
        for(int j = 1; j < m; j++) cout << "B";
        cout << '\n';
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) cout << "B";
            cout << '\n';
        }
    }
    return 0;
}
