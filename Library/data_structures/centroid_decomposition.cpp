/*
 * Centroid Decomposition
 * Time: O(n log n) preprocessing | Space: O(n)
 * Recursively decomposes tree into balanced subtrees using centroids
 */

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll

class CentroidDecomposition {
private:
    vector<vector<int>> adj;
    vector<int> parent, subtree_size;
    vector<bool> removed;
    int n;
    
    void compute_subtree_size(int u, int p) {
        subtree_size[u] = 1;
        for (int v : adj[u]) {
            if (v != p && !removed[v]) {
                compute_subtree_size(v, u);
                subtree_size[u] += subtree_size[v];
            }
        }
    }
    
    int find_centroid(int u, int p, int tree_size) {
        for (int v : adj[u]) {
            if (v != p && !removed[v] && subtree_size[v] > tree_size / 2) {
                return find_centroid(v, u, tree_size);
            }
        }
        return u;
    }
    
    void decompose(int u, int p) {
        compute_subtree_size(u, -1);
        int centroid = find_centroid(u, -1, subtree_size[u]);
        
        parent[centroid] = p;
        removed[centroid] = true;
        
        for (int v : adj[centroid]) {
            if (!removed[v]) {
                decompose(v, centroid);
            }
        }
    }
    
public:
    CentroidDecomposition(int size) : n(size), adj(size + 1), parent(size + 1), 
                                     subtree_size(size + 1), removed(size + 1, false) {}
    
    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    void build(int root = 1) {
        decompose(root, -1);
    }
    
    int get_centroid_parent(int u) {
        return parent[u];
    }
    
    // Get distance between two nodes in original tree
    int distance(int u, int v, vector<vector<int>>& original_adj) {
        if (u == v) return 0;
        
        vector<int> dist(n + 1, -1);
        queue<int> q;
        q.push(u);
        dist[u] = 0;
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            if (curr == v) return dist[v];
            
            for (int next : original_adj[curr]) {
                if (dist[next] == -1) {
                    dist[next] = dist[curr] + 1;
                    q.push(next);
                }
            }
        }
        
        return -1; // Should not reach here in connected tree
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    CentroidDecomposition cd(n);
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        cd.add_edge(u, v);
    }
    
    cd.build();
    
    // Print centroid tree parents
    for (int i = 1; i <= n; i++) {
        cout << cd.get_centroid_parent(i) << " ";
    }
    cout << "\n";
    
    return 0;
}
