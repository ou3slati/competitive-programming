/*
Global 14A - Phoenix and Gold
https://codeforces.com/contest/1515/problem/A

Rearrange weights to avoid sum X
n ≤ 100, w[i],X ≤ 100

Key: Sort, skip first weight that makes prefix = X
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        vector<int> w(n);
        int sum = 0;
        for(int& v : w) {
            cin >> v;
            sum += v;
        }
        
        if(sum == x) {
            cout << "NO\n";
            continue;
        }
        
        cout << "YES\n";
        sort(w.begin(), w.end());
        int prefix = 0;
        for(int i = 0; i < n; i++) {
            if(prefix + w[i] == x) {
                swap(w[i], w[i+1]);
            }
            prefix += w[i];
            cout << w[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
