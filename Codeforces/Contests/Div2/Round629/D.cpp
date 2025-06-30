/*
CF 629D - Carousel
https://codeforces.com/contest/1328/problem/D

Color adjacent elements with min colors
n ≤ 2e5

Key: Two colors enough unless odd cycle with all different
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
        vector<int> a(n);
        for(int& x : a) cin >> x;
        
        // Check if all equal
        bool all_equal = true;
        for(int i = 1; i < n; i++) {
            if(a[i] != a[0]) all_equal = false;
        }
        
        if(all_equal) {
            cout << "1\n";
            for(int i = 0; i < n; i++) cout << "1 ";
            cout << '\n';
            continue;
        }
        
        // Check if any adjacent equal or even length
        bool has_adj_equal = false;
        for(int i = 0; i < n; i++) {
            if(a[i] == a[(i+1)%n]) has_adj_equal = true;
        }
        
        if(n % 2 == 0 || has_adj_equal) {
            cout << "2\n";
            for(int i = 0; i < n; i++) cout << (i%2 + 1) << " ";
            cout << '\n';
            continue;
        }
        
        // Odd cycle with all different - need 3 colors
        cout << "3\n";
        for(int i = 0; i < n-1; i++) cout << (i%2 + 1) << " ";
        cout << "3\n";
    }
    return 0;
}
