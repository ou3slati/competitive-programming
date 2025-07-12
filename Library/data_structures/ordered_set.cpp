/*
 * Ordered Set using GNU PBDS
 * Time: O(log n) for all operations | Space: O(n)
 * Supports order statistics: find kth element, count elements < x
 */

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
#define int ll

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ordered_set<int> os;
    
    // Insert elements
    os.insert(1);
    os.insert(3);
    os.insert(5);
    os.insert(7);
    
    // order_of_key(x): number of elements < x
    cout << "Elements < 5: " << os.order_of_key(5) << "\n";
    
    // find_by_order(k): kth element (0-indexed)
    cout << "2nd element: " << *os.find_by_order(1) << "\n";
    
    // Standard set operations also work
    cout << "Size: " << os.size() << "\n";
    cout << "Contains 3: " << (os.find(3) != os.end()) << "\n";
    
    return 0;
}

/*
Key operations:
- os.order_of_key(x): count of elements strictly less than x
- os.find_by_order(k): iterator to kth smallest element (0-indexed)
- All standard set operations: insert, erase, find, size, etc.
*/
