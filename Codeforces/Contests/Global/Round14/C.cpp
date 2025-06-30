/*
Problem: Phoenix and Towers
Link: https://codeforces.com/contest/1515/problem/C
Contest: Codeforces Global Round 14
Approach: Greedy with Set
         1. Use set to maintain tower heights
         2. Always add block to shortest tower
         3. Keep track of tower assignments
         4. Prove difference never exceeds X
Time: O(N log M) where N is number of blocks and M is number of towers
Space: O(M) for set and O(N) for answer array
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;  // {height, tower_index}
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)

class TowerBuilder {
private:
    int N, M;
    ll X;
    vector<ll> blocks;
    
    // Assign blocks to towers greedily
    vector<int> assignBlocks() {
        // Initialize towers with height 0
        set<pli> towers;  // {height, index}
        FOR(i,1,M+1) {
            towers.insert({0, i});
        }
        
        // Assign each block to shortest tower
        vector<int> assignments(N);
        FOR(i,0,N) {
            // Get shortest tower
            auto it = towers.begin();
            pli tower = *it;
            towers.erase(it);
            
            // Assign block to this tower
            assignments[i] = tower.second;
            
            // Update tower height and reinsert
            tower.first += blocks[i];
            towers.insert(tower);
        }
        
        return assignments;
    }
    
public:
    void solve() {
        // Read input
        cin >> N >> M >> X;
        blocks.resize(N);
        FOR(i,0,N) cin >> blocks[i];
        
        // Get solution
        vector<int> result = assignBlocks();
        
        // Output result
        cout << "YES\n";
        for(int tower : result) {
            cout << tower << " ";
        }
        cout << "\n";
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        TowerBuilder solver;
        solver.solve();
    }
    
    return 0;
}
