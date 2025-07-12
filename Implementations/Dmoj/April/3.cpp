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
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ld> vd;
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
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

const int MXN=2001;
int N,K;
int v[MXN];
set <int> adj[MXN];

vi p;

void reset(){
   p.assign(N+1,0); for (int i=1; i<=N; i++) p[i]=i;
}

int findSet(int u){
   return p[u]==u? u: p[u]=findSet(p[u]);
}


void unionSet(int u, int v){
   int a=findSet(u),b=findSet(v);
   if(a==b) return;
   p[b]=a;
}


bool isSame(int u , int v){
   return findSet(u)==findSet(v);
}

int32_t main(){
   boost;
   cin>>N>>K;
	for(int i=0; i<N; i++) cin>>v[i];
	for(int i=0; i<N-1; i++){
      int u,v; cin>>u>>v;
      adj[u].insert(v); adj[v].insert(u);
	}

   vi res;
	for(int i=1; i<(1<<N); i++){
      reset();
      vi vec;
      for(int idx=0; idx<N; idx++) if((i&(1<<(idx)))) vec.pb(idx);

      int s=0;
      for(int j=0; j<sz(vec); j++) s+=v[vec[j]];
      if(s<K||s>2*K) continue;

      bool yes=true;
      for(int j=0; j<sz(vec); j++){
         int node=vec[j];
         for(auto x: adj[node+1]) if(find(all(vec),x-1)!=vec.end()) unionSet(x,j+1);
      }

      for(int i=1; i<sz(vec); i++) if(!isSame(vec[i]+1,vec[i-1]+1)){yes=false; break;}

      if(yes){res.assign(all(vec)); break;}
	}

	if(res.empty()) cout << -1 << endl;
	else{
      cout << sz(res) << endl;
      for(int i=0; i<sz(res); i++) cout << res[i]+1 << ' ';
      cout << endl;
	}

   return 0;
}

