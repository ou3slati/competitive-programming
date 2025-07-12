/*
 * Advanced C++ Tricks for Competitive Programming
 * Emplace operations, container tricks, and optimization techniques
 */

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cout << "=== Emplace vs Push Operations ===\n";
    
    // Vector with pairs
    vector<pair<int, int>> vec;
    
    // push_back creates temporary object then copies/moves
    vec.push_back(make_pair(1, 2));
    vec.push_back({3, 4});
    
    // emplace_back constructs object directly in container (more efficient)
    vec.emplace_back(5, 6);
    vec.emplace_back(7, 8);
    
    cout << "Vector pairs: ";
    for (const auto& [x, y] : vec) {
        cout << "(" << x << "," << y << ") ";
    }
    cout << "\n";
    
    // Set operations
    set<int> s;
    s.insert(10);    // Traditional insert
    s.emplace(20);   // Direct construction (same for int, but useful for complex types)
    
    // Priority queue
    priority_queue<pair<int, int>> pq;
    pq.push({1, 2});
    pq.emplace(3, 4);  // More efficient
    
    cout << "Priority queue: ";
    while (!pq.empty()) {
        auto [x, y] = pq.top();
        pq.pop();
        cout << "(" << x << "," << y << ") ";
    }
    cout << "\n";
    
    // Map/unordered_map
    map<string, vector<int>> m;
    m["key1"].push_back(1);
    m.emplace("key2", vector<int>{2, 3, 4});
    
    cout << "\n=== Container Optimization Tricks ===\n";
    
    // Reserve space to avoid reallocations
    vector<int> large_vec;
    large_vec.reserve(1000000);  // Avoid multiple reallocations
    
    // Use resize when you know the final size
    vector<int> sized_vec(100, -1);  // 100 elements, all initialized to -1
    
    // Efficient string building
    string result;
    result.reserve(1000);  // Reserve space for efficiency
    for (int i = 0; i < 10; i++) {
        result += to_string(i) + " ";
    }
    cout << "Built string: " << result << "\n";
    
    cout << "\n=== Iterator and Range Tricks ===\n";
    
    vector<int> v = {1, 2, 3, 4, 5};
    
    // Generic begin/end (works with arrays too)
    cout << "Using generic begin/end: ";
    for (auto it = begin(v); it != end(v); ++it) {
        cout << *it << " ";
    }
    cout << "\n";
    
    // Works with C-style arrays
    int arr[] = {10, 20, 30, 40};
    cout << "C-style array: ";
    for (auto it = begin(arr); it != end(arr); ++it) {
        cout << *it << " ";
    }
    cout << "\n";
    
    cout << "\n=== Output Formatting Tricks ===\n";
    
    // Conditional newline trick
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    
    cout << "Matrix (traditional):\n";
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j];
            if (j < matrix[i].size() - 1) cout << " ";
        }
        cout << "\n";
    }
    
    cout << "Matrix (with trick):\n";
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " \n"[j == matrix[i].size() - 1];
        }
    }
    
    cout << "\n=== Memory and Performance Tricks ===\n";
    
    // Use deque for frequent front/back operations
    deque<int> dq;
    dq.push_front(1);
    dq.push_back(2);
    dq.push_front(0);
    
    cout << "Deque: ";
    for (int x : dq) cout << x << " ";
    cout << "\n";
    
    // Use unordered containers for O(1) average operations
    unordered_set<int> fast_set;
    unordered_map<string, int> fast_map;
    
    // Custom hash for pairs (useful for unordered_map with pair keys)
    auto pair_hash = [](const pair<int, int>& p) {
        return hash<int>{}(p.first) ^ (hash<int>{}(p.second) << 1);
    };
    
    unordered_set<pair<int, int>, decltype(pair_hash)> pair_set(0, pair_hash);
    pair_set.insert({1, 2});
    pair_set.insert({3, 4});
    
    cout << "\n=== Bit Manipulation Tricks ===\n";
    
    // Fast power of 2 check
    auto is_power_of_2 = [](int n) { return n > 0 && (n & (n - 1)) == 0; };
    
    cout << "8 is power of 2: " << is_power_of_2(8) << "\n";
    cout << "10 is power of 2: " << is_power_of_2(10) << "\n";
    
    // Count set bits
    int n = 42;
    cout << "Set bits in " << n << ": " << __builtin_popcountll(n) << "\n";
    
    // Find rightmost set bit
    cout << "Rightmost set bit of " << n << ": " << (n & -n) << "\n";
    
    cout << "\n=== Algorithm Shortcuts ===\n";
    
    // All permutations
    string s = "abc";
    cout << "All permutations of " << s << ":\n";
    sort(s.begin(), s.end());
    do {
        cout << s << " ";
    } while (next_permutation(s.begin(), s.end()));
    cout << "\n";
    
    // Rotate container
    vector<int> rotate_vec = {1, 2, 3, 4, 5};
    rotate(rotate_vec.begin(), rotate_vec.begin() + 2, rotate_vec.end());
    cout << "After rotating by 2: ";
    for (int x : rotate_vec) cout << x << " ";
    cout << "\n";
    
    // Partial sort (useful when you only need top K elements)
    vector<int> partial_vec = {5, 2, 8, 1, 9, 3, 7, 4, 6};
    partial_sort(partial_vec.begin(), partial_vec.begin() + 3, partial_vec.end());
    cout << "Top 3 elements: ";
    for (int i = 0; i < 3; i++) cout << partial_vec[i] << " ";
    cout << "\n";
    
    cout << "\n=== Competitive Programming Shortcuts ===\n";
    
    // Quick GCD/LCM
    auto gcd = [](int a, int b) { return __gcd(a, b); };
    auto lcm = [](int a, int b) { return a / __gcd(a, b) * b; };
    
    cout << "GCD(12, 18) = " << gcd(12, 18) << "\n";
    cout << "LCM(12, 18) = " << lcm(12, 18) << "\n";
    
    // Min/max of multiple values
    int a = 5, b = 3, c = 8, d = 1;
    cout << "Min of 4 values: " << min({a, b, c, d}) << "\n";
    cout << "Max of 4 values: " << max({a, b, c, d}) << "\n";
    
    // Clamp value to range
    int value = 15;
    int clamped = clamp(value, 5, 10);  // C++17
    cout << "Clamped " << value << " to [5,10]: " << clamped << "\n";
    
    // Exchange values (returns old value)
    int x = 10, y = 20;
    int old_x = exchange(x, y);
    cout << "After exchange: x=" << x << ", old_x=" << old_x << "\n";
    
    return 0;
}

/*
Performance Tips:
1. Use emplace instead of push when constructing objects
2. Reserve space for containers when size is known
3. Use unordered containers for faster lookups
4. Prefer range-based loops for readability
5. Use const references to avoid unnecessary copying
6. Use move semantics for expensive objects
7. Consider deque for frequent front/back operations
8. Use partial_sort when you only need top K elements

Memory Tips:
1. Clear containers when done: container.clear(); container.shrink_to_fit();
2. Use appropriate container types (vector vs deque vs list)
3. Avoid unnecessary string concatenations in loops
4. Use string_view for read-only string operations (C++17)
5. Consider using smaller data types when range allows
*/
