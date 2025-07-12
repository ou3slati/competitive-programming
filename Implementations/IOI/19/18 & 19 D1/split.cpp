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
const ll INF = 1e9;
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
#include "split.h"
#endif

int N,A,B,C;
vi adj[MX];
vi res;

bool sub1(){
	FOR(i,0,N) if(sz(adj[i])>2) return false;
	return true;
}

int nb,nb2;
void dfs(int u){
	for(auto v: adj[u]) if(res[v]==-1 && nb<B){
		res[v]=2;
		nb++;
		dfs(v);
	}
}

vi v,vv;
bool cmp(int i, int j){
	return v[i] < v[j];
}

int sub[MX],par[MX];
void dfs2(int u, int p){
	sub[u]=1; par[u]=p;
	for(auto v: adj[u]) if(v!=p){
		dfs2(v,u);
		sub[u]+=sub[v];
	}
}


void dfs3(int u, int p, int node, int c){
	res[u]=c;
	if(c==vv[1]+1) nb2++;
	else nb++;

	for(auto nxt: adj[u]) if(nxt!=p && !((c==vv[1]+1 && nb2==v[vv[1]]) || (
		c==vv[0]+1 && nb==v[vv[0]])) && nxt!=node){
		dfs3(nxt,u,node,c);
	}
}

vi find_split(int n, int a, int b, int c, vi p, vi q) {
	N=n; A=a; B=b; C=c;
	FOR(i,0,sz(p)){
		int u=p[i],v=q[i];
		adj[u].pb(v); 
		adj[v].pb(u);
	}
	if(sub1()){
		int u=0,p=-1;
		FOR(i,0,N) if(sz(adj[i])==1){u=i; break;}
		vi vec;
		while(sz(vec)<N){
			vec.pb(u);
			int nxt=-1;
			for(auto v: adj[u]) if(v!=p) nxt=v;
			p=u; u=nxt;
		}
		vi res(N,3);
		FOR(i,0,a) res[vec[i]]=1;
		FOR(i,a,a+b) res[vec[i]]=2;
		return res;
	}
	else if(a==1){
		res.assign(N,-1);
		res[0]=2; nb=1;
		dfs(0);
		FOR(i,0,N) if(res[i]==-1){res[i]=1; break;}
		FOR(i,0,N) if(res[i]==-1) res[i]=3;
		return res;
	}
	else if(sz(p)==N-1){
		v={a,b,c},vv={0,1,2};
		sort(all(vv),cmp);

		dfs2(0,0);

		int u,mn=INF;
		res.assign(N,0);
		int stt;
		FOR(i,0,N){
			if(sub[i]>=v[vv[0]] && sub[i]<mn){
				mn=sub[i];
				u=i;
				stt=0;
			}
			else if(N-sub[i]>=v[vv[0]] && N-sub[i]<mn){
				mn=N-sub[i];
				u=i;
				stt=1;
			}
		}

		if(N-mn<v[vv[1]]){
			return res;
		}

		nb=0; nb2=0;
		if(stt==0){
			dfs3(0,0,u,vv[1]+1);
			dfs3(u,par[u],u,vv[0]+1);
		}
		else{
			dfs3(0,0,u,vv[0]+1);
			dfs3(u,par[u],u,vv[1]+1);
		}
		FOR(i,0,N) if(res[i]==0) res[i]=vv[2]+1;
		return res;
	}
	
	return{};
}

#ifdef LOCAL
int main() {
    boost; IO();

    int N,M,a,b,c; cin>>N>>M>>a>>b>>c;
    vi p(M),q(M);
    FOR(i,0,M) cin>>p[i]>>q[i];
    vi v=find_split(N,a,b,c,p,q);
    dbgv(v);

    return 0;
}
#endif

/*
a=1

5 6 1 2 2 
0 1
1 2
2 3
3 0 
0 2 
2 4
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