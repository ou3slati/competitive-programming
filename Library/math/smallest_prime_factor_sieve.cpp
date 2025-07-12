/*
 * Smallest Prime Factor (SPF) Sieve
 * Time: O(n log log n) preprocessing, O(log n) per factorization | Space: O(n)
 * Precomputes smallest prime factor for efficient prime factorization
 */

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll

class SPFSieve {
private:
    vector<int> spf;
    int max_n;
    
public:
    SPFSieve(int n) : max_n(n), spf(n + 1) {
        build_sieve();
    }
    
    void build_sieve() {
        // Initialize SPF array
        for (int i = 1; i <= max_n; i++) {
            spf[i] = i;
        }
        
        // Sieve to find smallest prime factors
        for (int i = 2; i * i <= max_n; i++) {
            if (spf[i] == i) { // i is prime
                for (int j = i * i; j <= max_n; j += i) {
                    if (spf[j] == j) { // First time we encounter j
                        spf[j] = i;
                    }
                }
            }
        }
    }
    
    // Get prime factorization of n
    vector<int> get_prime_factors(int n) {
        vector<int> factors;
        while (n > 1) {
            factors.push_back(spf[n]);
            n /= spf[n];
        }
        return factors;
    }
    
    // Get prime factorization with counts
    map<int, int> get_prime_factorization(int n) {
        map<int, int> factors;
        while (n > 1) {
            factors[spf[n]]++;
            n /= spf[n];
        }
        return factors;
    }
    
    // Check if number is prime
    bool is_prime(int n) {
        if (n <= 1) return false;
        return spf[n] == n;
    }
    
    // Get all divisors of n
    vector<int> get_divisors(int n) {
        map<int, int> prime_factors = get_prime_factorization(n);
        vector<int> divisors = {1};
        
        for (auto [prime, count] : prime_factors) {
            int size = divisors.size();
            int power = 1;
            
            for (int i = 0; i < count; i++) {
                power *= prime;
                for (int j = 0; j < size; j++) {
                    divisors.push_back(divisors[j] * power);
                }
            }
        }
        
        sort(divisors.begin(), divisors.end());
        return divisors;
    }
    
    // Count number of divisors
    int count_divisors(int n) {
        map<int, int> factors = get_prime_factorization(n);
        int count = 1;
        for (auto [prime, exp] : factors) {
            count *= (exp + 1);
        }
        return count;
    }
    
    // Sum of divisors
    int sum_of_divisors(int n) {
        map<int, int> factors = get_prime_factorization(n);
        int sum = 1;
        
        for (auto [prime, exp] : factors) {
            int term_sum = 0;
            int power = 1;
            for (int i = 0; i <= exp; i++) {
                term_sum += power;
                power *= prime;
            }
            sum *= term_sum;
        }
        
        return sum;
    }
    
    // Euler's totient function φ(n)
    int euler_totient(int n) {
        map<int, int> factors = get_prime_factorization(n);
        int result = n;
        
        for (auto [prime, exp] : factors) {
            result = result / prime * (prime - 1);
        }
        
        return result;
    }
    
    // Get all primes up to max_n
    vector<int> get_all_primes() {
        vector<int> primes;
        for (int i = 2; i <= max_n; i++) {
            if (spf[i] == i) {
                primes.push_back(i);
            }
        }
        return primes;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int max_n = 1000000;
    SPFSieve sieve(max_n);
    
    int n;
    cin >> n;
    
    // Prime factorization
    vector<int> factors = sieve.get_prime_factors(n);
    cout << "Prime factors of " << n << ": ";
    for (int factor : factors) {
        cout << factor << " ";
    }
    cout << "\n";
    
    // Prime factorization with counts
    auto factorization = sieve.get_prime_factorization(n);
    cout << "Prime factorization: ";
    for (auto [prime, count] : factorization) {
        cout << prime << "^" << count << " ";
    }
    cout << "\n";
    
    // Other properties
    cout << "Is prime: " << (sieve.is_prime(n) ? "Yes" : "No") << "\n";
    cout << "Number of divisors: " << sieve.count_divisors(n) << "\n";
    cout << "Sum of divisors: " << sieve.sum_of_divisors(n) << "\n";
    cout << "Euler's totient: " << sieve.euler_totient(n) << "\n";
    
    // All divisors
    vector<int> divisors = sieve.get_divisors(n);
    cout << "All divisors: ";
    for (int div : divisors) {
        cout << div << " ";
    }
    cout << "\n";
    
    return 0;
}
