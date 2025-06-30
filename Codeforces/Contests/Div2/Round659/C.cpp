/*
CF 659C - String Transformation 1
https://codeforces.com/contest/1384/problem/C

Transform string with adjacent swaps
n ≤ 1e5

Key: Process characters in order
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) {
        int n;
        string a, b;
        cin >> n >> a >> b;
        
        bool possible = true;
        for(int i = 0; i < n; i++) {
            if(a[i] > b[i]) possible = false;
        }
        
        if(!possible) {
            cout << "-1\n";
            continue;
        }
        
        vector<vector<int>> graph(20);
        for(int i = 0; i < n; i++) {
            if(a[i] != b[i]) {
                graph[a[i]-'a'].push_back(b[i]-'a');
            }
        }
        
        int ans = 0;
        vector<bool> used(20);
        for(int i = 0; i < 20; i++) {
            if(used[i]) continue;
            if(graph[i].empty()) continue;
            
            ans++;
            int curr = i;
            while(!graph[curr].empty()) {
                used[curr] = true;
                curr = *min_element(graph[curr].begin(), graph[curr].end());
            }
        }
        
        cout << ans << '\n';
    }
    return 0;
}
