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

const int MX=2e5+10;
int N;
int a[MX],b[MX];

vpi adj[MX];
int memo[MX];
bool vis[MX];

int solve(int i){
	vis[i]=1;
	if(memo[i]!=-1) return memo[i];

	int ans=0;
	for(auto j: adj[i])if(!vis[j.fi]) ans=max(ans,solve(j.fi)+j.se);
	return memo[i]=ans;
}

int32_t main(){
   boost;
   IO();


   memset(memo,-1,MX);
   memset(vis,0,MX);

   cin>>N;
   int ans=0;
   for(int i=0; i<N; i++) cin>>a[i],ans+=a[i];
   for(int i=0; i<N; i++) cin>>b[i];	

   for(int i=0; i<N; i++){
   	if(b[i]!=-1) adj[i].pb({b[i]-1,a[i]});
   }


   int mx=0;
   for(int i=0; i<N; i++) mx=max(mx,solve(i));

   ans+=mx;
   cout << ans << endl;


	

   return 0;
}

