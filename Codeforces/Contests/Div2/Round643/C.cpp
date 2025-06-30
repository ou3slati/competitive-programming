/*
CF 643C - Count Triangles
https://codeforces.com/contest/1355/problem/C

Count triangles with sides in ranges
a,b,c,d ≤ 5e5

Key: Fix largest side, count valid pairs
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    vector<ll> sum(b+c+1);
    for(int x = a; x <= b; x++) {
        sum[x+b]++;
        sum[x+c+1]--;
    }
    
    for(int i = 1; i < b+c+1; i++) {
        sum[i] += sum[i-1];
    }
    
    for(int i = 1; i < b+c+1; i++) {
        sum[i] += sum[i-1];
    }
    
    ll ans = 0;
    for(int z = c; z <= d; z++) {
        if(z < a+b) continue;
        ans += sum[z] - sum[z-1];
    }
    
    cout << ans << '\n';
    return 0;
}
