/*
CF 640B - Same Parity Summands
https://codeforces.com/contest/1352/problem/B

Split n into k numbers same parity
n,k ≤ 1e4

Key: Try min numbers of each parity
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
        
        // Try even numbers
        if(n >= 2*k && n % 2 == 0) {
            cout << "YES\n";
            for(int i = 0; i < k-1; i++) cout << "2 ";
            cout << n - 2*(k-1) << '\n';
            continue;
        }
        
        // Try odd numbers
        if(n >= k && n % 2 == k % 2) {
            cout << "YES\n";
            for(int i = 0; i < k-1; i++) cout << "1 ";
            cout << n - (k-1) << '\n';
            continue;
        }
        
        cout << "NO\n";
    }
    return 0;
}
