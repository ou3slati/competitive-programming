//Never stop trying
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
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0}; //right left down up

void IO(){
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
#endif 
}

const int MX=1e5+10;
int N,M;

int p[MX],h[MX];
vi adj[MX];

int cnt[MX];
int pr[MX];
int happy[MX];
int sad[MX];

void dfs(int u, int parent){
	int ans=p[u];
	pr[u]=parent;
	for(auto v: adj[u]) if(v!=parent){dfs(v,u);ans+=cnt[v];}
	cnt[u]=ans;
}

int32_t main(){
   boost;
   IO();

   int TC; cin>>TC;
   while(TC--){
   	cin>>N>>M;

   	for(int i=0; i<N; i++) cin>>p[i],adj[i].clear();
   	for(int i=0; i<N; i++) cin>>h[i];

   	bool y=true;
   	//for(int i=0; i<N; i++) if((p[i]-h[i])%2!=0){ y=false; break;}
   	
   	for(int i=0; i<N-1; i++){
   		int u,v; cin>>u>>v;
   		u--; v--;
   		adj[u].pb(v); adj[v].pb(u);
   	}

   	dfs(0,0);

   	for(int i=0; i<N; i++) happy[i]=(cnt[i]+h[i])/2;
   	for(int i=0; i<N; i++) if(!((h[i]+cnt[i])/2>=0 && (h[i]+cnt[i])%2==0)) y=false;

   	//for(int i=0; i<N; i++) cout << cnt[i] <<  ' '; cout << endl;
   	//for(int i=0; i<N; i++) cout << pr[i] <<  ' '; cout << endl;

   	
   	for(int i=0; i<N; i++){
   		if(!(abs(h[i])<=cnt[i])) y=false;
   		int nb=0;
   		for(auto v: adj[i]) if(v!=pr[i]) nb+=happy[v];
   		if(!(happy[i]>=nb)) y=false;
   		//if(!y) cout << i << endl;
   	}

   	if(y) cout << "YES" << endl;
   	else cout << "NO" << endl;


   }
	

   return 0;
}

