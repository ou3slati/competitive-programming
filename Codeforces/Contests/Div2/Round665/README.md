# Codeforces Round #665 (Div. 2)
[https://codeforces.com/contest/1401](https://codeforces.com/contest/1401)

## Problems

### A. Distance and Axis [900]
- Find min moves to make |pos - point| = K
- Solution: 
  - Case n < k: Need k-n moves
  - Case n ≥ k: Need 1 move if n-k odd, 0 if even
- Complexity: O(1)

### B. Ternary Sequence [1100]
- Max sum of pairwise products after permutation
- Solution:
  - Match 2s with 1s first (+2 each)
  - Minimize negative contributions from remaining 2s
  - Track counts instead of permutations
- Complexity: O(1)

### C. Mere Array [1300]
- Sort array by swapping elements divisible by minimum
- Solution:
  - Elements not divisible by min are fixed points
  - Check if misplaced elements are divisible by min
  - Sort copy to determine final positions
- Complexity: O(N log N)
