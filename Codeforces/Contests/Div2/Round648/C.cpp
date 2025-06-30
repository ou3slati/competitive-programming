/*
CF 648C - Rotation Matching
https://codeforces.com/contest/1365/problem/C

Max matches after rotation
n ≤ 2e5

Key: Count shifts needed for each element
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> pos(n+1);
    
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pos[x] = i;
    }
    
    vector<int> shifts(n);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int shift = (i - pos[x] + n) % n;
        shifts[shift]++;
    }
    
    cout << *max_element(shifts.begin(), shifts.end()) << '\n';
    return 0;
}
