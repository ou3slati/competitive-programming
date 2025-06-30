/*
CF 630B - Composite Coloring
https://codeforces.com/contest/1332/problem/B

Color numbers by smallest prime factor
n ≤ 1000, a[i] ≤ 1000

Key: First 11 primes sufficient for range
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    const vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31};
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), color(n);
        for(int& x : a) cin >> x;
        
        // Map prime factors to colors
        vector<int> used_colors;
        map<int,int> prime_color;
        
        for(int i = 0; i < n; i++) {
            int x = a[i];
            // Find smallest prime factor
            for(int p : primes) {
                if(x % p == 0) {
                    if(!prime_color.count(p)) {
                        prime_color[p] = used_colors.size() + 1;
                        used_colors.push_back(p);
                    }
                    color[i] = prime_color[p];
                    break;
                }
            }
        }
        
        cout << used_colors.size() << '\n';
        for(int c : color) cout << c << ' ';
        cout << '\n';
    }
    return 0;
}
