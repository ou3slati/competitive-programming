/*
CF 655B - Omkar and Last Class of Math
https://codeforces.com/contest/1372/problem/B

Find a,b where lcm(a,b) = n minimal
n ≤ 1e9

Key: Use smallest divisor
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
        
        int a = 1;
        for(int i = 2; i*i <= n; i++) {
            if(n % i == 0) {
                a = n/i;
                break;
            }
        }
        
        cout << a << ' ' << n-a << '\n';
    }
    return 0;
}
