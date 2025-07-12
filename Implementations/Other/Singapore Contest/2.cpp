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
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int32_t main(){
   boost;
   int N,d; cin>>N>>d;
   vector <pair<int,pi>> vec;
   int a,b,c;
   for (int i=0; i<N; i++){
      cin>>a>>b>>c;
      vec.pb({a,{b,c}});
   }
   vec.pb({d,{INF,INF}});
   sort(all(vec));

   if(N==1){
      if(vec[0].se.se<vec[0].fi){cout << d << endl; return 0;}
   }

   //for (int i=0; i<sz(vec); i++) cout << vec[i].fi << ' ' <<vec[i].se.fi << endl;

   int f=vec[0].se.fi;
   int res=vec[0].fi;
   if(vec[0].se.se<res) f=0;

   vpi vis;
   vis.pb({vec[0].se.fi,vec[0].se.se});
   for (int i=0; i<sz(vec)-1; i++){
      if(vec[i+1].fi-vec[i].fi<=f) f-=vec[i+1].fi-vec[i].fi;
      else{
         res+=vec[i+1].fi-vec[i].fi-f;
         for (int j=0; j<sz(vis); j++) if(vis[j].se<res){res+=vis[j].fi; vis[j].fi=0;}
         f=0;
      }

      if(res>vec[i+1].se.se) continue;
      f+=vec[i+1].se.fi;
      vis.pb({vec[i+1].se.fi,vec[i+1].se.se});
      //cout << res << endl;
   }
   cout << res << endl;
   return 0;
}

