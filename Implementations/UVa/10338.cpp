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
   int f[21];
   f[1]=1;
   for (int i=2; i<=20; i++) f[i]=i*f[i-1];

   int TC; cin>>TC;
   int t=0;

   while(TC--){
      string s; cin>>s;
      int n=sz(s);

      multiset <char> st; set <char> ss;
      for (int i=0; i<sz(s); i++){ st.insert(s[i]); ss.insert(s[i]);}
      int rep=1;
      for (auto x:ss) rep*=f[st.count(x)];
      cout <<"Data set "<<++t<<": " <<f[n]/rep << endl;
   }

}

