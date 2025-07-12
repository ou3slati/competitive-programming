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

int32_t main(){
   boost;
   int N; cin>>N;
   string t[N];
   for(int i=0; i<N; i++) cin>>t[i];

   vector<pair<str,int>> dec,inc;
   vs dec2,inc2;

   for(int i=0; i<N; i++){
      str s=t[i];

      sort(all(s));
      inc.pb({s,i});
      inc2.pb(s);

      sort(s.rbegin(),s.rend());
      dec.pb({s,i});
      dec2.pb(s);
   }

   sort(all(inc)); sort(all(inc2));
   sort(all(dec)); sort(all(dec2));

   /*for(auto x: inc)  cout << x.fi <<  ' ';
   cout << endl;
   for(auto x: dec) cout << x.fi << ' ';*/

   int res[N][2];
   for(int i=0; i<N; i++){
      int idx=dec[i].se;
      str x=dec[i].fi;
      auto it=upper_bound(all(inc2),x)-inc2.begin();
      //cout << it << endl;
      res[idx][1]=it;
   }

   for(int i=0; i<N; i++){
      int idx=inc[i].se;
      str x=inc[i].fi;
      auto it=lower_bound(all(dec2),x)-dec2.begin();
      it++;
      res[idx][0]=it;
   }

   for(int i=0; i<N; i++) cout << res[i][0] << ' ' << res[i][1] << endl;



   return 0;
}

