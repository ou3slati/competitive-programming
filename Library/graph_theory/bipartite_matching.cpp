/*
 * Maximum Bipartite Matching using Hungarian Algorithm (DFS-based)
 * Time: O(VE) | Space: O(V + E)
 * Finds maximum matching in bipartite graph using augmenting paths
 */

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll

class BipartiteMatching {
private:
    vector<vector<int>> adj;
    vector<int> match, visited;
    int n, m;
    
    bool dfs(int u) {
        if (visited[u]) return false;
        visited[u] = true;
        
        for (int v : adj[u]) {
            // If v is unmatched or we can find augmenting path from match[v]
            if (match[v] == -1 || dfs(match[v])) {
                match[v] = u;
                return true;
            }
        }
        
        return false;
    }
    
public:
    BipartiteMatching(int left_size, int right_size) : n(left_size), m(right_size), 
                     adj(left_size), match(left_size + right_size, -1), visited(left_size) {}
    
    void add_edge(int u, int v) {
        adj[u].push_back(v + n); // Offset right vertices by n
    }
    
    int max_matching() {
        int result = 0;
        
        for (int u = 0; u < n; u++) {
            fill(visited.begin(), visited.end(), false);
            if (dfs(u)) {
                result++;
            }
        }
        
        return result;
    }
    
    // Get the actual matching pairs
    vector<pair<int, int>> get_matching() {
        max_matching();
        vector<pair<int, int>> matching;
        
        for (int v = n; v < n + m; v++) {
            if (match[v] != -1) {
                matching.push_back({match[v], v - n});
            }
        }
        
        return matching;
    }
    
    // Check if graph is bipartite (bonus utility)
    static bool is_bipartite(const vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        
        for (int start = 0; start < n; start++) {
            if (color[start] == -1) {
                queue<int> q;
                q.push(start);
                color[start] = 0;
                
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    
                    for (int v : graph[u]) {
                        if (color[v] == -1) {
                            color[v] = 1 - color[u];
                            q.push(v);
                        } else if (color[v] == color[u]) {
                            return false;
                        }
                    }
                }
            }
        }
        
        return true;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    // Assuming vertices are 1-indexed, we need to determine left/right partition sizes
    // For simplicity, assuming first n/2 are left, rest are right
    int left_size = (n + 1) / 2;
    int right_size = n - left_size;
    
    BipartiteMatching bm(left_size, right_size);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--; // Convert to 0-indexed
        
        // Determine which side each vertex belongs to
        if (u < left_size && v >= left_size) {
            bm.add_edge(u, v - left_size);
        } else if (v < left_size && u >= left_size) {
            bm.add_edge(v, u - left_size);
        }
    }
    
    cout << bm.max_matching() << "\n";
    
    // Print matching pairs
    auto matching = bm.get_matching();
    for (auto [u, v] : matching) {
        cout << u + 1 << " " << (v + left_size + 1) << "\n";
    }
    
    return 0;
}
