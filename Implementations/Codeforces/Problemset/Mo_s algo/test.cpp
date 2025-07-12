#include <bits/stdc++.h>
#define PB push_back
#define sz(x) ((int)x.size())
using namespace std;
const int BLOCK = 316;
const int N = 100100;
vector<int> vc, g[N];
int col[N], l[N], r[N], nm[N], kol[N], ans[N], sum[N];
int tin[N], tout[N], n, q, kl[N];
 
void dfs(int v, int p){
    tin[v] = sz(vc);
    vc.PB(v);
    for (int u : g[v]){
        if (u == p) continue;
        dfs(u, v);
    }
    tout[v] = sz(vc) - 1;
}
 
bool cmp(int x, int y){
    int lx = l[x] / BLOCK;
    int ly = l[y] / BLOCK;
 
    if (lx == ly){
        if (lx & 1)
            return r[x] > r[y];
        else return r[x] < r[y];
    } else return lx < ly;
}
 
void add(int ps){
    int cur = col[vc[ps]];
    kol[cur]++;
    sum[kol[cur]]++;
}
 
void del(int ps){
    int cur = col[vc[ps]];
    sum[kol[cur]]--;
    kol[cur]--;
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    cin >> n >> q;
 
    for (int i = 0; i < n; i++)
        cin >> col[i];
 
    for (int i = 1; i < n; i++){
        int x, y; cin >> x >> y;
        x--; y--;
        g[x].PB(y);
        g[y].PB(x);
    }
 
    dfs(0, -1);
 
    for (int i = 0; i < q; i++){
        int v; cin >> v >> kl[i];
        v--;
        l[i] = tin[v];
        r[i] = tout[v];
        nm[i] = i;
    }
 
    sort(nm, nm + q, cmp);
 
    int lf = 0, rt = -1;
 
    for (int it = 0; it < q; it++){
        int i = nm[it];
 
        while (lf < l[i]) del(lf++);
        while (rt < r[i]) add(++rt);
        while (lf > l[i]) add(--lf);
        while (rt > r[i]) del(rt--);
 
        ans[i] = sum[kl[i]];
    }
 
    for (int i = 0; i < q; i++)
        cout << ans[i] << '\n';
 
    return 0;
}