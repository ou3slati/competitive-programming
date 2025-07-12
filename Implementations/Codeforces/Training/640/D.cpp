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

int32_t main(){
   boost;
   int TC; cin>>TC;
   while(TC--){
      int N; cin>>N;
      int t[N];
      unordered_map <int,vi> mp;
      for(int i=0; i<N; i++){cin>>t[i]; mp[t[i]].pb(i);}


      int h[N+1]={0};
      h[0]=0;
      for(int i=1; i<=N; i++) h[i]=t[i-1]+h[i-1];

      bool vis[N]={false};
      for(int i=1; i<=N; i++) for(int j=i+1; j<=N; j++){
         int x=h[j]-h[i-1];
         if(mp.count(x)) for(auto it: mp[x]) vis[it]=true;
      }

      int ans=0;
      for(int i=0; i<N; i++) if(vis[i]) ans++;
      cout << ans << endl;
      //cout << endl;

   }


   return 0;
}

