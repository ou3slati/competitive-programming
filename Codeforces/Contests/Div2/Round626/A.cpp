/*
CF 626A - Even Subset Sum
https://codeforces.com/contest/1323/problem/A

Find subset with even sum
n ≤ 100, a[i] ≤ 100

Key: One even or two odd numbers
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
        
        vector<int> odd;
        int even_idx = -1;
        
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if(x % 2) odd.push_back(i+1);
            else even_idx = i+1;
        }
        
        if(even_idx != -1) {
            cout << "1\n" << even_idx << '\n';
        }
        else if(odd.size() >= 2) {
            cout << "2\n" << odd[0] << ' ' << odd[1] << '\n';
        }
        else {
            cout << "-1\n";
        }
    }
    return 0;
}
