/*
 * Boyer-Moore Majority Element Algorithm
 * Time: O(n) | Space: O(1)
 * Finds element appearing more than n/2 times using voting approach
 */

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll

class MajorityElement {
public:
    // Returns majority element if exists, otherwise returns -1
    int find_majority(const vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return -1;
        
        // Phase 1: Find candidate using Boyer-Moore voting
        int candidate = arr[0];
        int count = 1;
        
        for (int i = 1; i < n; i++) {
            if (arr[i] == candidate) {
                count++;
            } else {
                count--;
                if (count == 0) {
                    candidate = arr[i];
                    count = 1;
                }
            }
        }
        
        // Phase 2: Verify candidate is actually majority
        count = 0;
        for (int x : arr) {
            if (x == candidate) count++;
        }
        
        return (count > n / 2) ? candidate : -1;
    }
    
    // Returns all elements appearing more than n/k times
    vector<int> find_majority_k(const vector<int>& arr, int k) {
        int n = arr.size();
        if (n == 0 || k <= 1) return {};
        
        // At most k-1 elements can appear > n/k times
        map<int, int> candidates;
        
        for (int x : arr) {
            if (candidates.count(x)) {
                candidates[x]++;
            } else if (candidates.size() < k - 1) {
                candidates[x] = 1;
            } else {
                // Decrease all counts
                vector<int> to_remove;
                for (auto& [val, cnt] : candidates) {
                    cnt--;
                    if (cnt == 0) to_remove.push_back(val);
                }
                for (int val : to_remove) {
                    candidates.erase(val);
                }
            }
        }
        
        // Verify candidates
        vector<int> result;
        for (auto& [candidate, _] : candidates) {
            int count = 0;
            for (int x : arr) {
                if (x == candidate) count++;
            }
            if (count > n / k) {
                result.push_back(candidate);
            }
        }
        
        return result;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    MajorityElement solver;
    
    int majority = solver.find_majority(arr);
    if (majority != -1) {
        cout << "Majority element: " << majority << "\n";
    } else {
        cout << "No majority element\n";
    }
    
    // Find elements appearing more than n/3 times
    vector<int> majority_3 = solver.find_majority_k(arr, 3);
    cout << "Elements appearing > n/3 times: ";
    for (int x : majority_3) {
        cout << x << " ";
    }
    cout << "\n";
    
    return 0;
}
