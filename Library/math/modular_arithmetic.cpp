/*
 * Modular Arithmetic Utilities
 * Fast modular exponentiation, inverse, and common operations
 */

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll

class ModularArithmetic {
private:
    static int mod;
    
public:
    static void set_mod(int m) { mod = m; }
    
    // Fast modular exponentiation: (base^exp) % mod
    static int mod_pow(int base, int exp, int m = mod) {
        int result = 1;
        base %= m;
        while (exp > 0) {
            if (exp & 1) {
                result = (result * base) % m;
            }
            base = (base * base) % m;
            exp >>= 1;
        }
        return result;
    }
    
    // Modular inverse using Fermat's little theorem (works when mod is prime)
    static int mod_inv_fermat(int a, int m = mod) {
        return mod_pow(a, m - 2, m);
    }
    
    // Modular inverse using Extended Euclidean Algorithm (works for any coprime a, m)
    static int mod_inv_extended(int a, int m = mod) {
        auto extended_gcd = [](int a, int b) -> pair<int, pair<int, int>> {
            if (b == 0) return {a, {1, 0}};
            auto [g, xy] = extended_gcd(b, a % b);
            return {g, {xy.second, xy.first - (a / b) * xy.second}};
        };
        
        auto [gcd, xy] = extended_gcd(a, m);
        if (gcd != 1) return -1; // Inverse doesn't exist
        return (xy.first % m + m) % m;
    }
    
    // Modular division: (a / b) % mod = (a * inv(b)) % mod
    static int mod_div(int a, int b, int m = mod) {
        return (a * mod_inv_fermat(b, m)) % m;
    }
    
    // Modular factorial and inverse factorial (useful for combinations)
    static vector<int> factorial, inv_factorial;
    
    static void precompute_factorials(int n, int m = mod) {
        factorial.resize(n + 1);
        inv_factorial.resize(n + 1);
        
        factorial[0] = 1;
        for (int i = 1; i <= n; i++) {
            factorial[i] = (factorial[i - 1] * i) % m;
        }
        
        inv_factorial[n] = mod_inv_fermat(factorial[n], m);
        for (int i = n - 1; i >= 0; i--) {
            inv_factorial[i] = (inv_factorial[i + 1] * (i + 1)) % m;
        }
    }
    
    // nCr mod p
    static int combination(int n, int r, int m = mod) {
        if (r > n || r < 0) return 0;
        return (factorial[n] * inv_factorial[r] % m) * inv_factorial[n - r] % m;
    }
    
    // nPr mod p
    static int permutation(int n, int r, int m = mod) {
        if (r > n || r < 0) return 0;
        return factorial[n] * inv_factorial[n - r] % m;
    }
    
    // Chinese Remainder Theorem
    // Solves system: x ≡ a[i] (mod m[i])
    static pair<int, int> chinese_remainder_theorem(vector<int>& a, vector<int>& m) {
        int n = a.size();
        int M = 1;
        for (int mod : m) M *= mod;
        
        int result = 0;
        for (int i = 0; i < n; i++) {
            int Mi = M / m[i];
            int yi = mod_inv_extended(Mi, m[i]);
            result = (result + a[i] * Mi % M * yi) % M;
        }
        
        return {(result % M + M) % M, M};
    }
    
    // Euler's totient function φ(n)
    static int euler_totient(int n) {
        int result = n;
        for (int p = 2; p * p <= n; p++) {
            if (n % p == 0) {
                while (n % p == 0) n /= p;
                result -= result / p;
            }
        }
        if (n > 1) result -= result / n;
        return result;
    }
    
    // Discrete logarithm using baby-step giant-step
    static int discrete_log(int a, int b, int m) {
        int sqrt_m = ceil(sqrt(m));
        map<int, int> baby_steps;
        
        int gamma = 1;
        for (int j = 0; j < sqrt_m; j++) {
            if (baby_steps.find(gamma) == baby_steps.end()) {
                baby_steps[gamma] = j;
            }
            gamma = (gamma * a) % m;
        }
        
        int factor = mod_inv_extended(mod_pow(a, sqrt_m, m), m);
        int y = b;
        
        for (int i = 0; i < sqrt_m; i++) {
            if (baby_steps.find(y) != baby_steps.end()) {
                int ans = i * sqrt_m + baby_steps[y];
                if (ans > 0) return ans;
            }
            y = (y * factor) % m;
        }
        
        return -1; // No solution
    }
};

int ModularArithmetic::mod = 1000000007;
vector<int> ModularArithmetic::factorial;
vector<int> ModularArithmetic::inv_factorial;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int x, n, m;
    cin >> x >> n >> m;
    
    ModularArithmetic::set_mod(m);
    
    cout << "Modular power: " << ModularArithmetic::mod_pow(x, n, m) << "\n";
    cout << "Modular inverse (Fermat): " << ModularArithmetic::mod_inv_fermat(x, m) << "\n";
    cout << "Modular inverse (Extended): " << ModularArithmetic::mod_inv_extended(x, m) << "\n";
    
    // Precompute factorials for combinations
    ModularArithmetic::precompute_factorials(20, m);
    cout << "10C5 mod " << m << " = " << ModularArithmetic::combination(10, 5, m) << "\n";
    
    return 0;
}
