/*
 * Lambda Functions in Competitive Programming
 * Anonymous functions for custom comparators, algorithms, and utilities
 */

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cout << "=== Basic Lambda Functions ===\n";
    
    // Basic lambda syntax
    auto add = [](int a, int b) -> int {
        return a + b;
    };
    
    cout << "5 + 3 = " << add(5, 3) << "\n";
    
    // Lambda without explicit return type (auto-deduced)
    auto multiply = [](int a, int b) {
        return a * b;
    };
    
    cout << "4 * 6 = " << multiply(4, 6) << "\n";
    
    // Lambda with no parameters
    auto get_random = []() {
        return rand() % 100;
    };
    
    cout << "Random: " << get_random() << "\n";
    
    cout << "\n=== Lambdas with STL Algorithms ===\n";
    
    vector<int> v = {5, 2, 8, 1, 9, 3};
    
    // Custom sorting with lambda
    sort(v.begin(), v.end(), [](int a, int b) {
        return a < b; // Ascending order
    });
    
    cout << "Sorted ascending: ";
    for (int x : v) cout << x << " ";
    cout << "\n";
    
    // Sort by absolute value
    vector<int> v2 = {-5, 3, -2, 8, -1};
    sort(v2.begin(), v2.end(), [](int a, int b) {
        return abs(a) < abs(b);
    });
    
    cout << "Sorted by absolute value: ";
    for (int x : v2) cout << x << " ";
    cout << "\n";
    
    // Count elements satisfying condition
    int even_count = count_if(v.begin(), v.end(), [](int x) {
        return x % 2 == 0;
    });
    
    cout << "Even numbers: " << even_count << "\n";
    
    // Transform elements
    vector<int> squares;
    transform(v.begin(), v.end(), back_inserter(squares), [](int x) {
        return x * x;
    });
    
    cout << "Squares: ";
    for (int x : squares) cout << x << " ";
    cout << "\n";
    
    cout << "\n=== Capture Lists ===\n";
    
    int multiplier = 10;
    
    // Capture by value
    auto scale_by_value = [multiplier](int x) {
        return x * multiplier;
    };
    
    // Capture by reference
    auto scale_by_ref = [&multiplier](int x) {
        return x * multiplier;
    };
    
    cout << "Scale 5 by " << multiplier << ": " << scale_by_value(5) << "\n";
    
    multiplier = 20;
    cout << "After changing multiplier to 20:\n";
    cout << "By value: " << scale_by_value(5) << "\n";      // Still uses 10
    cout << "By reference: " << scale_by_ref(5) << "\n";    // Uses 20
    
    // Capture all by value [=] or by reference [&]
    int a = 1, b = 2, c = 3;
    
    auto sum_all = [=]() {
        return a + b + c;
    };
    
    auto increment_all = [&]() {
        a++; b++; c++;
    };
    
    cout << "Sum: " << sum_all() << "\n";
    increment_all();
    cout << "After increment - a: " << a << ", b: " << b << ", c: " << c << "\n";
    
    cout << "\n=== Advanced Lambda Usage ===\n";
    
    // Lambda for custom comparator in priority queue
    auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first + a.second > b.first + b.second; // Min heap by sum
    };
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
    
    pq.push({3, 4});
    pq.push({1, 2});
    pq.push({5, 1});
    
    cout << "Priority queue (min sum): ";
    while (!pq.empty()) {
        auto [x, y] = pq.top();
        pq.pop();
        cout << "(" << x << "," << y << ") ";
    }
    cout << "\n";
    
    // Recursive lambda (C++14)
    auto factorial = [](int n) {
        auto fact_impl = [](int n, auto& self) -> int {
            return n <= 1 ? 1 : n * self(n - 1, self);
        };
        return fact_impl(n, fact_impl);
    };
    
    cout << "5! = " << factorial(5) << "\n";
    
    // Lambda for binary search predicate
    vector<int> sorted_v = {1, 3, 5, 7, 9, 11, 13};
    int target = 7;
    
    auto found = binary_search(sorted_v.begin(), sorted_v.end(), target);
    cout << "Found " << target << ": " << (found ? "Yes" : "No") << "\n";
    
    // Custom binary search with lambda
    auto lower = lower_bound(sorted_v.begin(), sorted_v.end(), target);
    if (lower != sorted_v.end() && *lower == target) {
        cout << "Position of " << target << ": " << (lower - sorted_v.begin()) << "\n";
    }
    
    cout << "\n=== Practical CP Examples ===\n";
    
    // Sort pairs by second element, then by first
    vector<pair<int, int>> pairs = {{3, 1}, {1, 2}, {2, 1}, {1, 1}};
    
    sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b) {
        return a.second != b.second ? a.second < b.second : a.first < b.first;
    });
    
    cout << "Sorted pairs: ";
    for (auto [x, y] : pairs) {
        cout << "(" << x << "," << y << ") ";
    }
    cout << "\n";
    
    // Find maximum element with custom criteria
    vector<string> words = {"cat", "elephant", "dog", "butterfly"};
    
    auto longest = *max_element(words.begin(), words.end(), [](const string& a, const string& b) {
        return a.length() < b.length();
    });
    
    cout << "Longest word: " << longest << "\n";
    
    return 0;
}

/*
Lambda Function Syntax:
[capture](parameters) -> return_type { body }

Capture modes:
[] - capture nothing
[=] - capture all by value
[&] - capture all by reference
[var] - capture var by value
[&var] - capture var by reference
[=, &var] - capture all by value except var by reference

Common use cases in CP:
1. Custom comparators for sorting
2. Predicates for algorithms (find_if, count_if, etc.)
3. Custom priority queue comparators
4. Inline utility functions
5. Recursive solutions with memoization
*/
