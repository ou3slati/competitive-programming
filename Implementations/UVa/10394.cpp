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

const int mxn=2*1000*10000+1;
bitset<mxn> sv;
vi p;

void sieve(){
   for (int i=2; i<mxn; i++) if(sv[i]){
      p.pb(i);
      for (int j=i*i; j<mxn; j+=i) sv[j]=0;
   }
}

int32_t main(){
   boost;
   sv.set(); sieve();
   vpi res;
   for (int i=1; i<sz(p); i++) if(p[i]-p[i-1]==2) res.pb({p[i-1],p[i]});
   int s; cin>>s;
   while(!cin.fail()){
      cout <<'('<<res[s-1].fi << ", " <<res[s-1].se <<')'<< endl;
      cin>>s;
   }

}

