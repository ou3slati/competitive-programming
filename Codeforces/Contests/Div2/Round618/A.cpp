/*
CF 618A - Non-zero
https://codeforces.com/contest/1300/problem/A

Make array sum and product non-zero
n ≤ 100, |a[i]| ≤ 100

Key: Zeros affect both sum and product, handle first
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
        
        int ops = 0, sum = 0;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            if(x == 0) { ops++; x = 1; }
            sum += x;
        }
        if(sum == 0) ops++;
        cout << ops << '\n';
    }
    return 0;
}
