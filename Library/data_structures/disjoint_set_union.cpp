/*
 * Disjoint Set Union (Union-Find) with Path Compression + Union by Rank
 * Time: O(α(n)) amortized per operation | Space: O(n)
 * α(n) is inverse Ackermann function - effectively constant for practical inputs
 */

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll

class DSU {
private:
    vector<int> parent, rank, set_size;
    int num_sets;
    
public:
    DSU(int n) : parent(n), rank(n, 0), set_size(n, 1), num_sets(n) {
        iota(parent.begin(), parent.end(), 0);
    }
    
    // Find with path compression
    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    
    // Union by rank with size tracking
    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;
        
        num_sets--;
        if (rank[px] < rank[py]) swap(px, py);
        
        parent[py] = px;
        set_size[px] += set_size[py];
        if (rank[px] == rank[py]) rank[px]++;
        
        return true;
    }
    
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
    
    int size(int x) {
        return set_size[find(x)];
    }
    
    int count_sets() {
        return num_sets;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    DSU dsu(n);
    cout << dsu.count_sets() << "\n";
    
    dsu.unite(0, 1);
    dsu.unite(1, 2);
    
    cout << dsu.count_sets() << "\n";
    cout << dsu.size(0) << "\n";
    
    return 0;
}
