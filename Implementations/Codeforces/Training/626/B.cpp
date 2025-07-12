#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
typedef double db;
typedef long double ldb;

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

const int MOD = 1e9+7;
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

vpi divv;

void solve(int K){
   for (int i=1; i*i<=K; i++) if(K%i==0) divv.pb({i,K/i});
   return;
}

int32_t main(){
   boost;
   int N,M, K; cin>>N>>M>>K;

   solve(K);

   vi vec, vecc;
   int nb=0;
   for (int i=0; i<N; i++){
      int x; cin >>x; if(x==1) nb++;
      else if(nb!=0){vec.pb(nb); nb=0;}
      if(i==N-1 && nb!=0) vec.pb(nb);
   }

   nb=0;
   for (int i=0; i<M; i++){
      int x; cin >>x; if(x==1) nb++;
      else if(nb!=0){vecc.pb(nb); nb=0;}
      if(i==M-1 && nb!=0) vecc.pb(nb);
   }

   sort(all(vec));  sort(all(vecc));
   int res=0;
   for (int i=0; i<sz(divv); i++){
      int f=divv[i].fi;
      int s=divv[i].se;

      auto itt=lower_bound(all(vec), f)-vec.begin();
      auto it=lower_bound(all(vecc), s)-vecc.begin();

      int n=0,m=0;
      for (int j=itt; j<sz(vec); j++) n+=vec[j]-f+1;
      for (int j=it; j<sz(vecc); j++) m+=vecc[j]-s+1;
      res+=n*m;

      if(f!=s){
      itt=lower_bound(all(vec), s)-vec.begin();
      it=lower_bound(all(vecc), f)-vecc.begin();

      n=0;m=0;
      for (int j=itt; j<sz(vec); j++) n+=vec[j]-s+1;
      for (int j=it; j<sz(vecc); j++) m+=vecc[j]-f+1;
      res+=n*m;
      }

   }

   cout << res << endl;
   return 0;

}


