# Codeforces Global Round 14
[https://codeforces.com/contest/1515](https://codeforces.com/contest/1515)

## Problems

### A. Phoenix and Gold [800]
- Rearrange weights to avoid sum X
- Key: Sort, skip first weight that makes prefix sum = X
- O(N log N)

### B. Phoenix and Puzzle [1000]
- Check if N can be split into equal triangles
- Key: N/2 or N/4 must be perfect square
- O(1)

### C. Phoenix and Towers [1400]
- Distribute N blocks to M towers, max diff ≤ X
- Key: Always add to shortest tower, difference stays ≤ X
- O(N log M)
