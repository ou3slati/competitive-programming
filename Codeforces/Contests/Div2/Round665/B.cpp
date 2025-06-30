/*
Problem: Ternary Sequence
Link: https://codeforces.com/contest/1401/problem/B
Contest: Codeforces Round #665 (Div. 2)
Approach: Greedy
         1. First maximize positive contributions (2s matching with 1s)
         2. Then minimize negative contributions (2s matching with 0s)
         Key insight: Order of matching matters - always try to match 2s with 1s first
Time: O(1)
Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class SequenceSolver {
private:
    // First sequence counts
    ll zeros1, ones1, twos1;
    // Second sequence counts
    ll zeros2, ones2, twos2;
    
    ll solve() {
        ll result = 0;
        
        // First maximize positive contributions (2 * 1 = 2)
        ll matching_two_one = min(twos1, ones2);
        result += 2 * matching_two_one;
        twos1 -= matching_two_one;
        ones2 -= matching_two_one;
        
        // Then minimize negative contributions (2 * 0 = 0)
        // We want to avoid matching remaining 2s with 0s
        ll remaining_twos2 = twos2;
        ll available_buffer = zeros1 + twos1;  // Numbers that can match with 2s
        
        // If we can't avoid some 2-0 matches, they contribute -2 each
        if(remaining_twos2 > available_buffer) {
            result -= 2 * (remaining_twos2 - available_buffer);
        }
        
        return result;
    }
    
public:
    void process() {
        // Read input
        cin >> zeros1 >> ones1 >> twos1;
        cin >> zeros2 >> ones2 >> twos2;
        
        // Output result
        cout << solve() << "\n";
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int TC;
    cin >> TC;
    while(TC--) {
        SequenceSolver solver;
        solver.process();
    }
    
    return 0;
}
