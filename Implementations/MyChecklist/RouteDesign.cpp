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

/*void IO(){
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
#endif 
}*/

void IO(){
#ifndef ONLINE_JUDGE 
    freopen("route.in", "r", stdin); 
    freopen("route.out", "w", stdout); 
#endif 
}


const int MX=4e4+10;

int N,M,RR;
int v[MX],vv[MX];
vpi adj[MX][2];

pi R[100005];
int memo[100005][2][2];

int solve(int i, int side, int d){
	if(memo[i][side][d]!=-1) return memo[i][side][d];

	int ans=0;

	int a=R[i].fi,b=R[i].se;
	int u=a; if(side==1) u=b;

	if(d==1){
		for(int idx=sz(adj[u][side])-1; idx>=0; idx--){
			pi ve=adj[u][side][idx];
			if(side==0){
				if(ve.fi>b) ans=max(ans,solve(ve.se,1,d)+vv[ve.fi]);
				else break;
			}
			else{
				if(ve.fi>a) ans=max(ans,solve(ve.se,0,d)+v[ve.fi]);
				else break;
			}
			
		}	
	}
	else{
		for(int idx=0; idx<sz(adj[u][side]); idx++){
			pi ve=adj[u][side][idx];
			
			if(side==0){ 
				if(ve.fi<b) ans=max(ans,solve(ve.se,1,d)+vv[ve.fi]);
				else break;
			}
			else{
				if(ve.fi<a) ans=max(ans,solve(ve.se,0,d)+v[ve.fi]);
				else break;
			}
		}
	}

	return memo[i][side][d]=ans;
}

int32_t main(){
   boost;
   IO();

   for(int i=0; i<100001; i++) for(int j=0; j<2; j++) memo[i][j][0]=memo[i][j][1]=-1;

   cin>>N>>M>>RR;
   for(int i=0; i<N; i++) cin>>v[i];
   for(int i=0; i<M; i++) cin>>vv[i];

   if(RR==0){
   	int x=0;
   	for(int i=0; i<N; i++) x=max(x,v[i]);
   	for(int i=0; i<M; i++) x=max(x,vv[i]);
   	cout << x << endl;
   	return 0;
   }

   for(int i=1; i<=RR; i++){
   	int x,y; cin>>x>>y; x--; y--;
   	R[i]={x,y};
   	adj[x][0].pb({y,i});
   	adj[y][1].pb({x,i});
   }

   for(int i=0; i<N; i++) sort(all(adj[i][0]));
   for(int i=0; i<M; i++) sort(all(adj[i][1]));

   int ans=0;

   for(int i=1; i<=RR; i++){
   	int x=v[R[i].fi]+vv[R[i].se];
   	ans=max(ans,solve(i,0,0)+x);
   	ans=max(ans,solve(i,0,1)+x);
   	ans=max(ans,solve(i,1,0)+x);
   	ans=max(ans,solve(i,1,1)+x);
   }

   cout << ans << endl;

   return 0;
}

