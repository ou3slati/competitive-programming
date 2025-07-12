/*
 * Longest Increasing Subsequence (LIS) - O(n log n)
 * Time: O(n log n) | Space: O(n)
 * Uses patience sorting approach with binary search
 */

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll

class LIS {
private:
    vector<int> tails;      // tails[i] = smallest tail of LIS of length i+1
    vector<int> indices;    // indices[i] = index of tails[i] in original array
    vector<int> prev;       // prev[i] = previous element index in LIS ending at i
    
public:
    // Returns length of LIS
    int find_lis_length(const vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        
        tails.clear();
        indices.clear();
        prev.assign(n, -1);
        
        tails.push_back(arr[0]);
        indices.push_back(0);
        
        for (int i = 1; i < n; i++) {
            if (arr[i] < arr[indices[0]]) {
                // Replace first element
                tails[0] = arr[i];
                indices[0] = i;
            } else if (arr[i] > arr[indices.back()]) {
                // Extend LIS
                prev[i] = indices.back();
                tails.push_back(arr[i]);
                indices.push_back(i);
            } else {
                // Binary search for position to replace
                int pos = upper_bound(tails.begin(), tails.end(), arr[i]) - tails.begin();
                tails[pos] = arr[i];
                indices[pos] = i;
                if (pos > 0) prev[i] = indices[pos - 1];
            }
        }
        
        return tails.size();
    }
    
    // Returns the actual LIS sequence
    vector<int> get_lis_sequence(const vector<int>& arr) {
        find_lis_length(arr);
        
        vector<int> lis;
        int idx = indices.back();
        
        while (idx >= 0) {
            lis.push_back(arr[idx]);
            idx = prev[idx];
        }
        
        reverse(lis.begin(), lis.end());
        return lis;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> arr = {-7, 10, 9, 2, 3, 8, 8, 1, 2, 3, 4};
    
    LIS solver;
    
    cout << "LIS length: " << solver.find_lis_length(arr) << "\n";
    
    vector<int> lis = solver.get_lis_sequence(arr);
    cout << "LIS sequence: ";
    for (int x : lis) {
        cout << x << " ";
    }
    cout << "\n";
    
    return 0;
}
