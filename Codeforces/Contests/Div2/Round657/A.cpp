/*
CF 657A - Choosing Teams
https://codeforces.com/contest/1387/problem/A

Form teams with min skill y
n ≤ 100

Key: Count students with skill ≥ y
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    
    int valid = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(5-x >= k) valid++;
    }
    
    cout << valid/3 << '\n';
    return 0;
}
