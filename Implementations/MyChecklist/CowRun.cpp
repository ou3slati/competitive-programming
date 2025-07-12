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
    freopen("cowrun.in", "r", stdin); 
    freopen("cowrun.out", "w", stdout); 
#endif 
}

const int MX=1005;
int N;
vi pos;
int memo[MX][MX][2];

int solve(int l, int r, int s){
	//cout << l << ' ' << r << endl;
	if(l==0 && r==N-1) return 0;

	if(memo[l][r][s]!=-1) return memo[l][r][s];
	int ans=INF;
	int vis=r-l+1;
	if(s==0){
		if(l) ans=min(ans,solve(l-1,r,0)+(N-vis)*(pos[l]-pos[l-1]));
		if(r<N-1) ans=min(ans,solve(l,r+1,1)+(N-vis)*(pos[r+1]-pos[l]));
	}
	else{
		if(l) ans=min(ans,solve(l-1,r,0)+(N-vis)*(pos[r]-pos[l-1]));
		if(r<N-1) ans=min(ans,solve(l,r+1,1)+(N-vis)*(pos[r+1]-pos[r]));
	}

	return memo[l][r][s]=ans;

}


int32_t main(){
   boost;
   IO();

   memset(memo,-1,sizeof(memo));

   cin>>N; pos.resize(N);
   for(int i=0; i<N; i++) cin>>pos[i];
   sort(all(pos));
   
   auto it=lower_bound(pos.begin(),pos.begin()+N,0)-pos.begin();

   if(it!=N && pos[it]==0) cout << solve(it,it,0) << endl;
   else{
   	int ans=INF;
   	if(it!=N) ans=solve(it,it,0)+N*pos[it];
   	if(it!=0) ans=min(ans,solve(it-1,it-1,0)+N*abs(pos[it-1]));
   	cout << ans << endl;
   }
	

   return 0;
}

