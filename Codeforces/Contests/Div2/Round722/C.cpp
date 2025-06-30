/*
Problem: Parsa's Humongous Tree
Link: https://codeforces.com/contest/1529/problem/C
Contest: Codeforces Round #722 (Div. 2)
Approach: LCA and Binary Lifting
         1. Build two trees and precompute LCA information
         2. Use binary lifting to efficiently traverse both trees
         3. Maintain jump arrays for efficient ancestor checks
         4. Use good array to track valid jumps
Time: O(N log N) for preprocessing and O(N log N) for queries
Space: O(N log N) for jump arrays and adjacency lists
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define ROF(i,a,b) for(int i = (b)-1; i >= (a); --i)
#define pb push_back
#define sz(x) (int)(x).size()

const int MX = 3e5 + 10;
const int LOG = 30;

class TreeSolver {
private:
    int N;
    vector<vector<int>> adj[2];  // Two trees
    vector<vector<int>> jmp, jump, jumpLCA, good;
    vector<int> in, out;
    int timer;

    void dfs2(int u, int p) {
        in[u] = ++timer;
        
        jmp[u][0] = p;
        FOR(i,1,LOG) {
            jmp[u][i] = jmp[jmp[u][i-1]][i-1];
        }
        
        for(int v: adj[1][u]) {
            dfs2(v,u);
        }
        
        out[u] = ++timer;
    }

    bool isAncestor(int u, int v) {
        return in[u] <= in[v] && out[u] >= out[v];
    }

    int getLCA(int u, int v) {
        if(isAncestor(u,v)) return u;
        if(isAncestor(v,u)) return v;
        
        ROF(i,0,LOG) {
            if(!isAncestor(jmp[u][i],v)) {
                u = jmp[u][i];
            }
        }
        return jmp[u][0];
    }

    void dfs(int u, int p) {
        jump[u][0] = p;
        jumpLCA[u][0] = p;
        good[u][0] = 1;
        
        FOR(i,1,LOG) {
            jump[u][i] = jump[jump[u][i-1]][i-1];
            jumpLCA[u][i] = getLCA(jumpLCA[u][i-1], jumpLCA[jump[u][i-1]][i-1]);
            good[u][i] = good[u][i-1] && good[jump[u][i-1]][i-1]
                && !isAncestor(jumpLCA[u][i-1], jumpLCA[jump[u][i-1]][i-1])
                && !isAncestor(jumpLCA[jump[u][i-1]][i-1], jumpLCA[u][i-1]);
        }
        
        for(int v: adj[0][u]) {
            dfs(v,u);
        }
    }

public:
    TreeSolver(int n) : N(n) {
        // Initialize data structures
        adj[0].resize(N+1);
        adj[1].resize(N+1);
        jmp.assign(N+1, vector<int>(LOG));
        jump.assign(N+1, vector<int>(LOG));
        jumpLCA.assign(N+1, vector<int>(LOG));
        good.assign(N+1, vector<int>(LOG));
        in.resize(N+1);
        out.resize(N+1);
        timer = 0;
    }

    void addEdge(int u, int v, int tree) {
        adj[tree][u].pb(v);
    }

    void precompute() {
        dfs2(1,1);  // Process second tree
        dfs(1,1);   // Process first tree
    }

    int solve() {
        int ans = 1;
        FOR(node,1,N+1) {
            int cur_lca = node, u = node, cur = 1;
            ROF(i,0,LOG) {
                if(good[u][i]) {
                    if((!isAncestor(cur_lca,jumpLCA[u][i]) && 
                        !isAncestor(jumpLCA[u][i],cur_lca)) || 
                        getLCA(cur_lca,jumpLCA[u][i]) == cur_lca || 
                        getLCA(cur_lca,jumpLCA[u][i]) == jumpLCA[u][i]) {
                        
                        cur_lca = getLCA(cur_lca,jumpLCA[u][i]);
                        u = jump[u][i];
                        cur += (1<<i);
                    }
                }
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        int N;
        cin >> N;
        
        TreeSolver solver(N);
        
        // Read first tree
        FOR(i,0,N-1) {
            int u;
            cin >> u;
            solver.addEdge(u, i+2, 0);
        }
        
        // Read second tree
        FOR(i,0,N-1) {
            int u;
            cin >> u;
            solver.addEdge(u, i+2, 1);
        }
        
        solver.precompute();
        cout << solver.solve() << endl;
    }
    
    return 0;
}
