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

int N;
vi adj[101];
vi ans;
vi num, low,p;
int counter,root;

void solve(int u){
   low[u]=num[u]=counter++;
   for(auto x:adj[u]){
      if(num[x]==-1){
         if(u==1) root++;
         p[x]=u;
         solve(x);
         if(low[x]>=num[u]) ans[u]=1;
         low[u]=min(low[u],low[x]);
      }
      else if(p[u]!=x){
         low[u]=min(low[u],num[x]);
      }
   }
}

int32_t main(){
   boost;
   cin>>N; cin.ignore();
   while(N){
      for (int i=0; i<101; i++) adj[i].clear();
      ans.assign(N+1,0); num.assign(N+1,-1); low.assign(N+1,-1); p.assign(N+1,-1);

      string s; getline(cin,s);
      while(s!="0"){
         int i=0, x=0;
         while(s[i]>='0' && s[i]<='9'){x*=10; x+=s[i]-'0';i++;}
         int nb;
         for (int j=i+1; j<sz(s); j++){
            nb=0;
            while(j<sz(s) && s[j]>='0' && s[j]<='9'){nb*=10; nb+=s[j]-'0'; j++;}
            adj[x].pb(nb); adj[nb].pb(x);
         }
         getline(cin,s);
      }

      /*for (int i=1; i<=N; i++){
         for(auto x: adj[i]) cout << x <<' ';
         cout << endl;
      }*/

      counter=0; root=0;
      solve(1);
      if(root>1) ans[1]=1;
      else ans[1]=0;

      int res=0;
      for(int i=1; i<=N; i++) if(ans[i]) res++;
      cout << res << endl;
      //cout << endl;
      cin>>N;
   }
   return 0;
}

