/*
Problem: Red and Blue
Link: https://codeforces.com/contest/1469/problem/B
Contest: Educational Codeforces Round 101 (Rated for Div. 2)
Approach: Dynamic Programming with Prefix Sums
         1. Calculate prefix sums for both arrays
         2. Use DP to find maximum possible sum at each position
         3. State (i,j) represents using first i red and j blue elements
         4. Transition by either taking next red or next blue element
Time: O(N*M) where N and M are lengths of arrays
Space: O(N*M) for memoization table
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define sz(x) (int)(x).size()

const ll INF = 1e18;
const int MX = 105;

class SequenceSolver {
private:
    int N, M;
    vector<ll> red, blue;
    vector<vector<ll>> memo;
    
    // Calculate prefix sums
    vector<ll> getPrefixSums(const vector<ll>& arr) {
        vector<ll> pref = arr;
        FOR(i,1,sz(arr)) pref[i] += pref[i-1];
        return pref;
    }
    
    // DP function to find maximum sum
    ll solve(int i, int j) {
        // Base case: used all elements
        if(i == N && j == M) return 0;
        
        // Return memoized result
        if(memo[i][j] != -1) return memo[i][j];
        
        // Get previous sums
        ll redSum = (i > 0) ? red[i-1] : 0;
        ll blueSum = (j > 0) ? blue[j-1] : 0;
        
        // Try all possible transitions
        ll ans = 0;
        if(i < N) {
            ans = max(ans, max(solve(i+1,j), red[i] + blueSum));
        }
        if(j < M) {
            ans = max(ans, max(solve(i,j+1), redSum + blue[j]));
        }
        
        return memo[i][j] = ans;
    }
    
public:
    ll solve(vector<ll>& r, vector<ll>& b) {
        // Initialize
        N = sz(r);
        M = sz(b);
        red = getPrefixSums(r);
        blue = getPrefixSums(b);
        memo.assign(N+1, vector<ll>(M+1, -1));
        
        // Solve using DP
        return solve(0, 0);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n;
        vector<ll> red(n);
        FOR(i,0,n) cin >> red[i];
        
        cin >> m;
        vector<ll> blue(m);
        FOR(i,0,m) cin >> blue[i];
        
        SequenceSolver solver;
        cout << solver.solve(red, blue) << "\n";
    }
    
    return 0;
}
