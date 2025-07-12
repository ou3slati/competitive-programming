/*
 * Extended Euclidean Algorithm
 * Time: O(log min(a,b)) | Space: O(1)
 * Finds gcd(a,b) and coefficients x,y such that ax + by = gcd(a,b)
 */

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll

class ExtendedGCD {
public:
    struct Result {
        int gcd, x, y;
    };
    
    // Returns gcd and coefficients x, y such that ax + by = gcd(a, b)
    static Result extended_gcd(int a, int b) {
        if (b == 0) {
            return {a, 1, 0};
        }
        
        Result res = extended_gcd(b, a % b);
        int x = res.y;
        int y = res.x - (a / b) * res.y;
        
        return {res.gcd, x, y};
    }
    
    // Modular multiplicative inverse of a modulo m
    // Returns -1 if inverse doesn't exist
    static int mod_inverse(int a, int m) {
        Result res = extended_gcd(a, m);
        if (res.gcd != 1) {
            return -1; // Inverse doesn't exist
        }
        return (res.x % m + m) % m;
    }
    
    // Solve linear Diophantine equation ax + by = c
    // Returns {x0, y0} where x0, y0 is a particular solution
    // General solution: x = x0 + k*(b/gcd), y = y0 - k*(a/gcd)
    static pair<bool, pair<int, int>> solve_diophantine(int a, int b, int c) {
        Result res = extended_gcd(a, b);
        if (c % res.gcd != 0) {
            return {false, {0, 0}}; // No solution
        }
        
        int scale = c / res.gcd;
        return {true, {res.x * scale, res.y * scale}};
    }
    
    // Find number of solutions to ax + by = c in range [x1, x2] × [y1, y2]
    static int count_solutions_in_range(int a, int b, int c, int x1, int x2, int y1, int y2) {
        auto [has_solution, solution] = solve_diophantine(a, b, c);
        if (!has_solution) return 0;
        
        Result gcd_res = extended_gcd(a, b);
        int g = gcd_res.gcd;
        a /= g; b /= g; // Reduce to coprime case
        
        auto [x0, y0] = solution;
        
        // General solution: x = x0 + k*b, y = y0 - k*a
        // Find range of k such that x1 <= x0 + k*b <= x2 and y1 <= y0 - k*a <= y2
        
        int k_min = LLONG_MIN, k_max = LLONG_MAX;
        
        // Constraints from x
        if (b > 0) {
            k_min = max(k_min, (x1 - x0 + b - 1) / b);
            k_max = min(k_max, (x2 - x0) / b);
        } else if (b < 0) {
            k_min = max(k_min, (x2 - x0 + b + 1) / b);
            k_max = min(k_max, (x1 - x0) / b);
        } else if (x0 < x1 || x0 > x2) {
            return 0;
        }
        
        // Constraints from y
        if (a > 0) {
            k_min = max(k_min, (y0 - y2 + a - 1) / a);
            k_max = min(k_max, (y0 - y1) / a);
        } else if (a < 0) {
            k_min = max(k_min, (y0 - y1 + a + 1) / a);
            k_max = min(k_max, (y0 - y2) / a);
        } else if (y0 < y1 || y0 > y2) {
            return 0;
        }
        
        return max(0LL, k_max - k_min + 1);
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int a, b;
    cin >> a >> b;
    
    auto res = ExtendedGCD::extended_gcd(a, b);
    cout << "gcd(" << a << ", " << b << ") = " << res.gcd << "\n";
    cout << "Coefficients: x = " << res.x << ", y = " << res.y << "\n";
    cout << "Verification: " << a << "*" << res.x << " + " << b << "*" << res.y << " = " << a*res.x + b*res.y << "\n";
    
    // Test modular inverse
    int inv = ExtendedGCD::mod_inverse(a, b);
    if (inv != -1) {
        cout << "Modular inverse of " << a << " mod " << b << " = " << inv << "\n";
    } else {
        cout << "Modular inverse doesn't exist\n";
    }
    
    return 0;
}
