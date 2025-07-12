/*
 * Tuple Operations and Structured Bindings
 * Working with tuples, pairs, and tie operations
 */

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cout << "=== Basic Tuple Operations ===\n";
    
    // Creating tuples
    auto t1 = make_tuple(1, 2.5, "hello");
    tuple<int, double, string> t2(42, 3.14, "world");
    
    // Accessing tuple elements
    cout << "t1: " << get<0>(t1) << ", " << get<1>(t1) << ", " << get<2>(t1) << "\n";
    
    // Tuple size
    cout << "Tuple size: " << tuple_size<decltype(t1)>::value << "\n";
    
    cout << "\n=== Tie Operations ===\n";
    
    // Basic tie usage - unpacking tuples
    int a, b, c, d;
    tie(a, b, c, d) = make_tuple(10, 20, 30, 40);
    cout << "After tie: a=" << a << ", b=" << b << ", c=" << c << ", d=" << d << "\n";
    
    // Swapping values using tie
    tie(a, b, c, d) = make_tuple(d, c, b, a);
    cout << "After swap: a=" << a << ", b=" << b << ", c=" << c << ", d=" << d << "\n";
    
    // Using tie with pairs
    pair<int, int> p = {100, 200};
    tie(a, b) = p;
    cout << "From pair: a=" << a << ", b=" << b << "\n";
    
    // Ignoring values with std::ignore
    tie(a, ignore, b, ignore) = make_tuple(1, 999, 5, 888);
    cout << "With ignore: a=" << a << ", b=" << b << "\n";
    
    cout << "\n=== Structured Bindings (C++17) ===\n";
    
    // Modern way to unpack tuples
    auto [x, y, z] = make_tuple(7, 8, 9);
    cout << "Structured binding: x=" << x << ", y=" << y << ", z=" << z << "\n";
    
    // With pairs
    pair<string, int> name_age = {"Alice", 25};
    auto [name, age] = name_age;
    cout << "Name: " << name << ", Age: " << age << "\n";
    
    // With arrays
    int arr[3] = {11, 22, 33};
    auto [first, second, third] = arr;
    cout << "Array elements: " << first << ", " << second << ", " << third << "\n";
    
    cout << "\n=== Practical Applications ===\n";
    
    // Function returning multiple values
    auto divide_with_remainder = [](int dividend, int divisor) {
        return make_tuple(dividend / divisor, dividend % divisor);
    };
    
    auto [quotient, remainder] = divide_with_remainder(17, 5);
    cout << "17 ÷ 5 = " << quotient << " remainder " << remainder << "\n";
    
    // Working with maps
    map<string, int> scores = {{"Alice", 95}, {"Bob", 87}, {"Charlie", 92}};
    
    cout << "Map iteration with structured bindings:\n";
    for (const auto& [student, score] : scores) {
        cout << student << ": " << score << "\n";
    }
    
    // Multiple assignment from containers
    vector<int> v = {1, 2, 3, 4, 5};
    auto [v1, v2, v3, v4, v5] = make_tuple(v[0], v[1], v[2], v[3], v[4]);
    cout << "Vector elements: " << v1 << ", " << v2 << ", " << v3 << ", " << v4 << ", " << v5 << "\n";
    
    cout << "\n=== Tuple Comparison and Sorting ===\n";
    
    // Tuples have lexicographic comparison
    vector<tuple<int, int, string>> students = {
        {85, 2, "Bob"},
        {95, 1, "Alice"},
        {85, 3, "Charlie"},
        {95, 2, "David"}
    };
    
    // Sort by score (descending), then by rank (ascending)
    sort(students.begin(), students.end(), [](const auto& a, const auto& b) {
        auto [score_a, rank_a, name_a] = a;
        auto [score_b, rank_b, name_b] = b;
        return score_a != score_b ? score_a > score_b : rank_a < rank_b;
    });
    
    cout << "Sorted students:\n";
    for (const auto& [score, rank, name] : students) {
        cout << name << ": score=" << score << ", rank=" << rank << "\n";
    }
    
    cout << "\n=== Advanced Tuple Techniques ===\n";
    
    // Tuple concatenation
    auto t_small = make_tuple(1, 2);
    auto t_large = tuple_cat(t_small, make_tuple(3, 4, 5));
    
    auto [e1, e2, e3, e4, e5] = t_large;
    cout << "Concatenated tuple: " << e1 << ", " << e2 << ", " << e3 << ", " << e4 << ", " << e5 << "\n";
    
    // Using tuples in algorithms
    vector<tuple<int, int>> points = {{3, 4}, {1, 2}, {5, 1}, {2, 3}};
    
    // Find point closest to origin
    auto closest = *min_element(points.begin(), points.end(), [](const auto& a, const auto& b) {
        auto [x1, y1] = a;
        auto [x2, y2] = b;
        return x1*x1 + y1*y1 < x2*x2 + y2*y2;
    });
    
    auto [cx, cy] = closest;
    cout << "Closest point to origin: (" << cx << ", " << cy << ")\n";
    
    cout << "\n=== Competitive Programming Examples ===\n";
    
    // Reading multiple inputs
    // In practice: cin >> a >> b >> c;
    // But with tuple: 
    auto read_three = []() {
        int x, y, z;
        // cin >> x >> y >> z; // Simulated
        x = 10; y = 20; z = 30; // Example values
        return make_tuple(x, y, z);
    };
    
    auto [input1, input2, input3] = read_three();
    cout << "Read inputs: " << input1 << ", " << input2 << ", " << input3 << "\n";
    
    // Coordinate transformations
    auto rotate_point = [](int x, int y) {
        // Rotate 90 degrees clockwise
        return make_tuple(y, -x);
    };
    
    auto [new_x, new_y] = rotate_point(3, 4);
    cout << "Point (3,4) rotated: (" << new_x << ", " << new_y << ")\n";
    
    // Multiple return values from recursive functions
    function<tuple<int, int>(int)> fibonacci_pair = [&](int n) -> tuple<int, int> {
        if (n <= 1) return {n, 0};
        auto [fib_n_minus_1, fib_n_minus_2] = fibonacci_pair(n - 1);
        return {fib_n_minus_1 + fib_n_minus_2, fib_n_minus_1};
    };
    
    auto [fib_10, fib_9] = fibonacci_pair(10);
    cout << "Fibonacci(10) = " << fib_10 << ", Fibonacci(9) = " << fib_9 << "\n";
    
    return 0;
}

/*
Key Benefits:
1. Clean multiple value returns
2. Elegant unpacking of data structures
3. Simplified variable swapping
4. Better iteration over key-value pairs
5. Cleaner function signatures

Best Practices:
1. Use structured bindings (C++17) over tie when possible
2. Use std::ignore for unwanted values
3. Prefer meaningful variable names in structured bindings
4. Use const auto& for read-only access to avoid copying
5. Combine with algorithms for powerful data processing
*/
