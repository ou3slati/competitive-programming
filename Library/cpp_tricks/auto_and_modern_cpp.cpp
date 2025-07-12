/*
 * Modern C++ Features for Competitive Programming
 * Auto keyword, range-based loops, and type deduction
 */

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    // Auto keyword examples
    cout << "=== Auto Keyword Examples ===\n";
    
    // Basic auto usage
    auto x = 42;        // int
    auto y = 3.14;      // double
    auto s = "hello";   // const char*
    auto str = string("world"); // string
    
    cout << "x: " << x << " (type: int)\n";
    cout << "y: " << y << " (type: double)\n";
    
    // Auto with containers
    vector<int> v = {1, 2, 3, 4, 5};
    auto it = v.begin();  // vector<int>::iterator
    auto size = v.size(); // size_t
    
    // Range-based for loops with auto
    cout << "\n=== Range-based Loops ===\n";
    
    // Modify elements by reference
    for (auto &element : v) {
        element *= 2;
    }
    
    // Read-only iteration
    for (auto element : v) {
        cout << element << " ";
    }
    cout << "\n";
    
    // With const auto& for efficiency (no copying)
    for (const auto& element : v) {
        cout << element << " ";
    }
    cout << "\n";
    
    // Auto with pairs and maps
    cout << "\n=== Auto with Pairs and Maps ===\n";
    
    map<string, int> m = {{"apple", 5}, {"banana", 3}, {"orange", 8}};
    
    for (auto& [key, value] : m) { // C++17 structured binding
        cout << key << ": " << value << "\n";
        value++; // Modify value
    }
    
    // Traditional way (still useful)
    for (auto it = m.begin(); it != m.end(); ++it) {
        cout << it->first << " -> " << it->second << "\n";
    }
    
    // Auto with algorithms
    cout << "\n=== Auto with Algorithms ===\n";
    
    // Find operations
    auto found = find(v.begin(), v.end(), 6);
    if (found != v.end()) {
        cout << "Found: " << *found << "\n";
    }
    
    // Lambda with auto
    auto is_even = [](int n) { return n % 2 == 0; };
    auto even_count = count_if(v.begin(), v.end(), is_even);
    cout << "Even numbers: " << even_count << "\n";
    
    // Auto with initializer lists
    cout << "\n=== Auto with Initializer Lists ===\n";
    
    for (auto x : {1, 4, 9, 16, 25}) {
        cout << x << " ";
    }
    cout << "\n";
    
    // Auto with function return types (C++14)
    auto get_max = [](int a, int b) -> auto {
        return a > b ? a : b;
    };
    
    cout << "Max of 10 and 20: " << get_max(10, 20) << "\n";
    
    // Auto with complex nested types
    cout << "\n=== Auto with Complex Types ===\n";
    
    vector<vector<pair<int, string>>> complex_data = {
        {{1, "one"}, {2, "two"}},
        {{3, "three"}, {4, "four"}}
    };
    
    for (const auto& row : complex_data) {
        for (const auto& [num, word] : row) {
            cout << num << ":" << word << " ";
        }
        cout << "\n";
    }
    
    // Auto with trailing return types (advanced)
    auto multiply = [](auto a, auto b) -> decltype(a * b) {
        return a * b;
    };
    
    cout << "Multiply: " << multiply(3, 4) << "\n";
    cout << "Multiply: " << multiply(2.5, 4) << "\n";
    
    return 0;
}

/*
Key Benefits of Auto:
1. Reduces verbosity with complex type names
2. Makes code more maintainable
3. Prevents type mismatches
4. Essential for lambda expressions and modern C++

Best Practices:
1. Use auto when type is obvious from context
2. Use const auto& for read-only access to avoid copying
3. Use auto& when you need to modify elements
4. Don't overuse - sometimes explicit types are clearer
*/
