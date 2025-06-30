/*
Problem: Assigning to Classes
Link: https://codeforces.com/contest/1300/problem/B
Contest: Codeforces Round #618 (Div. 2)
Approach: Sorting + Median
         1. Sort all students by skill
         2. Split into two equal-sized groups
         3. Difference of medians gives minimum unfairness
Time: O(N log N)
Space: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

class ClassAssigner {
private:
    int N;  // Number of students per class
    vector<int> skills;
    
    int solve() {
        // Sort students by skill
        sort(skills.begin(), skills.end());
        
        // For N=1, difference of the two students
        if(N == 1) {
            return abs(skills[1] - skills[0]);
        }
        
        // For N>1, difference of medians
        // Middle elements after sorting give minimum unfairness
        return abs(skills[N] - skills[N-1]);
    }
    
public:
    void process() {
        cin >> N;
        skills.resize(2*N);
        for(int i = 0; i < 2*N; i++) {
            cin >> skills[i];
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
        ClassAssigner solver;
        solver.process();
    }
    
    return 0;
}
