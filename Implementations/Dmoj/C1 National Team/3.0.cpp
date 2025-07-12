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

int N,M;
vi v[101];
set <int> st;
int nb;
int ans;

void solve(int i){
   /*for (auto x:st) cout << x << ' ';
   cout << endl;*/
   if(i==N-1){
      ans=min(ans,nb-sz(st));
      return;
   }
   bool y=false;
   for (int j=0; j<sz(v[i]); j++)if(st.count(v[i][j])==0){
      st.insert(v[i][j]);
      solve(i+1);
      y=true;
      st.erase(v[i][j]);
   }
   if(y==false) solve(i+1);
}


int32_t main(){
   boost;
   ans=INF;
   cin >>N>>M;
   set <int> s;

   int x; cin>>x;
   nb=x;
   for (int i=0; i<x; i++){
      int y;cin>>y;
      s.insert(y);
   }


   for (int i=0; i<N-1; i++){
      cin>>x;
      for (int j=0; j<x; j++){
         int y; cin>>y;
         if(s.count(y)==1) v[i].pb(y);
      }
   }
   /*for (int i=0; i<N-1; i++){
      for (int j=0; j<sz(v[i]); j++) cout << v[i][j] << ' ';
   cout << endl;
   }*/

   solve(0);
   cout << ans << endl;

}

