/*
CF Round 665 (Div. 2) - Problem C
https://codeforces.com/contest/1401/problem/C

Check if array can be sorted by swapping elements where:
- Can only swap if both elements divisible by min element
- Need to determine if sorting is possible

Constraints:
- 1 ≤ t ≤ 10^4
- 1 ≤ n ≤ 10^5
- 1 ≤ a[i] ≤ 10^9

Solution:
1. Find minimum element m
2. Create sorted copy
3. For each position i:
   - If a[i] ≠ sorted[i] then a[i] must be divisible by m
   - Otherwise array unsortable
4. Proof: Elements not divisible by m form fixed points

Complexity: O(N log N) for sorting
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), sorted(n);
        
        // Read and find minimum
        int min_elem = INT_MAX;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            sorted[i] = a[i];
            min_elem = min(min_elem, a[i]);
        }
        
        // Sort copy for comparison
        sort(sorted.begin(), sorted.end());
        
        // Check if misplaced elements are divisible by minimum
        bool possible = true;
        for(int i = 0; i < n; i++) {
            if(a[i] != sorted[i] && a[i] % min_elem != 0) {
                possible = false;
                break;
            }
        }
        
        cout << (possible ? "YES" : "NO") << '\n';
    }
    return 0;
}
