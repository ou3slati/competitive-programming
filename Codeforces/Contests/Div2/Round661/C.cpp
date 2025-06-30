/*
CF 661C - Boats Competition
https://codeforces.com/contest/1399/problem/C

Max pairs with same sum
n ≤ 50

Key: Try all possible sums
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
        vector<int> w(n);
        for(int& x : w) cin >> x;
        
        int ans = 0;
        for(int s = 2; s <= 100; s++) {
            int curr = 0;
            vector<int> used(n);
            
            for(int i = 0; i < n; i++) {
                if(used[i]) continue;
                for(int j = i+1; j < n; j++) {
                    if(!used[j] && w[i] + w[j] == s) {
                        curr++;
                        used[i] = used[j] = 1;
                        break;
                    }
                }
            }
            ans = max(ans, curr);
        }
        
        cout << ans << '\n';
    }
    return 0;
}
