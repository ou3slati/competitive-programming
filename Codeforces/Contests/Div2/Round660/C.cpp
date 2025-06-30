/*
CF 660C - Uncle Bogdan and Country Happiness
https://codeforces.com/contest/1388/problem/C

Check if happiness values possible
n ≤ 1e5

Key: Track min/max good people
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> adj;
vector<ll> p, h, total, good;
bool possible = true;

ll dfs(int v, int par = -1) {
    total[v] = p[v];
    for(int u : adj[v]) {
        if(u != par) {
            total[v] += dfs(u, v);
        }
    }
    
    // good - bad = h[v]
    // good + bad = total[v]
    // 2*good = total[v] + h[v]
    good[v] = (total[v] + h[v]);
    if(good[v] % 2 || good[v] < 0 || good[v] > 2*total[v]) {
        possible = false;
    }
    good[v] /= 2;
    
    ll sum_good = 0;
    for(int u : adj[v]) {
        if(u != par) {
            sum_good += good[u];
        }
    }
    if(sum_good > good[v]) possible = false;
    
    return total[v];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        
        adj.assign(n, vector<int>());
        p.resize(n); h.resize(n);
        total.resize(n); good.resize(n);
        possible = true;
        
        for(int i = 0; i < n; i++) cin >> p[i];
        for(int i = 0; i < n; i++) cin >> h[i];
        
        for(int i = 0; i < n-1; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        dfs(0);
        cout << (possible ? "YES\n" : "NO\n");
    }
    return 0;
}
