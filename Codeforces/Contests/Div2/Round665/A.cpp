/*
CF Round 665 (Div. 2) - Problem A
https://codeforces.com/contest/1401/problem/A

Find min moves to make |pos - point| = K where:
- Can move point on number line
- Can place axis point anywhere
- Need |distance| = K

Constraints:
- 1 ≤ t ≤ 10^4
- 0 ≤ n,k ≤ 10^9

Solution:
Case n < k: Need k-n moves to reach minimum possible
Case n ≥ k: Need 1 move if n-k odd (can't satisfy), 0 if even

Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        
        if(n < k) cout << k-n << '\n';
        else cout << (n-k) % 2 << '\n';
    }
    return 0;
}
