/*
Problem: Phoenix and Puzzle
Link: https://codeforces.com/contest/1515/problem/B
Contest: Codeforces Global Round 14
Approach: Number Theory
         1. Check if n/2 is a perfect square (when n is even)
         2. Check if n/4 is a perfect square (when n is divisible by 4)
         3. If either condition is true, the number is valid
Time: O(1) for each test case
Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class PuzzleSolver {
private:
    // Check if a number is a perfect square
    bool isPerfectSquare(ll x) {
        if(x < 0) return false;
        ll sqrt_x = sqrt(x);
        return sqrt_x * sqrt_x == x;
    }
    
    // Check if number satisfies puzzle conditions
    bool canSolve(ll n) {
        // Check n/2 if n is even
        if(n % 2 == 0 && isPerfectSquare(n/2)) {
            return true;
        }
        
        // Check n/4 if n is divisible by 4
        if(n % 4 == 0 && isPerfectSquare(n/4)) {
            return true;
        }
        
        return false;
    }
    
public:
    void solve() {
        ll n;
        cin >> n;
        cout << (canSolve(n) ? "YES" : "NO") << "\n";
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        PuzzleSolver solver;
        solver.solve();
    }
    
    return 0;
}
