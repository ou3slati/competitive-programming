/*
CF 655C - Omkar and Baseball
https://codeforces.com/contest/1372/problem/C

Min ops to sort array
n ≤ 2e5

Key: Count segments needing sort
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
        
        int segments = 0;
        bool in_segment = false;
        
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            
            if(x != i+1) {
                if(!in_segment) {
                    segments++;
                    in_segment = true;
                }
            } else {
                in_segment = false;
            }
        }
        
        cout << min(2, segments) << '\n';
    }
    return 0;
}
