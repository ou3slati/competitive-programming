/*
CF 640A - Sum of Round Numbers
https://codeforces.com/contest/1352/problem/A

Split into round numbers
n ≤ 1e4

Key: Use decimal places
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> ans;
        
        int pow = 1;
        while(n) {
            if(n % 10) ans.push_back((n % 10) * pow);
            n /= 10;
            pow *= 10;
        }
        
        cout << ans.size() << '\n';
        for(int x : ans) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}
