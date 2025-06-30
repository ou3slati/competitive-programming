/*
Problem: Distance and Axis
Link: https://codeforces.com/contest/1401/problem/A
Contest: Codeforces Round #665 (Div. 2)
Approach: Math - Case Analysis
         1. If N < K, we need to move N to K
         2. If N ≥ K, we need to make N-K even
         Key insight: When N ≥ K, we can always achieve distance K by moving point
         at most 1 unit if N-K is odd
Time: O(1)
Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class AxisSolver {
private:
    ll N, K;
    
    // Calculate minimum moves needed
    ll solve() {
        // If N < K, we must move N to K
        if(N < K) {
            return K - N;
        }
        
        // If N ≥ K, we need N-K to be even
        return (N - K) % 2;
    }
    
public:
    void process() {
        cin >> N >> K;
        cout << solve() << "\n";
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int TC;
    cin >> TC;
    while(TC--) {
        AxisSolver solver;
        solver.process();
    }
    
    return 0;
}
