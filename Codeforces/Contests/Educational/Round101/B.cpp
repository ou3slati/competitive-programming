/*
EDU 101B - Red and Blue
https://codeforces.com/contest/1469/problem/B

Max sum from interleaving two arrays' prefixes
n,m ≤ 100, |a[i]| ≤ 100

Key: Best result comes from best prefixes independently
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n;
        int max_red = 0, sum = 0;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            sum += x;
            max_red = max(max_red, sum);
        }
        
        cin >> m;
        int max_blue = 0;
        sum = 0;
        for(int i = 0; i < m; i++) {
            int x; cin >> x;
            sum += x;
            max_blue = max(max_blue, sum);
        }
        
        cout << max(0, max_red + max_blue) << '\n';
    }
    return 0;
}
