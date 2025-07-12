/*
 * Fenwick Tree (Binary Indexed Tree)
 * Time: O(log n) query/update | Space: O(n)
 * Supports point updates and prefix sum queries
 */

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll

class FenwickTree {
private:
    vector<int> tree;
    int n;
    
    // Least significant bit - key to tree navigation
    int lsb(int i) { return i & (-i); }
    
public:
    FenwickTree(int size) : n(size), tree(size + 1, 0) {}
    
    FenwickTree(const vector<int>& arr) : n(arr.size()), tree(n + 1, 0) {
        for (int i = 0; i < n; i++) {
            update(i + 1, arr[i]);
        }
    }
    
    // Add delta to position idx (1-indexed)
    void update(int idx, int delta) {
        for (; idx <= n; idx += lsb(idx)) {
            tree[idx] += delta;
        }
    }
    
    // Get prefix sum [1..idx]
    int prefix_sum(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= lsb(idx)) {
            sum += tree[idx];
        }
        return sum;
    }
    
    // Get range sum [l..r] (1-indexed)
    int range_sum(int l, int r) {
        return prefix_sum(r) - prefix_sum(l - 1);
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    FenwickTree ft(arr);
    
    // Example queries
    cout << ft.prefix_sum(7) << "\n";
    cout << ft.range_sum(1, 5) << "\n";
    cout << ft.range_sum(1, 12) << "\n";
    
    // Example updates
    ft.update(6, 8);
    ft.update(9, -2);
    cout << ft.range_sum(1, 12) << "\n";
    
    return 0;
}

/*
Sample Input:
12
2 1 1 3 2 3 4 5 6 7 8 9
*/
