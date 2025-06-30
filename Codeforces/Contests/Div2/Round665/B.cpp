/*
CF Round 665 (Div. 2) - Problem B
https://codeforces.com/contest/1401/problem/B

Max sum of pairwise products after permutation where:
- Two arrays of length n containing only {0,1,2}
- Can rearrange elements in each array
- Sum = Σ a[i]*b[i]

Constraints:
- 1 ≤ t ≤ 100
- a[i], b[i] ∈ {0,1,2}
- Sum of array elements matches input

Solution:
1. Match 2s with 1s first (contribution of +2)
2. Minimize negative contributions from remaining 2s
3. Track counts instead of actual permutations

Complexity: O(1) per test case
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        ll a0, a1, a2;  // counts of 0s, 1s, 2s in first array
        ll b0, b1, b2;  // counts in second array
        cin >> a0 >> a1 >> a2;
        cin >> b0 >> b1 >> b2;
        
        ll ans = 0;
        // First maximize positive contributions (2*1)
        ll match = min(a2, b1);
        ans += 2 * match;
        a2 -= match;
        b1 -= match;
        
        // Then minimize negative contributions (2*0)
        ll remaining_twos = b2;
        ll available = a0 + a2;  // numbers that can match with 2s
        
        if(remaining_twos > available) {
            ans -= 2 * (remaining_twos - available);
        }
        
        cout << ans << '\n';
    }
    return 0;
}
