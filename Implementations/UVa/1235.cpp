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

int N;
vi p,rnk; int nbSets;

void reset(){
   p.resize(N); rnk.assign(N,0);
   for (int i=0; i<N; i++) p[i]=i;
   nbSets=N;
}

int findSet(int u){
   return p[u]==u? u: p[u]=findSet(p[u]);
}

void unionSet(int u, int v){
   int a=findSet(u),b=findSet(v);
   nbSets--;
   if(rnk[a]<rnk[b]) swap(a,b);
   if(rnk[a]==rnk[b]) rnk[a]++;
   p[b]=a;
}

int dist(int x, int y){
   int ans=0;
   for (int i=0; i<4; i++){
      ans+=min( abs(x%10-y%10), 10-abs(x%10-y%10) );
      x/=10; y/=10;
   }
   return ans;
}

int32_t main(){
   boost;
	int TC; cin>>TC;
	while(TC--){
      cin>>N;
      reset();
      int t[N];
      int res=INF;
      for(int i=0; i<N; i++){
         cin>>t[i];
         res=min(res,dist(0,t[i]));
      }

      vector<pair<int,pi>> vec;
      for (int i=0; i<N; i++) for (int j=i+1; j<N;j++)
         vec.pb({dist(t[i],t[j]),{i,j}});
      sort(all(vec));

      for (int i=0; i<sz(vec) && nbSets>1; i++){
         int u=vec[i].se.fi,v=vec[i].se.se,w=vec[i].fi;
         if(findSet(u)!=findSet(v)){
            unionSet(u,v);
            res+=w;
         }
      }
      cout << res << endl;
      //cout << endl << endl << endl << endl;
	}

   return 0;
}

