/*
Problem: Mere Array
Link: https://codeforces.com/contest/1401/problem/C
Contest: Codeforces Round #665 (Div. 2)
Approach: Math + Sorting
         1. Find minimum element in array
         2. Elements not divisible by minimum can't be swapped
         3. Check if these elements are already in sorted position
         Key insight: Elements divisible by minimum can be swapped freely
Time: O(N log N)
Space: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) begin(x), end(x)

class ArraySolver {
private:
    int N;
    vector<ll> original, sorted;
    ll minimum;
    
    // Find minimum element in array
    void findMinimum() {
        minimum = *min_element(all(original));
    }
    
    // Check if array can be sorted
    bool canSort() {
        // Create sorted copy
        sorted = original;
        sort(all(sorted));
        
        // Check each position
        for(int i = 0; i < N; i++) {
            // If element differs from sorted position
            if(original[i] != sorted[i]) {
                // If not divisible by minimum, we can't swap it
                if(original[i] % minimum != 0) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
public:
    void process() {
        // Read input
        cin >> N;
        original.resize(N);
        for(int i = 0; i < N; i++) {
            cin >> original[i];
        }
        
        // Solve and output
        findMinimum();
        cout << (canSort() ? "YES" : "NO") << "\n";
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int TC;
    cin >> TC;
    while(TC--) {
        ArraySolver solver;
        solver.process();
    }
    
    return 0;
}
