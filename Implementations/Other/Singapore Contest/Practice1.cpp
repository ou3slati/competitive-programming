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
   int N;  cin>>N;
   int t[N];
   vi r;
   for (int i=0; i<N; i++) {
      int x; cin>>x;
      t[i]=x;
      r.pb(x);
   }

   sort(all(r));
   vi l;

   int res=0;
   for (int i=0; i<N; i++){
      auto itr=lower_bound(all(r),t[i])-r.begin();
      r.erase(itr+r.begin());
      auto it=lower_bound(all(l),t[i])-l.begin();
      res+=(int)itr*(int)it;

      l.insert(l.begin()+it,t[i]);
      /*for (int i=0; i<sz(r); i++) cout << r[i] << ' ';
      cout << endl;
      for (int i=0; i<sz(l); i++) cout << l[i] << ' ';
      cout << endl;
      cout << endl;*/
   }
	cout << res << endl;

   return 0;
}

