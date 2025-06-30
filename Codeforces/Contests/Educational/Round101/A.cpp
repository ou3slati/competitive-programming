/*
Problem: Regular Bracket Sequence
Link: https://codeforces.com/contest/1469/problem/A
Contest: Educational Codeforces Round 101 (Rated for Div. 2)
Approach: String analysis - Check basic conditions for a string to be potentially regular:
         1. Length must be even (to have equal number of opening and closing brackets)
         2. First character can't be closing bracket
         3. Last character can't be opening bracket
Time: O(1) - constant time checks
Space: O(1) - only storing the input string
*/

#include <bits/stdc++.h>
using namespace std;

// Fast I/O
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr)

// Main solver class
class BracketChecker {
private:
    string s;
    
    bool isValid() {
        // Check basic conditions
        if (s.length() % 2 == 1) return false;  // Must be even length
        if (s[0] == ')') return false;          // Can't start with closing
        if (s.back() == '(') return false;      // Can't end with opening
        return true;
    }
    
public:
    BracketChecker(const string& sequence) : s(sequence) {}
    
    string solve() {
        return isValid() ? "Yes" : "No";
    }
};

int main() {
    FAST_IO;
    
    int t;
    cin >> t;
    
    while(t--) {
        string s;
        cin >> s;
        
        BracketChecker checker(s);
        cout << checker.solve() << "\n";
    }
    
    return 0;
}
