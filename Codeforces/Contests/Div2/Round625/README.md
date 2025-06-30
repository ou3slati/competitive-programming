# Codeforces Round #625 (Div. 2)
[https://codeforces.com/contest/1321](https://codeforces.com/contest/1321)

## Problems

### A. Contest for Robots [900]
- Compare two robot arrays, need wins > losses
- Key: Only positions where robot1 wins matter
- O(N)

### B. Journey Planning [1400]
- Max sum from subsequence where b[i] = i + a[i]
- Key: Elements with same b[i]-i must be in different positions
- O(N)

### C. Remove Adjacent [1500]
- Remove char if greater than both neighbors
- Key: Always optimal to remove largest possible first
- O(N²)
