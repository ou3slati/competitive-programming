/*
CF 662B - Applejack and Storages
https://codeforces.com/contest/1393/problem/B

Process queries on planks
n,q ≤ 1e5

Key: Track counts of each length
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    map<int,int> cnt;
    int pairs = 0, quads = 0;
    
    auto add = [&](int x) {
        int old = cnt[x];
        cnt[x]++;
        if(old % 2 == 1) pairs++;
        if(old % 4 == 3) quads++;
    };
    
    auto remove = [&](int x) {
        int old = cnt[x];
        cnt[x]--;
        if(old % 2 == 0) pairs--;
        if(old % 4 == 0) quads--;
    };
    
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        add(x);
    }
    
    int q;
    cin >> q;
    while(q--) {
        char op;
        int x;
        cin >> op >> x;
        
        if(op == '+') add(x);
        else remove(x);
        
        cout << (pairs >= 4 && quads >= 1 ? "YES\n" : "NO\n");
    }
    
    return 0;
}
