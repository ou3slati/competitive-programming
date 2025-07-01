# Codeforces Round #672 (Div. 2)
[Contest Link](https://codeforces.com/contest/1420)

## Problems

### [A. Cubes Sorting](https://codeforces.com/contest/1420/problem/A) [900]
- Check if array can be sorted with bubble sort in less than n(n-1)/2 swaps
- Key insights:
  1. Only strictly decreasing sequence needs max swaps
  2. Any non-decreasing adjacent pair allows sorting
  3. Check if array is strictly decreasing
- O(N) solution

### [B. Rock and Lever](https://codeforces.com/contest/1420/problem/B) [1200]
- Count pairs where (a[i] & a[j]) >= (a[i] ⊕ a[j])
- Key insights:
  1. Condition equivalent to MSB position being same
  2. Group numbers by highest set bit
  3. Use combinations within each group
- O(N) solution

### [C1. Pokémon Army (easy version)](https://codeforces.com/contest/1420/problem/C1) [1300]
- Find maximum value of alternating subsequence
- Key insights:
  1. Optimal solution alternates between adding and subtracting
  2. Use DP with state (index, isAdding)
  3. For each position, can continue or switch state
- O(N) solution

### [C2. Pokémon Army (hard version)](https://codeforces.com/contest/1420/problem/C2) [2100]
- Same as C1 but with position swaps
- Key insights:
  1. Use segment tree to handle updates
  2. Each node stores four states (pp, pm, mp, mm)
  3. Carefully combine states during tree operations
- O(N + Q log N) solution

### [D. Rescue Nibel!](https://codeforces.com/contest/1420/problem/D) [1800]
- Count valid combinations of events
- Key insights:
  1. Sort events by time
  2. Track active intervals
  3. Use combinations for counting
- O(N log N) solution

### [E. Battle Lemmings](https://codeforces.com/contest/1420/problem/E) [2500]
- Optimize lemming grouping
- Key insights:
  1. Dynamic programming with state compression
  2. Consider group sizes and positions
  3. Handle zero positions carefully
- O(N³) solution
