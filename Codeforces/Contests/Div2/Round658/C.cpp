/*
CF 658C - Prefix Flip
https://codeforces.com/contest/1382/problem/C

Transform string with prefix operations
n ≤ 1e5

Key: Build solution from right to left
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) {
        int n;
        string a, b;
        cin >> n >> a >> b;
        
        vector<int> ops;
        for(int i = n-1; i >= 0; i--) {
            if(a[i] != b[i]) {
                if(a[0] != b[i]) {
                    ops.push_back(1);
                }
                ops.push_back(i+1);
                
                // Flip prefix
                for(int j = 0; j <= i; j++) {
                    a[j] = (a[j] == '0' ? '1' : '0');
                }
                reverse(a.begin(), a.begin()+i+1);
            }
        }
        
        cout << ops.size() << ' ';
        for(int x : ops) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}
