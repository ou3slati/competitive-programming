/*
CF 638B - Phoenix and Beauty
https://codeforces.com/contest/1348/problem/B

Make array beautiful with min operations
n,k ≤ 100

Key: Use cyclic pattern of k numbers
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        set<int> nums;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            nums.insert(x);
        }
        
        if(nums.size() > k) {
            cout << "-1\n";
            continue;
        }
        
        cout << n*k << '\n';
        for(int i = 0; i < n; i++) {
            for(int x : nums) cout << x << ' ';
            for(int j = nums.size(); j < k; j++) {
                cout << "1 ";
            }
        }
        cout << '\n';
    }
    return 0;
}
