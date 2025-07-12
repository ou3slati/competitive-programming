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

vi adj[100];
int match[101];
bool vis[101];

bool bpm(int i){
   for (int j=0; j<sz(adj[i]); j++){
      if(vis[adj[i][j]]) continue;
      vis[adj[i][j]]=true;
      if(match[adj[i][j]]==-1 || bpm(match[adj[i][j]])){
         match[adj[i][j]]=i;
         return true;
      }
   }
   return false;
}

int32_t main(){
   boost;
   int N,M; cin>>N>>M;
   set <int> s;
   int x; cin>>x;
   for (int i=0; i<x; i++){
      int y; cin>>y;
      s.insert(y);
   }

   for (int i=2; i<=N; i++){
      cin>>x;
      for (int j=0; j<x; j++){
         int y; cin>>y;
         if(s.count(y)) adj[y].pb(i);
      }
   }
   /*for (int i=1; i<=M; i++){
      for (int j=0; j<sz(adj[i]); j++)cout << adj[i][j] << ' ';
      cout << endl;
   }*/

	memset(match,-1,sizeof(match));
	int res=0;
	for (int i=1; i<=M; i++) if(s.count(i)){
      memset(vis,false,sizeof(vis));
      if(bpm(i)) res++;
	}
   cout << sz(s)-res << endl;

   return 0;
}

