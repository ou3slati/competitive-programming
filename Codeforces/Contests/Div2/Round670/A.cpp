/*
CF 670A - Subset Mex
https://codeforces.com/contest/1406/problem/A

Find max MEX of two subsets
n ≤ 100

Key: Count frequencies, build greedily
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> cnt(101);
        
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            cnt[x]++;
        }
        
        int mex1 = 0, mex2 = 0;
        for(int i = 0; i <= 100; i++) {
            if(cnt[i] == 0) {
                mex1 = i;
                break;
            }
            cnt[i]--;
        }
        
        for(int i = 0; i <= 100; i++) {
            if(cnt[i] == 0) {
                mex2 = i;
                break;
            }
        }
        
        cout << mex1 + mex2 << '\n';
    }
    return 0;
}
