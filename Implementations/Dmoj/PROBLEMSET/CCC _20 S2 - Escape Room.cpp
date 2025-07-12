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

const int MXN=1002;
int g[MXN][MXN];
bool res=false;
vpi adj[MXN*MXN];
bool vis[MXN][MXN]={false};

void solve(int x, int y){
   vis[x][y]=true;
   //cout << x << ' ' << y << endl;
   if(x==1&&y==1){
      res=true;
      return;
   }
   int val=x*y;
   for(auto it: adj[val]){
      if(!vis[it.fi][it.se]) solve(it.fi,it.se);
   }
}

int32_t main(){
   boost;
   int N,M; cin>>M>>N;
   for (int i=1; i<=M; i++) for (int j=1;j<=N;j++){
      int x; cin>>x; g[i][j]=x;
      adj[x].pb({i,j});
   }
   solve(M,N);
   if(res) cout <<"yes" << endl;
   else cout << "no" << endl;


   return 0;
}

