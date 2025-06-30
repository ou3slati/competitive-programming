/*
CF 646C - Game On Tree
https://codeforces.com/contest/1363/problem/C

Game on tree with x as special vertex
n ≤ 1000

Key: Only degree of x matters
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        x--;
        
        vector<int> deg(n);
        for(int i = 0; i < n-1; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            deg[u]++;
            deg[v]++;
        }
        
        if(deg[x] <= 1) cout << "Ayush\n";
        else cout << (n % 2 ? "Ashish\n" : "Ayush\n");
    }
    return 0;
}
