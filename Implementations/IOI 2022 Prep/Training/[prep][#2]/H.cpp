//Never stop trying
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
typedef string str;
typedef long double ld;
typedef pair<int, int> pi;
#define fi first
#define se second
typedef vector<int> vi;
typedef vector<pi> vpi;
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
const int MX = 1e6 + 10;
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
/////////////////////////ONLY CLEAN CODES ALLOWED/////////////////////////

int N; 
vi L(MX), R(MX), RL[MX*2], RR[MX*2]; 


vi adj[MX*2], vis_dfs(MX*2); 
int n,e; 

void dfs(int u){
	vis_dfs[u]=1;
	n++;  
	for(int v: adj[u]){
		e++;
		if(!vis_dfs[v]) dfs(v); 
	}
}

int LIM; 
int check(int X){
	FOR(i,1,N+1) if(L[i]>X) return 0; 

	vi vec; 
	vector<bool> vis(N+1,0),used(LIM,0); 
	FOR(i,1,N+1) if(R[i]>X){
		if(used[L[i]]) return 0; 
		vec.pb(L[i]);
		used[L[i]]=1; 
		vis[i]=1; 
	}

	
	while(sz(vec)){
		int x=vec.back(); vec.pop_back();

		for(int i: RL[x]) if(!vis[i]){
			if(used[R[i]]) return 0;
			vec.pb(R[i]);
			used[R[i]]=1; 
			vis[i]=1;  
		}

		for(int i: RR[x]) if(!vis[i]){
			if(used[L[i]]) return 0;
			vec.pb(L[i]);
			used[L[i]]=1; 
			vis[i]=1;  
		}
	}

	FOR(i,1,N+1){
		vis[i]=0; 
		if(!vis[i]) adj[L[i]].pb(R[i]), adj[R[i]].pb(L[i]); 
	}

	FOR(i,1,N+1) if(!vis_dfs[i]){
		e=0; n=0; 
		dfs(i); 
		e/=2; 
		if(e>n) return 0; 
	}

	FOR(i,1,N+1) if(!vis[i]) adj[L[i]].pop_back(), adj[R[i]].pop_back(); 

	return 1; 
}


int main() {
    boost; IO();

    cin>>N; 
    FOR(i,1,N+1){
    	cin>>L[i]>>R[i]; 
    }

    //compression
    vi v; 
    FOR(i,1,N+1) v.pb(L[i]), v.pb(R[i]);
    sort(all(v)); 

    unordered_map<int,int>mp;
    vi mpr={0};  
    int cnt=0; 
    for(int x: v) if(!mp.count(x)) mp[x]=++cnt,mpr.pb(x); 
    LIM=cnt+1; 

    FOR(i,1,N+1) L[i]=mp[L[i]], R[i]=mp[R[i]]; 
    //compression ends here


    FOR(i,1,N+1){
    	RL[L[i]].pb(i); 
    	RR[R[i]].pb(i); 
    }

    int l=1, r=cnt, ans=-1; 
    while(l<=r){
    	int m=(l+r)/2; 
    	if(check(m)) ans=m, r=m-1; 
    	else l=m+1; 
    }

    if(ans!=-1) ans=mpr[ans];
    cout << ans << endl;
    

    return 0;
}
//Change your approach 