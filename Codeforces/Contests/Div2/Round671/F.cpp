/*
CF 671F - Rain of Fire
https://codeforces.com/contest/1419/problem/F

Find minimum time to connect all points
n ≤ 300, coordinates ≤ 1e9

Key insights:
1. Binary search on time
2. Points connect if they share x or y coordinate
3. Connection speed depends on distance
4. Use graph connectivity to check validity
*/

#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent, rank;
public:
    DisjointSet(int n) : parent(n), rank(n, 0) {
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    
    int find(int x) {
        if(parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if(px == py) return;
        if(rank[px] < rank[py]) swap(px, py);
        parent[py] = px;
        if(rank[px] == rank[py]) rank[px]++;
    }
};

bool check_connectivity(int n, vector<pair<long long, long long>>& points, long long time) {
    DisjointSet ds(n);
    
    // Connect points that can reach each other within given time
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(points[i].first == points[j].first || points[i].second == points[j].second) {
                long long dist = min(
                    abs(points[i].first - points[j].first),
                    abs(points[i].second - points[j].second)
                );
                if(dist <= time) {
                    ds.unite(i, j);
                }
            }
        }
    }
    
    // Check if all points are connected
    int root = ds.find(0);
    for(int i = 1; i < n; i++) {
        if(ds.find(i) != root) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<pair<long long, long long>> points(n);
    
    for(int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }
    
    // Binary search on time
    long long left = 0, right = 2e9;
    long long ans = -1;
    
    while(left <= right) {
        long long mid = left + (right - left) / 2;
        if(check_connectivity(n, points, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << ans << '\n';
    
    return 0;
}
