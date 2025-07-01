# Codeforces Round #671 (Div. 2)
[Contest Link](https://codeforces.com/contest/1419)

## Problems

### [A. Digit Game](https://codeforces.com/contest/1419/problem/A) [900]
- Winner in digit removal game
- Key: Analyze which player controls which positions
- Even positions controlled by Raze, odd by Breach
- Check if winning digit parity exists for each player
- O(N) solution

### [B. Stairs](https://codeforces.com/contest/1419/problem/B) [1200]
- Count maximum complete stairs possible with x blocks
- Key: Each stair uses 2^k-1 blocks in total
- Pattern: 1, 3, 7, 15, 31, ...
- O(log N) solution

### [C. Killjoy](https://codeforces.com/contest/1419/problem/C) [1500]
- Find minimum operations to make array equal or equal to x
- Key insights:
  1. If all equal to x, answer is 0
  2. If x exists or sum of differences is 0, answer is 1
  3. Otherwise, answer is 2
- O(N) solution

### [D1. Sage's Birthday (easy)](https://codeforces.com/contest/1419/problem/D1) [1000]
- Rearrange array to maximize local minima
- Key: Place larger elements alternately
- O(N log N) solution

### [D2. Sage's Birthday (hard)](https://codeforces.com/contest/1419/problem/D2) [1500]
- Same as D1 but must be strictly less than neighbors
- Key: Binary search on number of peaks
- O(N log N) solution

### [E. Decryption](https://codeforces.com/contest/1419/problem/E) [2100]
- Find special permutation of divisors
- Key: Use prime factorization
- Create cycle using prime power relationships
- O(√N) solution

### [F. Rain of Fire](https://codeforces.com/contest/1419/problem/F) [2800]
- Complex geometry and timing problem
- Key: Use divide and conquer with efficient data structures
- O(N² log N) solution
