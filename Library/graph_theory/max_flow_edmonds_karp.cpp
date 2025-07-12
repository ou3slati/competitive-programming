/*
 * Edmonds-Karp Maximum Flow Algorithm
 * Time: O(VE²) | Space: O(V²)
 * Finds maximum flow in a flow network using BFS for shortest augmenting paths
 */

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll

class MaxFlow {
private:
    vector<vector<int>> capacity, adj;
    int n;
    
    int bfs(int source, int sink, vector<int>& parent) {
        fill(parent.begin(), parent.end(), -1);
        parent[source] = -2;
        queue<pair<int, int>> q;
        q.push({source, LLONG_MAX});
        
        while (!q.empty()) {
            int cur = q.front().first;
            int flow = q.front().second;
            q.pop();
            
            for (int next : adj[cur]) {
                if (parent[next] == -1 && capacity[cur][next] > 0) {
                    parent[next] = cur;
                    int new_flow = min(flow, capacity[cur][next]);
                    if (next == sink) {
                        return new_flow;
                    }
                    q.push({next, new_flow});
                }
            }
        }
        
        return 0;
    }
    
public:
    MaxFlow(int vertices) : n(vertices), capacity(n, vector<int>(n, 0)), adj(n) {}
    
    void add_edge(int from, int to, int cap) {
        capacity[from][to] += cap;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    
    int edmonds_karp(int source, int sink) {
        int flow = 0;
        vector<int> parent(n);
        int new_flow;
        
        while ((new_flow = bfs(source, sink, parent)) > 0) {
            flow += new_flow;
            int cur = sink;
            
            // Update residual capacities along the path
            while (cur != source) {
                int prev = parent[cur];
                capacity[prev][cur] -= new_flow;
                capacity[cur][prev] += new_flow;
                cur = prev;
            }
        }
        
        return flow;
    }
    
    // Get minimum cut - returns vertices reachable from source in residual graph
    vector<bool> min_cut(int source) {
        vector<bool> reachable(n, false);
        queue<int> q;
        q.push(source);
        reachable[source] = true;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (int v : adj[u]) {
                if (!reachable[v] && capacity[u][v] > 0) {
                    reachable[v] = true;
                    q.push(v);
                }
            }
        }
        
        return reachable;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int V, source, sink;
    cin >> V >> source >> sink;
    
    MaxFlow mf(V);
    
    for (int i = 0; i < V; i++) {
        int edges;
        cin >> edges;
        for (int j = 0; j < edges; j++) {
            int to, capacity;
            cin >> to >> capacity;
            mf.add_edge(i, to, capacity);
        }
    }
    
    cout << mf.edmonds_karp(source, sink) << "\n";
    
    return 0;
}
