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

const int MX=505;
int N,M,K;
int g[MX][MX],st[MX][MX];
bool vis[MX][MX]; 
set <pi> s;
int D;

int32_t main(){
   boost;
   IO();

   cin>>N>>M>>K;

   for(int i=0; i<N; i++) for(int j=0; j<M; j++) cin>>g[i][j];
   for(int i=0; i<N; i++) for(int j=0; j<M; j++) cin>>st[i][j];

   int l=1,r=N*M;
	int res[N][M];
	for(int i=0; i<N; i++) for(int j=0; j<M; j++) res[i][j]=INF;
	while(l<=r){ // binary search over D
		D=(l+r)/2;
		for(int i=0; i<N; i++) for(int j=0; j<M; j++) vis[i][j]=false;
		for(int i=0; i<N; i++) for(int j=0; j<M; j++) if(!vis[i][j] && st[i][j]){
			dfs(i,j);
			if(sz(s)>=T){
				for(auto x: s) res[x.fi][x.se]=D;
			}
			s.clear();
		}
	}

   return 0;
}

