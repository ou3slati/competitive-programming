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

int N,Q;
int t[500001];

int solve(int i){
   return t[i];
}

int32_t main(){
   boost;
   cin>>N>>Q;
   t[N-1]=1;  int i=N-2;
   while(i>=0){
      t[i]=(t[i+1]*2)%MOD;
      i--;
   }
   /*for (int i=0; i<N; i++) cout << t[i] << ' ';
   cout << endl;*/

   string st; cin>>st;
   set <int> s; for (int i=0; i<N; i++) s.insert(i);
   int res=0;
   for (int i=0; i<N; i++){
      if(st[i]=='1'){
         s.erase(i);
         res=(res+solve(i))%MOD;
      }
      //cout << res << endl;
   }


   while(Q--){
      int l,r; cin>>l>>r;
      l--; r--;
      vi vec;
      for(auto it=s.lower_bound(l); it!=s.end() && *it<=r; it++){
         res=(res+solve(*it))%MOD;
         vec.pb(*it);
      }
      for(auto x: vec) s.erase(x);
      cout << res << endl;
   }


   return 0;
}

