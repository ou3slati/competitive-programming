//Never stop trying
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
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
const int MX = 2e5 + 10;
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

vi vec[MX];

int32_t main() {
	boost; IO();

	int N; cin>>N;
	//cout << N << endl;
	unordered_map <str,int> mp;
	int cnt=0;

	int ed[N];
	
	FOR(i,0,N){
		str s,ss; cin>>s>>ss;
		int u,v; 
		if(!mp.count(s)) mp[s]=cnt++;
		if(!mp.count(ss)) mp[ss]=cnt++;
		u=mp[s],v=mp[ss];
		ed[u]=v;
		vec[v].pb(u);
	}

	if(N%2==1){
		cout << -1 << endl;
		return 0;
	}

	bool vis[N]; FOR(i,0,N) vis[i]=false;

	FOR(i,0,N) if(!vis[i]){
		if(i!=ed[i] && i==ed[ed[i]]) vis[i]=true,vis[ed[i]]=true;
	}

	int ans=0;
	int nb=0;
	FOR(i,0,N) if(i!=ed[i] && !vis[i]){
		if(!vis[ed[i]]){
			ans++;
			vis[i]=true; vis[ed[i]]=true;
			for(int j=0; j<sz(vec[ed[ed[i]]]); j++) if(vec[ed[ed[i]]][j]==ed[i]){
				vec[ed[ed[i]]].erase(vec[ed[ed[i]]].begin()+j);
				break;
			}
		}
		else{
			for(auto j: vec[i]) if(!vis[j]){
				vis[j]=true;
				vis[i]=true;
				ans++;
				for(int k=0;k<sz(vec[ed[i]]); k++) if(vec[ed[i]][k]==i){
					vec[ed[i]].erase(vec[ed[i]].begin()+k);
					break;
				}
				break;
			}
		}
	}

	FOR(i,0,N) if(!vis[i]) nb++;
	
	ans+=nb;
	cout << ans << endl;



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
