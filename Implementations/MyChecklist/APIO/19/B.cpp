//Never stop trying
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
typedef double db;
typedef long double ld;
typedef pair<int, int> pi;
#define fi first
#define se second
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<str> vs;
typedef vector<ld> vd;
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

const int MOD = 1e9 + 7; //998244353
const ll INF = 1e18;
const int MX = 1e5 + 10;
const int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0}; //right left down up

template<class T> using V = vector<T>;
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } // divide a by b rounded up
constexpr int log2(int x) { return 31 - __builtin_clz(x); } // floor(log2(x))

#define dbg(x) cerr << " - " << #x << " : " << x << endl;
#define dbgs(x,y) cerr << " - " << #x << " : " << x << " / " << #y << " : " << y << endl;
#define dbgv(v) cerr << " - " << #v << " : " << endl << "[ "; for(auto it : v) cerr << it << ' '; cerr << ']' << endl;

void IO() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}


int N,M;
V<pair<pi,int>> vec;

vi adj[MX];
bool vis[MX];

void dfs(int u){
	vis[u]=true;
	for(auto v: adj[u]) if(!vis[v]) dfs(v);
}

bool chain(){
	if(M!=N-1) return false;
	FOR(i,0,M) if(vec[i].fi.fi!=i+1 || vec[i].fi.se!=i+2) return false;
	return true;
}

vi t(4*MX);

void update(int i, int v, int pos=1, int tl=0, int tr=M-1){
	if(tl==tr){
		t[pos]=v;
		return;
	}
	int tm=(tl+tr)/2;
	if(i<=tm) update(i,v,pos*2,tl,tm);
	else update(i,v,pos*2+1,tm+1,tr);
	t[pos]=min(t[pos*2],t[pos*2+1]);
}

int get(int l, int r, int pos=1,int tl=0, int tr=M-1){
	if(l>r) return 2e9;
	if(l==tl && r==tr) return t[pos];
	int tm=(tl+tr)/2;
	return min(get(l,min(tm,r),pos*2,tl,tm),get(max(l,tm+1),r,pos*2+1,tm+1,tr));
}

int main() {
	boost; IO();

	cin >>N>>M;
	FOR(i,0,M){
		int u,v,w; cin>>u>>v>>w;
		vec.pb({{u,v},w});
	}
	int Q; cin>>Q;

	if(N<=1000 && M<=1000 && Q<=10000){
		while(Q--){
			int t; cin>>t;
			if(t==1){
				int i,x; cin>>i>>x; i--;
				vec[i].se=x;
			}
			else{
				int u,w; cin>>u>>w;
				FOR(i,1,N+1) adj[i].clear();
				FOR(i,0,M) if(vec[i].se>=w){
					int u=vec[i].fi.fi,v=vec[i].fi.se;
					adj[u].pb(v); adj[v].pb(u);
				}
				FOR(i,1,N+1) vis[i]=false;
				dfs(u);
				int ans=0;
				FOR(i,1,N+1) if(vis[i]) ans++;
				cout << ans << endl;
			}
		}
	}
	else if(chain()){
		FOR(i,0,M) update(i,vec[i].se);
		//cout << get(0,M-1) << endl;

		while(Q--){
			int t; cin>>t;
			if(t==1){
				int i,x; cin>>i>>x; i--;
				update(i,x);
			}
			else{
				int u,w; cin>>u>>w; u--;
				int l=u,r=u;
				int ll=0,rr=u-1;
				while(ll<=rr){
					int m=(ll+rr)/2;
					if(get(m,u-1)>=w){
						l=m; rr=m-1;
					}
					else ll=m+1;
				}
				//cout << l << endl;

				ll=u,rr=N-2;
				while(ll<=rr){
					int m=(ll+rr)/2;
					if(get(u,m)>=w){
						r=m+1; ll=m+1;
					}
					else rr=m-1;
				}
				//cout << r << endl;
				cout << r-l+1 << endl;
			}
		}
	}
	else{
		
	}





	return 0;
}

/* Careful!!!
	.Array bounds
	.Infinite loops
	.Uninitialized variables / empty containers
	.Order of input

   Some insights:
	.Binary search
	.Graph representation
	.Write brute force code
	.Change your approach
*/
