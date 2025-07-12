/*
 * Fenwick Tree with Range Updates and Range Queries
 * Time: O(log n) per operation | Space: O(n)
 * Supports range updates and range sum queries using difference arrays
 */

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll

class FenwickTreeRangeUpdate {
private:
    vector<int> tree1, tree2;
    int n;
    
    int lsb(int i) { return i & (-i); }
    
    void add(vector<int>& tree, int pos, int val) {
        for (; pos <= n; pos += lsb(pos)) {
            tree[pos] += val;
        }
    }
    
    int query(vector<int>& tree, int pos) {
        int sum = 0;
        for (; pos > 0; pos -= lsb(pos)) {
            sum += tree[pos];
        }
        return sum;
    }
    
public:
    FenwickTreeRangeUpdate(int size) : n(size), tree1(size + 1, 0), tree2(size + 1, 0) {}
    
    // Add val to range [l, r] (1-indexed)
    void range_update(int l, int r, int val) {
        add(tree1, l, val);
        add(tree1, r + 1, -val);
        add(tree2, l, val * (l - 1));
        add(tree2, r + 1, -val * r);
    }
    
    // Get prefix sum [1..pos]
    int prefix_sum(int pos) {
        return pos * query(tree1, pos) - query(tree2, pos);
    }
    
    // Get range sum [l..r]
    int range_sum(int l, int r) {
        return prefix_sum(r) - prefix_sum(l - 1);
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    FenwickTreeRangeUpdate ft(n);
    
    // Example operations
    ft.range_update(4, 9, 2);  // Add 2 to range [4,9]
    ft.range_update(2, 6, 5);  // Add 5 to range [2,6]
    
    cout << ft.range_sum(2, 8) << "\n";
    
    ft.range_update(1, 1, 3);  // Add 3 to position 1
    cout << ft.range_sum(1, 6) << "\n";
    
    return 0;
}
