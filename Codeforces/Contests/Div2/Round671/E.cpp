/*
CF 671E - Decryption
https://codeforces.com/contest/1419/problem/E

Find special permutation of divisors
n ≤ 1e9

Key insights:
1. Use prime factorization
2. Create cycle using prime power relationships
3. Special case for exactly 2 prime factors
4. Output is possible with cost 0 except when n = p1*p2
*/

#include <bits/stdc++.h>
using namespace std;

vector<long long> get_prime_factors(long long n) {
    vector<long long> factors;
    for(long long i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            factors.push_back(i);
            while(n % i == 0) n /= i;
        }
    }
    if(n > 1) factors.push_back(n);
    return factors;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        long long n;
        cin >> n;
        
        // Get all divisors
        set<long long> divisors;
        for(long long i = 2; i * i <= n; i++) {
            if(n % i == 0) {
                divisors.insert(i);
                divisors.insert(n/i);
            }
        }
        divisors.insert(n);
        
        // Get prime factors
        vector<long long> primes = get_prime_factors(n);
        
        // Special case: exactly 2 prime factors
        if(primes.size() == 2) {
            if(primes[0] * primes[1] == n) {
                cout << primes[0] << ' ' << n << ' ' << primes[1] << '\n';
                cout << "1\n";
                continue;
            }
            
            // Print in order: p1, multiples of p1, p1*p2, p2, multiples of p2, n
            cout << primes[0] << ' ';
            divisors.erase(primes[0]);
            
            vector<long long> to_remove;
            for(auto x : divisors) {
                if(x % primes[0] == 0 && x != primes[0]*primes[1] && x != n) {
                    cout << x << ' ';
                    to_remove.push_back(x);
                }
            }
            for(auto x : to_remove) divisors.erase(x);
            
            cout << primes[0]*primes[1] << ' ';
            divisors.erase(primes[0]*primes[1]);
            
            cout << primes[1] << ' ';
            divisors.erase(primes[1]);
            
            to_remove.clear();
            for(auto x : divisors) {
                if(x % primes[1] == 0 && x != n) {
                    cout << x << ' ';
                    to_remove.push_back(x);
                }
            }
            for(auto x : to_remove) divisors.erase(x);
            
            cout << n << '\n';
            cout << "0\n";
            continue;
        }
        
        // General case: create cycle using prime products
        set<long long> prime_products;
        for(int i = 0; i < primes.size(); i++) {
            prime_products.insert(primes[i] * primes[(i+1)%primes.size()]);
        }
        
        for(int i = 0; i < primes.size(); i++) {
            cout << primes[i] << ' ';
            divisors.erase(primes[i]);
            
            vector<long long> to_remove;
            for(auto x : divisors) {
                if(x % primes[i] == 0 && !prime_products.count(x)) {
                    cout << x << ' ';
                    to_remove.push_back(x);
                }
            }
            for(auto x : to_remove) divisors.erase(x);
            
            cout << primes[i]*primes[(i+1)%primes.size()] << ' ';
            divisors.erase(primes[i]*primes[(i+1)%primes.size()]);
        }
        cout << '\n';
        cout << "0\n";
    }
    
    return 0;
}
