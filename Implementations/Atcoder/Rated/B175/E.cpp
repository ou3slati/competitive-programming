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

int R,C,K;
int memo[3001][3001][4];
int g[3001][3001];


int solve(int x, int y, int z){
	if(x==R && y==C) return 0;
	if(memo[x][y][z]!=-1) return memo[x][y][z];
	int ans=0;
	if(x<R) ans=max(ans,solve(x+1,y,0));
	if(x<R && g[x+1][y]!=-1) ans=max(ans,solve(x+1,y,1)+g[x+1][y]);
	if(y<C) ans=max(ans,solve(x,y+1,z));
	if(y<C && z<3 && g[x][y+1]!=-1) ans=max(ans,solve(x,y+1,z+1)+g[x][y+1]);
	return memo[x][y][z]=ans;
}

int32_t main(){
   boost;
   IO();

   memset(memo,-1,sizeof(memo)); 
   cin>>R>>C>>K;
   for(int i=1; i<=R; i++) for(int j=1; j<=C; j++) g[i][j]=-1;
   for(int i=1; i<=K; i++){
   	int x,y,v; cin>>x>>y>>v;
   	g[x][y]=v;
   }

   int ans=0;
   ans=max(ans,solve(1,1,0));
   if(g[1][1]!=-1) ans=max(ans,solve(1,1,1)+g[1][1]);
   cout << ans << endl;


   return 0;
}

