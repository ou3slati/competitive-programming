/*
Problem: Eshag Loves Big Arrays
Link: https://codeforces.com/contest/1529/problem/A
Contest: Codeforces Round #722 (Div. 2)
Approach: Tree DP - For each node, we try both possible values and propagate the maximum result
Time: O(N) where N is the number of nodes
Space: O(N) for memoization and adjacency list
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define endl "\n"
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)

const int MX = 2e5 + 10;

int N; 
vi a(MX), b(MX);
vector<vi> adj(MX);
vector<vector<int>> memo;

int solve(int u, int p, int x) {
    int &ind = memo[u][x];
    if(ind != -1) return ind; 
    
    int val = 0, vall = 0;
    if(u) {
        if(!x) {
            val = abs(a[u] - a[p]);
            vall = abs(b[u] - a[p]);
        }
        else {
            val = abs(a[u] - b[p]);
            vall = abs(b[u] - b[p]);
        }
    }
    
    for(int v: adj[u]) if(v != p) {
        val += solve(v, u, 0);
        vall += solve(v, u, 1);
    }

    return ind = max(val, vall); 
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while(t--) {
        cin >> N; 
        FOR(i,0,N) {
            cin >> a[i] >> b[i];
            adj[i].clear();
        }

        FOR(i,0,N-1) {
            int u, v; 
            cin >> u >> v; 
            u--; v--;
            adj[u].pb(v); 
            adj[v].pb(u);
        }

        memo.assign(N, vector<int>(2, -1));
        cout << solve(0, 0, 0) << endl;
    }

    return 0;
}
