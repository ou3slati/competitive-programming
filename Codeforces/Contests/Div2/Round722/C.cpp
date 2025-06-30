/*
CF 722C - Parsa's Humongous Tree
https://codeforces.com/contest/1529/problem/C

Tree with two possible values per node
Maximize sum of |adjacent differences|
n ≤ 2e5, values ≤ 1e9

Key: dp[node][choice] = max possible for subtree
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<pair<ll,ll>> val(n);
        vector<vector<int>> adj(n);
        vector<vector<ll>> dp(n, vector<ll>(2));
        
        for(auto& [l,r] : val) cin >> l >> r;
        
        for(int i = 0; i < n-1; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        function<void(int,int)> dfs = [&](int u, int p) {
            for(int v : adj[u]) if(v != p) {
                dfs(v, u);
                dp[u][0] += max(abs(val[u].first - val[v].first) + dp[v][0],
                               abs(val[u].first - val[v].second) + dp[v][1]);
                dp[u][1] += max(abs(val[u].second - val[v].first) + dp[v][0],
                               abs(val[u].second - val[v].second) + dp[v][1]);
            }
        };
        
        dfs(0, -1);
        cout << max(dp[0][0], dp[0][1]) << '\n';
    }
    return 0;
}
