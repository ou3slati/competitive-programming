//Never stop trying
/*#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
#define int ll
typedef string str;
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
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)

const int MOD = 1e9 + 7; //998244353
const ll INF = 1e18;
const int MX = 3e5 + 10;
const int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0}; //right left down up

template<class T> using V = vector<T>;
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } // divide a by b rounded up
//constexpr int log2(int x) { return 31 - __builtin_clz(x); } // floor(log2(x))

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

ll random(ll a, ll b){
    return a + rng() % (b - a + 1);
}

#ifndef LOCAL  
#define cerr if(false) cerr
#endif
#define dbg(x) cerr << #x << " : " << x << endl; 
#define dbgs(x,y) cerr << #x << " : " << x << " / " << #y << " : " << y << endl;
#define dbgv(v) cerr << #v << " : " << "[ "; for(auto it : v) cerr << it << ' '; cerr << ']' << endl;
#define here() cerr << "here" << endl;

void IO() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

vi adj[MX];
int N; 

int szz[MX];

void dfs(int u, int p){
	szz[u]=1;
	for(auto v: adj[u]) if(v!=p){
		dfs(v,u);
		szz[u]+=szz[v];
	}
}

vi t(4*MX,0);

void update(int i, int v, int pos=1, int tl=0, int tr=N-1){
	if(tl==tr){
		t[pos]=v;
		return;
	}
	int tm=(tl+tr)/2;
	if(i<=tm) update(i,v,pos*2,tl,tm);
	else update(i,v,pos*2+1,tm+1,tr);
	t[pos]=max(t[pos*2],t[pos*2+1]);
} 

int get(int l, int r, int pos=1, int tl=0, int tr=N-1){
	if(l>r) return -INF;
	if(l==tl && r==tr) return t[pos];
	int mid=(tl+tr)/2;
	return max(get(l,min(r,mid),pos*2,tl,mid),get(max(l,mid+1),r,pos*2+1,mid+1,tr));
}

int32_t main() {
    boost; IO();

    cin>>N;
    vi a(N);
    vi y(N);
    FOR(i,0,N){
    	cin>>a[i];
    	if(a[i]>0){
    		y[i]=0;
    		update(i,0);
		}
    	else{
    		y[i]=-a[i];
    		update(i,y[i]);
		}
	}

	FOR(i,0,N){
		int l=i,r=N-1;
		int ans=-1;
		while(l<=r){
			int m=(l+r)/2;
			if(get(i,m)>y[i]){
				ans=m; r=m-1;
			}
			else l=m+1;
		}
		//if(a[i]==75001 && y[i]) dbg(a[ans]);
		if(ans!=-1){
			adj[ans].pb(i);
			adj[i].pb(ans);
		}
	}
	//FOR(i,0,N-1) cout << 0 << endl;
	//fill(vis,vis+N,0);
	int ans=0;
	ROF(i,0,N) if(a[i]>0){
		dfs(i,i);
		if(szz[i]%2==1){ans=a[i]; break;}
	}
	cout << ans << endl;
    

    return 0;
}

//74992

/* Careful!!!
    .Array bounds
    .Infinite loops
    .Uninitialized variables / empty containers
    .Multisets are shit

   Some insights:
    .Binary search
    .Graph representation
    .Write brute force code
    .Change your approach
*/