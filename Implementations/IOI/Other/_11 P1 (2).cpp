#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
//#define int ll
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

//0: normal - 1: taken
const int MXN=150000+500;
int V,E,D;
vpi g[MXN];
bool vis[MXN][2]={false};
map <pi,pi> memo;
int stp=0;

pi solve (int u, int s){
   if(!stp && u==D){
      return {0,s};
   }
   if(stp && u==D) stp=false;

   if(vis[u][s]) return {-1*INF,-1*INF};
   vis[u][s]=true;


   if(memo.count({u,s})) return memo[{u,s}];
   pi res;
   if(g[u].size()==1){
      int des=g[u][0].se;
      if(g[des][0].se==u){
         pi x=solve(des,1);
         res.fi=x.fi+1; res.se=x.se;
      }
      else{
         pi x=solve(des,0);
         res.fi=x.fi+1; res.se=x.se;
      }
   }
   else if(s==0){
      int des=g[u][0].se;
      if(g[des][0].se==u){
         pi x=solve(des,1);
         res.fi=x.fi+1; res.se=x.se;
      }
      else{
         pi x=solve(des,0);
         res.fi=x.fi+1; res.se=x.se;
      }
   }
   else if(s==1){
      int des=g[u][1].se;
      if(g[des][0].se==u){
         pi x=solve(des,1);
         res.fi=x.fi+1; res.se=x.se;
      }
      else{
         pi x=solve(des,0);
         res.fi=x.fi+1; res.se=x.se;
      }
   }
   return memo[{u,s}]=res;
}

void count_routes(int N, int M, int P, int R[][2] ,int Q, int G[]){
   //memset(memo,{-1,-1},sizeof(memo));
   V=N; E=M; D=P;
   for (int i=0; i<E; i++){
      int a=R[i][0],b=R[i][1];
      g[a].pb({i,b});
      g[b].pb({i,a});
   }
   for(int i=0; i<V; i++) sort(all(g[i]));

   vpi vec;
   for(int i=0; i<V; i++){
      if(i==D) stp=true;
      memset(vis,false,sizeof(vis));
      if(i!=D) vec.pb(solve(i,0));
      if(i==D) vec.pb(solve(i,0));
      if(i==D){memset(vis,false,sizeof(vis)); stp=true; pi x=solve(i,1);}
   }

   //cout << memo[{D,0}].fi <<  ' '<<memo[{D,1}].fi << endl;
   int ans;
   for (int q=0; q<Q; q++){
      int x=G[q];
      ans=0;
      for (int i=0; i<sz(vec); i++) if(vec[i].fi<=x && vec[i].fi>0 && memo[{D,vec[i].se}].fi>0 &&(x-vec[i].fi)%(memo[{D,vec[i].se}].fi)==0)
         ans++;
      answer(ans);
      //cout << ans  << endl;
   }

   //for (int i=0; i<sz(vec); i++) cout << vec[i].fi << ' ' << vec[i].se << endl;


}

/*int32_t main(){
   boost;
   int N,M,P,Q;
   cin>>N>>M>>P;
   for (int i=0; i<M; i++) cin>>R[i][0]>>R[i][1];
   cin>>Q;
   for (int q=0; q<Q; q++) cin>>G[q];
   count_routes(N,M,P,Q);

   return 0;
}*/

/*
6 6 0

1 2
0 1
0 3
3 4
4 5
1 5

1
3
*/
