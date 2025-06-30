# Codeforces Round #722 (Div. 2)
[https://codeforces.com/contest/1529](https://codeforces.com/contest/1529)

## Problems

### A. Eshag Loves Big Arrays [800]
- Min operations to make mean = minimum
- Key: Remove all elements > minimum
- O(N)

### B. Sifid and Strange Subsequences [1100]
- Max subsequence where |any two elements| ≥ min(subsequence)
- Key: Take all negatives + at most one smallest positive
- O(N log N)

### C. Parsa's Humongous Tree [1600]
- Binary tree, two choices per node, maximize sum of |adjacent|
- Key: DP on tree, track best for each choice
- O(N)
