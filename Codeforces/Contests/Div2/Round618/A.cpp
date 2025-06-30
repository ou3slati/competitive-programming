/*
Problem: Non-zero
Link: https://codeforces.com/contest/1300/problem/A
Contest: Codeforces Round #618 (Div. 2)
Approach: Greedy
         1. First make all zeros into ones (count these operations)
         2. If final sum is zero, need one more operation
Time: O(N)
Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class NonZeroSolver {
private:
    int N;
    vector<int> numbers;
    
    int solve() {
        int operations = 0;
        int sum = 0;
        
        // First pass: make all zeros into ones
        for(int x : numbers) {
            if(x == 0) {
                operations++;
                x = 1;  // Convert to 1
            }
            sum += x;
        }
        
        // If sum is still zero, need one more operation
        if(sum == 0) {
            operations++;
        }
        
        return operations;
    }
    
public:
    void process() {
        cin >> N;
        numbers.resize(N);
        for(int i = 0; i < N; i++) {
            cin >> numbers[i];
        }
        cout << solve() << "\n";
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T--) {
        NonZeroSolver solver;
        solver.process();
    }
    
    return 0;
}
