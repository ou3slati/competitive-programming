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

const int MOD = 1e9+7; //1000000007
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int32_t main(){
   boost;
   int N,M; cin>>N>>M;
   int t[M];
   vpi vec;
   for (int i=0; i<M; i++){
      int x;cin>>x;
      t[i]=x;
      vec.pb({x,i+1});
   }
   sort(all(vec));
   int i=N;
   vpi res;
   for (int j=0; j<sz(vec); j++){
      int f=vec[j].fi, s=vec[j].se;
      if(f<=i){
         i-=f;
         res.pb({s,i+1});
      }
      else if(f>i){
         i=0;
         res.pb({vec[j].se,i+1});
      }
   }
   sort(all(res));
   if(i!=0){cout << -1 << endl; return 0;}

   int c[N]={0};
   for (int i=0; i<sz(vec); i++){
      int p=res[i].se;
      for (int j=p-1; j<p+t[i]; j++) c[j]=i+1;
   }

   set <int> s;
   for (int i=0; i<N;i++) s.insert(c[i]);
   for (int i=1; i<=M; i++) if(s.count(i)==0)
      {cout << -1 << endl; return 0;}

   for (int i=0; i<sz(res); i++) cout << res[i].se << ' ';
   cout << endl;


}

