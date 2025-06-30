/*
CF 650B - Even Array
https://codeforces.com/contest/1367/problem/B

Min moves to make even indices even
n ≤ 40

Key: Count misplaced odd/even numbers
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
        int odd = 0, even = 0;
        
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            if((x%2) != (i%2)) {
                if(i%2) odd++;
                else even++;
            }
        }
        
        cout << (odd == even ? odd : -1) << '\n';
    }
    return 0;
}
