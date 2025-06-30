/*
CF 660A - Captain Flint and Crew Recruitment
https://codeforces.com/contest/1388/problem/A

Find four different numbers with sum n
n ≤ 1e4

Key: Use 6,10,14 and remainder
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
        
        if(n <= 30) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            if(n == 36 || n == 40 || n == 44) {
                cout << "6 10 15 " << n-31 << '\n';
            } else {
                cout << "6 10 14 " << n-30 << '\n';
            }
        }
    }
    return 0;
}
