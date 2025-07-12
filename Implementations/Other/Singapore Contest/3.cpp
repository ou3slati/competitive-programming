#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
typedef double db;
typedef long double ld;

typedef pair<int,int> pi;
#define mp make_pair
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<db> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;

#define pb push_back
#define eb emplace_back
#define pf push_front

#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)

const int MOD = 1e9+7; //998244353
const ll INF = 9999999;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

vector<vpi> gr;
int n;
int dist[15000];
int vis[15000];
int a[15000];
int k;

int mn()
{

    priority_queue<pi, vector<pi>, greater<pi> > q;

    int ans = INF;

    for (int i = 1; i <= n; i++) {
        if (!a[i])
            continue;
        for (int j = 1; j <= n; j++) {
            dist[j] = INF;
            vis[j] = 0;
        }
        dist[i] = 0;

        while (!q.empty())
            q.pop();

        q.push({ 0, i });

        int good = 0;

        while (!q.empty()) {
            int v = q.top().second;

            q.pop();
            if (vis[v])
                continue;
            vis[v] = 1;
            good += a[v];
            if (dist[v] > ans)
                break;
            if (good == 2 and a[v]) {
                ans = min(ans, dist[v]);
                break;
            }
            for (int j = 0; j < gr[v].size(); j++) {
                int to = gr[v][j].first;
                int weight = gr[v][j].second;
                if (dist[v] + weight < dist[to]) {
                    dist[to] = dist[v] + weight;
                    q.push({ dist[to], to });
                }
            }
        }
    }

    return ans;
}

int32_t main(){
   boost;
   gr.resize(10001);
   memset(a,0,sizeof(a));
   int V,E,x; cin>>V>>E>>x;
   n=V; k=x;
   int y=0;
   for (int i=0; i<E; i++){
      int u,v,w; cin>>u>>v>>w;

      if(u==1&&v==2){continue;}
      if(v==1&&u==2) {continue;}

      gr[u].pb({v,w});
      gr[v].pb({u,w});

   }
   for (int i=0; i<x; i++){
      int z; cin>>z;
      a[z]=1;
   }

   cout << 1+mn() << endl;



   return 0;
}

