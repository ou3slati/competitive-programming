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

int modpow(int x){
   if(x==0) return 1;
   int l=modpow(x/2);
   l=(l*l)%MOD;
   if(x%2==1) l=(l*2)%MOD;
   return l;
}

int32_t main(){
   boost;
   int n,m; cin>>n>>m;
   string s; cin>>s;
   set <pi> st;
   for (int i=0; i<n; i++){
      if(s[i]=='0') continue;
      int j=i;
      while(s[j]=='1') j++; j--;
      st.insert({i+1,j+1});
   }
   //for (auto x: st) cout << x.fi << ' '<<x.se << endl;
   while(m--){
      int l,r; cin>>l>>r;
      st.insert({l,r});
      vpi vect;
      for (auto x: st){
         vect.pb({x.fi,x.se});
      }
      vpi vec;
      for (int i=0;i<sz(vect);i++){
         int j=i;
         while(j<sz(vect)&& vect[j].fi<=vect[i].se){
            vect[i].se=max(vect[i].se,vect[j].se); j++;
         }
         vec.pb({vect[i].fi,vect[i].se});
         i=j-1;

      }
      //for (int i=0; i<sz(vec); i++) cout << vec[i].fi << ' ' << vec[i].se << endl;
      //cout << endl;
      int res=0;
      for (int i=0; i<sz(vec); i++){
         int p=n-vec[i].se, k=n-vec[i].fi;
         res=(res+(modpow(p)*(modpow(k-p+1)-1))%MOD)%MOD;
      }
      cout << res << endl;
   }

}

