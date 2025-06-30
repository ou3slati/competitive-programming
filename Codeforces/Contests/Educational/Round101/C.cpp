/*
Problem: Building a Fence
Link: https://codeforces.com/contest/1469/problem/C
Contest: Educational Codeforces Round 101 (Rated for Div. 2)
Approach: Greedy + Simulation
         1. For each position, try to minimize height differences
         2. If difference between adjacent positions is too large, adjust heights
         3. Check if final configuration is valid:
            - Adjacent heights differ by at most K-1
            - No height exceeds original height + K-1
Time: O(N*X) where X is iteration count for adjustments
Space: O(N) for storing heights
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define sz(x) (int)(x).size()

class FenceSolver {
private:
    int N, K;
    vector<ll> original, heights;
    
    // Adjust heights to minimize differences
    void adjustHeights() {
        const int ITERATIONS = 10;  // Number of adjustment iterations
        
        FOR(iter,0,ITERATIONS) {
            FOR(i,1,N) {
                // If difference is too large, adjust heights
                if(heights[i] - heights[i-1] >= K) {
                    if(i != 1) {
                        heights[i-1] += heights[i] - heights[i-1] - (K-1);
                    }
                }
                else if(heights[i-1] - heights[i] >= K) {
                    if(i != N-1) {
                        heights[i] += heights[i-1] - heights[i] - (K-1);
                    }
                }
            }
        }
    }
    
    // Check if configuration is valid
    bool isValid() {
        FOR(i,0,N) {
            // Check difference with previous height
            if(i > 0 && abs(heights[i] - heights[i-1]) > K-1) {
                return false;
            }
            
            // Check if height exceeds maximum allowed
            if(heights[i] > original[i] + K-1) {
                return false;
            }
        }
        return true;
    }
    
public:
    string solve(int n, int k, vector<ll>& h) {
        // Initialize variables
        N = n;
        K = k;
        original = heights = h;
        
        // Try to adjust heights
        adjustHeights();
        
        // Check if solution is valid
        return isValid() ? "YES" : "NO";
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        
        vector<ll> h(n);
        FOR(i,0,n) cin >> h[i];
        
        FenceSolver solver;
        cout << solver.solve(n, k, h) << "\n";
    }
    
    return 0;
}
