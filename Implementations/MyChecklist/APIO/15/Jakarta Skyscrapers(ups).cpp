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
const ll INF = 2e9;
const int MX = 3e4 + 10;
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

const int mxP=40;
int N,M; 
vi pos(MX),vec[MX],P(MX);

V<pair<pi,int>> adj[MX][mxP+1];

int main() {
    boost; IO();

    cin>>N>>M;
    FOR(i,0,M){
    	cin>>pos[i]>>P[i];
    	if(P[i]<=mxP) vec[pos[i]].pb(P[i]);
	}

	FOR(i,0,M) if(P[i]>mxP){
		int x=pos[i],jump=0;
		while(x+P[i]*(jump+1)<N){
			jump++;
			adj[x][0].pb({{x+P[i]*jump,0},jump});
		}
		jump=0;
		while(x-P[i]*(jump+1)>=0){
			jump++;
			adj[x][0].pb({{x-P[i]*jump,0},jump});
		}
	}


	priority_queue<pair<int,pi>,V<pair<int,pi>>,greater<pair<int,pi>>>q;
	q.push({0,{pos[0],0}});
	int dist[N][mxP+1]; FOR(i,0,N) FOR(j,0,mxP+1) dist[i][j]=INF;
	dist[pos[0]][0]=0;

	while(!q.empty()){
		int u=q.top().se.fi,p=q.top().se.se,d=q.top().fi;
		q.pop();
		if(dist[u][p]<d) continue;

		for(auto it: adj[u][p]){
			int v=it.fi.fi,pp=it.fi.se,w=it.se;
			if(dist[v][pp]>d+w){
				dist[v][pp]=d+w;
				q.push({dist[v][pp],{v,pp}});
			}
		}

		if(u+p<N){
			int v=u+p,pp=p,w=1;
			if(dist[v][pp]>d+w){
				dist[v][pp]=d+w;
				q.push({dist[v][pp],{v,pp}});
			}
			pp=0; 
			if(dist[v][pp]>d+w){
				dist[v][pp]=d+w;
				q.push({dist[v][pp],{v,pp}});
			}
		}
		if(u-p>=0){
			int v=u-p,pp=p,w=1;
			if(dist[v][pp]>d+w){
				dist[v][pp]=d+w;
				q.push({dist[v][pp],{v,pp}});
			}
			pp=0; 
			if(dist[v][pp]>d+w){
				dist[v][pp]=d+w;
				q.push({dist[v][pp],{v,pp}});
			}
		}

		for(auto pp: vec[u]){
			int v=u,w=0;
			if(dist[v][pp]>d+w){
				dist[v][pp]=d+w;
				q.push({dist[v][pp],{v,pp}});
			}
		}
	}

	int ans=dist[pos[1]][0];
	if(ans==INF) ans=-1;
	cout << ans << endl;

    

    return 0;
}

/*
(pos,power)-->(pos+-power,power) (<=sqrt(N))
(pos,power)-->(pos+-power,0) (<=sqrt(N))
(pos,0)--> (pos,power) (all powers in that pos) (<=sqrt(N))
(pos,0)-->(nw_pos,0) (>sqrt(N))
*/
//Change your approach 