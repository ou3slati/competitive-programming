/*
CF 637C - Nastya and Strange Generator
https://codeforces.com/contest/1341/problem/C

Check if permutation possible
n ≤ 1e5

Key: Elements must form increasing blocks
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
        vector<int> pos(n+1);
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            pos[x] = i;
        }
        
        bool possible = true;
        int last = n;
        
        for(int i = 1; i <= n; i++) {
            if(pos[i] > last) {
                possible = false;
                break;
            }
            last = pos[i];
        }
        
        cout << (possible ? "Yes\n" : "No\n");
    }
    return 0;
}
