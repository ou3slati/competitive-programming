//Never stop trying
/*#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
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
const ll INF = 2e9;
const int MX = 2e5 + 10;
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

#ifndef LOCAL
#include "werewolf.h"
#endif

vi vec;
vpi t(MX*4);
int N;

void build(int pos=1, int l=0, int r=N-1){
	if(l==r){
		t[pos]={vec[l],vec[l]};
		return;
	}
	int m=(l+r)/2;
	build(pos*2,l,m);
	build(pos*2+1,m+1,r);
	t[pos].fi=min(t[pos*2].fi,t[pos*2+1].fi);
	t[pos].se=max(t[pos*2].se,t[pos*2+1].se);
}

int query(int type, int l, int r, int pos=1, int tl=0, int tr=N-1){
	if(l>r){
		if(type==0) return INF;
		return -INF;
	}

	if(l==tl && r==tr){
		if(type==0) return t[pos].fi;
		return t[pos].se;
	}
	int tm=(tl+tr)/2;
	if(type==0) 
		return min( query(type,l,min(r,tm),pos*2,tl,tm), 
			query(type,max(l,tm+1),r,pos*2+1,tm+1,tr) );
	return max( query(type,l,min(r,tm),pos*2,tl,tm), 
			query(type,max(l,tm+1),r,pos*2+1,tm+1,tr) );
}

vi adj[MX]; 

vi check_validity(int n, vi X, vi Y, vi S, vi E, vi L, vi R){
	int Q=sz(S); N=n;

	FOR(i,0,sz(X)){
		int u=X[i],v=Y[i];
		adj[u].pb(v); 
		adj[v].pb(u);

	}

	int u,p=-1; 
	FOR(i,0,N) if(sz(adj[i])==1) {u=i; break;}

	
	while(1){
		vec.pb(u);
		int nxt=-1;
		for(auto v: adj[u]) if(v!=p) nxt=v;
		if(nxt==-1) break;
		p=u; u=nxt;
	}
	assert(sz(vec)==N);
	unordered_map<int,int>mp; FOR(i,0,N) mp[vec[i]]=i;
	build();

	vi A(Q,0);
	FOR(i,0,Q){
		int l=L[i],r=R[i],s=S[i],e=E[i];
		if(s<l || e>r){
			continue;
		}
		s=mp[s]; e=mp[e];
		if(s<e){
			int idx; //max idx such that min(s,idx)>=l
			int lft=s,rgt=e;
			while(lft<=rgt){
				int m=(lft+rgt)/2;
				if(query(0,s,m)>=l){
					idx=m; 
					lft=m+1;
				}
				else rgt=m-1;
			}
			A[i]=(query(1,idx,e)<=r && vec[idx]<=r);
		}
		else{
			int idx; //min idx such that min(idx,s)>=l
			int lft=e,rgt=s;
			while(lft<=rgt){
				int m=(lft+rgt)/2;
				if(query(0,m,s)>=l){
					idx=m; 
					rgt=m-1;
				}
				else lft=m+1;
			}
			A[i]=(query(1,e,idx)<=r && vec[idx]<=r);
		}

	}
	return A;
}

#ifdef LOCAL
int main() {
    boost; IO();

    int N,M,Q; cin>>N>>M>>Q;
    vi x(M),y(M); 
    FOR(i,0,M) cin>>x[i];
    FOR(i,0,M) cin>>y[i];
    vi s(Q),e(Q),l(Q),r(Q);
    FOR(i,0,Q) cin>>s[i];
    FOR(i,0,Q) cin>>e[i];
    FOR(i,0,Q) cin>>l[i];
    FOR(i,0,Q) cin>>r[i];


    vi vec=check_validity(N,x,y,s,e,l,r);
    for(auto x: vec) cout << x << ' '; cout << endl;
    

    return 0;
}
#endif

/*
6 6 3
5 1 1 3 3 5
1 2 3 4 0 2
4 4 5
2 2 4
1 2 3
2 2 4
*/


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