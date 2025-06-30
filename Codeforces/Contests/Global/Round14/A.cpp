/*
Problem: Phoenix and Gold
Link: https://codeforces.com/contest/1515/problem/A
Contest: Codeforces Global Round 14
Approach: Constructive Algorithm
         1. Sort array to make it easier to handle
         2. Try to build solution avoiding sum X
         3. Keep track of running sum and rearrange if needed
Time: O(N log N) for sorting
Space: O(N) for storing array
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

class WeightSolver {
private:
    int N, X;
    vector<int> weights;
    
    // Try to construct valid sequence
    pair<bool, vector<int>> constructSequence() {
        // Sort weights for easier handling
        sort(all(weights));
        
        int runningSum = 0;
        vector<int> result;
        int postponedWeight = -1;
        
        // Process each weight
        FOR(i,0,N) {
            // If current sum + weight equals X, postpone this weight
            if(runningSum + weights[i] == X) {
                postponedWeight = weights[i];
            } else {
                runningSum += weights[i];
                result.push_back(weights[i]);
            }
        }
        
        // Check if total sum equals X
        ll totalSum = accumulate(all(weights), 0LL);
        if(totalSum == X) {
            return {false, vector<int>()};
        }
        
        // Add postponed weight if exists
        if(postponedWeight != -1) {
            result.push_back(postponedWeight);
        }
        
        return {true, result};
    }
    
public:
    void solve() {
        cin >> N >> X;
        weights.resize(N);
        FOR(i,0,N) cin >> weights[i];
        
        auto [possible, sequence] = constructSequence();
        
        if(!possible) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for(int w : sequence) {
                cout << w << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        WeightSolver solver;
        solver.solve();
    }
    
    return 0;
}
