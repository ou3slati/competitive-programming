/*
CF 670C - Link Cut Centroids
https://codeforces.com/contest/1406/problem/C

Make tree have unique centroid
n ≤ 1e5

Key: Remove and add edge to leaf
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> size;
int n;

int get_size(int v, int p = -1) {
    size[v] = 1;
    for(int u : adj[v]) {
        if(u != p) {
            size[v] += get_size(u, v);
        }
    }
    return size[v];
}

pair<int,int> get_centroid(int v, int p = -1) {
    pair<int,int> res = {v, -1};
    int s = 1, ms = 0;
    for(int u : adj[v]) {
        if(u != p) {
            auto tmp = get_centroid(u, v);
            if(tmp.second != -1) return tmp;
            s += size[u];
            ms = max(ms, size[u]);
        }
    }
    ms = max(ms, n - s);
    if(ms <= n/2) res.second = ms;
    return res;
}

int get_leaf(int v, int p = -1) {
    if(adj[v].size() == 1) return v;
    for(int u : adj[v]) {
        if(u != p) {
            int leaf = get_leaf(u, v);
            if(leaf != -1) return leaf;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) {
        cin >> n;
        adj.assign(n, vector<int>());
        size.assign(n, 0);
        
        for(int i = 0; i < n-1; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        get_size(0);
        auto [c1, ms1] = get_centroid(0);
        
        if(ms1 < n/2) {
            cout << "1 1\n1 1\n";
            continue;
        }
        
        int leaf = get_leaf(c1);
        int parent = -1;
        for(int u : adj[leaf]) {
            parent = u;
        }
        
        cout << leaf+1 << ' ' << parent+1 << '\n';
        cout << leaf+1 << ' ' << c1+1 << '\n';
    }
    return 0;
}
