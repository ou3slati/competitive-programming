/*
CF 669A - Ahahahahahahahaha
https://codeforces.com/contest/1407/problem/A

Remove half elements for sum divisible by 2
n ≤ 1000

Key: Keep majority element
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
        vector<int> a(n);
        int ones = 0;
        for(int& x : a) {
            cin >> x;
            ones += x;
        }
        
        if(ones <= n/2) {
            cout << n/2 << '\n';
            for(int i = 0; i < n/2; i++) cout << "0 ";
        } else {
            int size = n/2 + (n/2)%2;
            cout << size << '\n';
            for(int i = 0; i < size; i++) cout << "1 ";
        }
        cout << '\n';
    }
    return 0;
}
