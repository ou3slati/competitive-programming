/*
CF 671C - Killjoy
https://codeforces.com/contest/1419/problem/C

Min operations to make array equal or x
n ≤ 1000, x ≤ 1e9

Key insights:
1. If all numbers equal x, answer is 0
2. If x exists in array or sum diff is 0, answer is 1
3. Otherwise, answer is 2 (can always solve in 2 moves)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        
        bool all_equal = true;
        bool has_x = false;
        long long sum_diff = 0;
        
        for(int i = 0; i < n; i++) {
            int val;
            cin >> val;
            if(val != x) all_equal = false;
            if(val == x) has_x = true;
            sum_diff += x - val;
        }
        
        if(all_equal) cout << "0\n";
        else if(has_x || sum_diff == 0) cout << "1\n";
        else cout << "2\n";
    }
    return 0;
}
