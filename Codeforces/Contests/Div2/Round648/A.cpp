/*
CF 648A - Matrix Game
https://codeforces.com/contest/1365/problem/A

Game on matrix taking empty rows/cols
n,m ≤ 50

Key: Count free rows and cols
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<bool> row(n), col(m);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int x; cin >> x;
                if(x) row[i] = col[j] = true;
            }
        }
        
        int free = min(count(row.begin(), row.end(), false),
                      count(col.begin(), col.end(), false));
                      
        cout << (free % 2 ? "Ashish\n" : "Vivek\n");
    }
    return 0;
}
