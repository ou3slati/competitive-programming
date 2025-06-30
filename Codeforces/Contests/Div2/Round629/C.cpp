/*
CF 629C - Ternary XOR
https://codeforces.com/contest/1328/problem/C

Split ternary number into two with minimum max
n ≤ 5e4, digits in {0,1,2}

Key: Equal until first 2, then split optimally
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
        string x;
        cin >> n >> x;
        
        string a(n, '0'), b(n, '0');
        bool split = false;
        
        for(int i = 0; i < n; i++) {
            if(!split) {
                if(x[i] == '2') {
                    a[i] = b[i] = '1';
                } else if(x[i] == '1') {
                    a[i] = '1';
                    split = true;
                } else {
                    a[i] = b[i] = '0';
                }
            } else {
                b[i] = x[i];
            }
        }
        
        cout << a << '\n' << b << '\n';
    }
    return 0;
}
