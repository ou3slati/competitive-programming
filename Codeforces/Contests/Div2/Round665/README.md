# Codeforces Round #665 (Div. 2)
[https://codeforces.com/contest/1401](https://codeforces.com/contest/1401)

## Problems

### A. Distance and Axis [900]
- |pos - point| = K, minimize moves
- Key: When N ≥ K, parity of N-K determines solvability
- O(1)

### B. Ternary Sequence [1100]
- Max Σ(a[i]*b[i]) after permutation, elements in {0,1,2}
- Key: 2*1 gives +2, 2*0 gives 0, others irrelevant
- O(1)

### C. Mere Array [1300]
- Sort by swapping elements divisible by min
- Key: Non-divisible elements are fixed points
- O(N log N)
