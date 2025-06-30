/*
CF 653B - Multiply by 2, divide by 6
https://codeforces.com/contest/1374/problem/B

Min ops to make n = 1
n ≤ 1e9

Key: Count factors of 2 and 3
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
        
        int twos = 0, threes = 0;
        while(n % 2 == 0) n /= 2, twos++;
        while(n % 3 == 0) n /= 3, threes++;
        
        if(n != 1 || twos > threes) cout << "-1\n";
        else cout << 2*threes - twos << '\n';
    }
    return 0;
}
