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
   int N; cin>>N;
   map <str,str> mp;
   map <str,int> vis;
   string t[N];

   for (int i=0; i<N;i++){
      string s,ss; cin>>s>>ss;
      mp[s]=ss;
      vis[s]=0;
      t[i]=s;
   }
   vector<pair<string,string>> ans;

   for(int i=0; i<N; i++) if(vis[t[i]]==0){
      string s=t[i];
      string res=t[i];
      while(mp.count(s)){
         vis[s]=1;
         s=mp[s];
      }
      ans.pb({res,s});
   }
   cout << sz(ans) << endl;
   for (int i=0; i<sz(ans); i++) cout << ans[i].fi<< ' '<<ans[i].se << endl;

}

