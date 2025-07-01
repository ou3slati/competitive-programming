/*
CF 672C2 - Pokémon Army (hard version)
https://codeforces.com/contest/1420/problem/C2

Find maximum alternating subsequence value with updates
n ≤ 3e5, q ≤ 3e5, a[i] ≤ 1e9

Key insights:
1. Same as C1 but with position swaps
2. Use segment tree to handle updates efficiently
3. Each node stores 4 values: pp, pm, mp, mm
   - pp: plus followed by plus
   - pm: plus followed by minus
   - mp: minus followed by plus
   - mm: minus followed by minus
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long pp, pm, mp, mm;
    Node(long long val = 0) {
        pp = val;    // Value if used as positive
        mm = -val;   // Value if used as negative
        pm = mp = 0; // No alternation within single element
    }
};

class SegmentTree {
    vector<Node> st;
    vector<long long> arr;
    int n;
    
    Node combine(const Node& a, const Node& b) {
        Node res;
        // Best way to combine subsequences
        res.pp = max(a.pp + b.mp, a.pm + b.pp);
        res.pm = max(a.pp + b.mm, a.pm + b.pm);
        res.mp = max(a.mp + b.mp, a.mm + b.pp);
        res.mm = max(a.mp + b.mm, a.mm + b.pm);
        return res;
    }
    
    void build(int pos, int l, int r) {
        if(l == r) {
            st[pos] = Node(arr[l]);
            return;
        }
        int mid = (l + r) / 2;
        build(2*pos, l, mid);
        build(2*pos+1, mid+1, r);
        st[pos] = combine(st[2*pos], st[2*pos+1]);
    }
    
    void update(int pos, int l, int r, int idx, long long val) {
        if(l == r) {
            st[pos] = Node(val);
            return;
        }
        int mid = (l + r) / 2;
        if(idx <= mid) update(2*pos, l, mid, idx, val);
        else update(2*pos+1, mid+1, r, idx, val);
        st[pos] = combine(st[2*pos], st[2*pos+1]);
    }
    
public:
    SegmentTree(const vector<long long>& a) {
        arr = a;
        n = a.size();
        st.resize(4*n);
        build(1, 0, n-1);
    }
    
    void update(int idx, long long val) {
        arr[idx] = val;
        update(1, 0, n-1, idx, val);
    }
    
    long long getMax() {
        return max(st[1].pp, st[1].pm);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q;
        vector<long long> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        SegmentTree st(a);
        cout << st.getMax() << '\n';
        
        while(q--) {
            int l, r;
            cin >> l >> r;
            l--; r--;  // Convert to 0-based
            swap(a[l], a[r]);
            st.update(l, a[l]);
            st.update(r, a[r]);
            cout << st.getMax() << '\n';
        }
    }
    
    return 0;
}
