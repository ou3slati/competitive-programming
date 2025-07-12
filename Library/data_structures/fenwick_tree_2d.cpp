/*
 * 2D Fenwick Tree (Binary Indexed Tree)
 * Time: O(log n * log m) per operation | Space: O(n * m)
 * Supports 2D point updates and 2D range sum queries
 */

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll

class FenwickTree2D {
private:
    vector<vector<int>> tree;
    int n, m;
    
    int lsb(int i) { return i & (-i); }
    
public:
    FenwickTree2D(int rows, int cols) : n(rows), m(cols), tree(rows + 1, vector<int>(cols + 1, 0)) {}
    
    FenwickTree2D(const vector<vector<int>>& matrix) : n(matrix.size()), m(matrix[0].size()), 
                  tree(n + 1, vector<int>(m + 1, 0)) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                update(i + 1, j + 1, matrix[i][j]);
            }
        }
    }
    
    // Add delta to position (row, col) - 1-indexed
    void update(int row, int col, int delta) {
        for (int i = row; i <= n; i += lsb(i)) {
            for (int j = col; j <= m; j += lsb(j)) {
                tree[i][j] += delta;
            }
        }
    }
    
    // Get sum of rectangle from (1,1) to (row, col)
    int prefix_sum(int row, int col) {
        int sum = 0;
        for (int i = row; i > 0; i -= lsb(i)) {
            for (int j = col; j > 0; j -= lsb(j)) {
                sum += tree[i][j];
            }
        }
        return sum;
    }
    
    // Get sum of rectangle from (r1,c1) to (r2,c2) - 1-indexed
    int range_sum(int r1, int c1, int r2, int c2) {
        return prefix_sum(r2, c2) - prefix_sum(r1 - 1, c2) 
               - prefix_sum(r2, c1 - 1) + prefix_sum(r1 - 1, c1 - 1);
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    
    FenwickTree2D ft(matrix);
    
    // Query rectangle sum
    cout << ft.range_sum(1, 1, 5, 6) << "\n";
    
    // Update position (2,2) by adding 7
    ft.update(2, 2, 7);
    cout << ft.range_sum(1, 1, 5, 6) << "\n";
    
    return 0;
}

/*
Sample Input:
8
1 1 3 2 1 1 3 2
2 3 3 3 2 3 3 3
1 1 1 1 1 1 1 1
1 9 3 1 1 9 3 1
1 1 3 2 1 1 3 2
2 3 3 3 2 3 3 3
1 1 1 1 1 1 1 1
1 9 3 1 1 9 3 1
*/
