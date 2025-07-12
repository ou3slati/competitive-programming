//Never stop trying
//#include "supertrees.h"
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
//#define int ll
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
const int MX = 1001;
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



int N;
int p[MX][MX];
vi adj[MX];
bool vis[MX]; set<int> s;

vi adj2[MX];
bool vis2[MX]; set<int> ss;



bool sub1(){
	FOR(i,0,N) FOR(j,i+1,N) if(p[i][j]!=1) return 0;
	return 1;
}

bool sub2(){
	FOR(i,0,N) FOR(j,i+1,N)  if(p[i][j]!=0 && p[i][j]!=1) return 0;
	return 1;
}
bool sub3(){
	FOR(i,0,N) FOR(j,i+1,N) if(p[i][j]!=0 && p[i][j]!=2) return 0;
	return 1;
}


void dfs(int u){
	vis[u]=true;
	s.insert(u);
	for(auto v: adj[u]) if(!vis[v])dfs(v);
}
void dfs2(int u){
	vis2[u]=true;
	ss.insert(u);
	for(auto v: adj2[u]) if(!vis2[v])dfs2(v);
}



bool check(vi vec[]){
	FOR(i,0,N){
		FOR(j,0,sz(vec[i])) FOR(k,j+1,sz(vec[i])) if(p[vec[i][j]][vec[i][k]]!=1) return 0;
		FOR(j,0,sz(vec[i])) FOR(k,i+1,N) FOR(l,0,sz(vec[k])){
			if(p[vec[i][j]][vec[k][l]]!=2) return 0;
		}
	}
	return 1;
}



int construct(vector<vi> P) {
	N=sz(P[0]);
	vector<vi> res(N,vi(N,-1));
	FOR(i,0,N) FOR(j,0,N) p[i][j]=P[i][j],res[i][j]=0;

	if(sub1()){
		FOR(i,0,N-1) res[i][i+1]=res[i+1][i]=1;
	}
	else if(sub2()||sub3()){
		FOR(i,0,N) FOR(j,i+1,N) if(p[i][j]!=0){
			adj[i].pb(j); adj[j].pb(i);
		}
		FOR(i,0,N) vis[i]=false;
		FOR(i,0,N) if(!vis[i]){
			s.clear(); dfs(i);
			vi vec; for(auto x: s) vec.pb(x);
			if(sz(vec)==1) continue; //no edges to add
			//dbgv(vec);
			int cur=p[vec[0]][vec[1]];
			if(sz(vec)==2 && cur==2) return 0; //multiple edges
			FOR(j,0,sz(vec)) FOR(k,j+1,sz(vec)){
				if(p[vec[j]][vec[k]]!=cur) return 0;
			}
			FOR(i,0,sz(vec)){
				if(i<sz(vec)-1){
					res[vec[i]][vec[i+1]]=res[vec[i+1]][vec[i]]=1;
				}	
				if(i==sz(vec)-1 && cur==2) res[vec[i]][vec[0]]=res[vec[0]][vec[i]]=1;
			}
		}
	}
	else{
		FOR(i,0,N) FOR(j,i+1,N) if(p[i][j]!=0){
			adj[i].pb(j); adj[j].pb(i);
		}
		FOR(i,0,N) if(!vis[i]){
			s.clear(); dfs(i);
			vi vec; for(auto x: s) vec.pb(x);
			if(sz(vec)==1) continue; //no edges to add

			//We are in a connected component 
			
			FOR(j,0,sz(vec)) FOR(k,j+1,sz(vec)){
				if(p[vec[k]][vec[j]]==1){
					adj2[vec[k]].pb(vec[j]);
					adj2[vec[j]].pb(vec[k]);
				}
			}
			FOR(j,0,N) vis2[j]=false;

			vi group[N]; int cnt=0;
			vi cy;
			for(auto u: vec) if(!vis2[u]){
				ss.clear(); dfs2(u);
				vi vv; for(auto x: ss) vv.pb(x);
				cy.pb(u);
				for(auto x: vv) group[cnt].pb(x);
				cnt++;
				if(sz(vv)==1) continue;
				FOR(i,0,sz(vv)-1){
					res[vv[i]][vv[i+1]]=res[vv[i+1]][vv[i]]=1;
				}
			}	

			if(!check(group)||cnt==2) return 0;

			FOR(i,0,sz(cy)-1){
				res[cy[i]][cy[i+1]]=res[cy[i+1]][cy[i]]=1;
			}
			if(sz(cy)>1) res[cy.back()][cy[0]]=res[cy[0]][cy.back()]=1;

		}
	}

	//build(res);
	FOR(i,0,N){
		FOR(j,0,N) cout << res[i][j] << ' ';
		cout << endl;
	}
	return 1;
}

/*
5
0 0 0 0 0
0 0 2 2 2
0 2 0 2 2
0 2 2 0 2
0 2 2 2 0

0 0 0 0 0 
0 0 1 0 1 
0 1 0 1 0 
0 0 1 0 1 
0 1 0 1 0 
*/

/*
6
0 1 0 0 0 0
1 0 0 0 0 0
0 0 0 1 2 2
0 0 1 0 2 2
0 0 2 2 0 2
0 0 2 2 2 0

*/

/*
9
0 1 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0 0
0 0 0 1 2 2 2 2 2
0 0 1 0 2 2 2 2 2
0 0 2 2 0 2 2 2 1
0 0 2 2 2 0 1 1 2
0 0 2 2 2 1 0 1 2
0 0 2 2 2 1 1 0 2
0 0 2 2 1 2 2 2 0


0 1 0 0 0 0 0 0 0 
1 0 0 0 0 0 0 0 0 
0 0 0 1 1 1 0 0 0 
0 0 1 0 0 0 0 0 0 
0 0 1 0 0 1 0 0 1 
0 0 1 0 1 0 1 0 0 
0 0 0 0 0 1 0 1 0 
0 0 0 0 0 0 1 0 0 
0 0 0 0 1 0 0 0 0 
*/



int main() {
	boost; IO();

	cin>>N;
	vector<vi> a(N,vi(N,-1));
	FOR(i,0,N) FOR(j,0,N) cin>>a[i][j];
	cout << construct(a) << endl;



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
