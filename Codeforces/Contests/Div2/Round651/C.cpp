/*
CF 651C - Number Game
https://codeforces.com/contest/1370/problem/C

Game with subtracting divisors
n ≤ 1e9

Key: Analyze cases based on prime factors
*/

#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if(n < 2) return false;
    for(int i = 2; i*i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--) {
        int n;
        cin >> n;
        
        if(n == 1) cout << "FastestFinger\n";
        else if(n == 2) cout << "Ashishgup\n";
        else if(n % 2 == 1) cout << "Ashishgup\n";
        else {
            int odd = n;
            while(odd % 2 == 0) odd /= 2;
            
            if(odd == 1) cout << "FastestFinger\n";
            else if(n/2 % 2 == 1 && isPrime(n/2)) cout << "FastestFinger\n";
            else cout << "Ashishgup\n";
        }
    }
    return 0;
}
