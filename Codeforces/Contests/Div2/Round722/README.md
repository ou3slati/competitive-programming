# Codeforces Round #722 (Div. 2)

Contest Link: https://codeforces.com/contest/1529

## Problems

### A. Eshag Loves Big Arrays
- Rating: 800
- Tags: Tree DP, DFS
- Approach: Used tree DP to compute the maximum possible sum by trying both possible values for each node
- Time Complexity: O(N)
- Space Complexity: O(N)

### B. Sifid and Strange Subsequences
- Rating: 1100
- Tags: Number Theory, Dynamic Programming, Sieve
- Approach: Used sieve for prime factorization and dynamic programming to compute cumulative sum of divisor counts
- Time Complexity: O(N log log N) for sieve + O(N log N) for divisor calculation
- Space Complexity: O(N)

### C. Parsa's Humongous Tree
- Rating: 1600
- Tags: LCA, Binary Lifting, Tree Algorithms
- Approach: Used LCA and binary lifting to efficiently traverse two trees and find optimal paths
- Time Complexity: O(N log N)
- Space Complexity: O(N log N)

## Key Concepts Used
1. Tree Dynamic Programming
2. Number Theory (Sieve, Prime Factorization)
3. Lowest Common Ancestor (LCA)
4. Binary Lifting
5. Graph Traversal (DFS)

## Implementation Notes
- All solutions use fast I/O optimization
- Heavy use of preprocessing for efficiency
- Modular arithmetic for large numbers
- Efficient data structures for tree representation

## Learning Points
1. Efficient tree traversal techniques
2. Combining multiple tree algorithms
3. Optimization using preprocessing
4. Smart use of binary lifting for ancestor queries
