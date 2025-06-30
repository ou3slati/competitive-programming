/*
CF 646A - Odd Selection
https://codeforces.com/contest/1363/problem/A

Select x numbers with odd sum
n ≤ 1000

Key: Need odd number of odds
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        int odd = 0, even = 0;
        for(int i = 0; i < n; i++) {
            int a; cin >> a;
            (a & 1) ? odd++ : even++;
        }
        
        bool possible = false;
        for(int i = 1; i <= min(odd, x); i += 2) {
            if(x - i <= even) possible = true;
        }
        
        cout << (possible ? "Yes\n" : "No\n");
    }
    return 0;
}
