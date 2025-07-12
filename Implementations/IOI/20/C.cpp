//Never stop trying
//#include "tickets.h"
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
const int MX = 1501;
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
int x[MX][MX];

ll find_maximum(int k, V<vi> X){
	N=sz(X); M=sz(X[0]); 
	vector<vi> res(N,vi(M,-1));
	FOR(i,0,N) FOR(j,0,M) x[i][j]=X[i][j];
	ll ans=0;

	if(M==1){
		vi vec;
		FOR(i,0,N) vec.pb(x[i][0]),res[i][0]=0;
		sort(all(vec));
		int x=vec[sz(vec)/2]; //median
		for(auto y: vec) ans+=abs(x-y);
	}
	else{
		vi vec[N][2];
		FOR(i,0,N){
			FOR(j,0,M){
				vec[i][x[i][j]].pb(j);
			}
		}
		FOR(idx,0,k){
			int a=0,b=0;
			bool vis[N]; FOR(i,0,N) vis[i]=false;
			vpi chosen;
			FOR(i,0,N){
				if(vec[i][0].empty()){
					b++,vis[i]=true;
					chosen.pb({i,vec[i][1].back()});
					vec[i][1].pop_back();
				}
				else if(vec[i][1].empty()){
					a++,vis[i]=true;
					chosen.pb({i,vec[i][0].back()});
					vec[i][0].pop_back();
				}
			}
			FOR(i,0,N) if(!vis[i]){
				if(sz(vec[i][0])>sz(vec[i][1])){
					chosen.pb({i,vec[i][0].back()});
					vec[i][0].pop_back();
					a++;
					vis[i]=true;
				}
				else if(sz(vec[i][0])<sz(vec[i][1])){
					b++;
					chosen.pb({i,vec[i][1].back()});
					vec[i][1].pop_back();
					vis[i]=true;
				}
			}
			FOR(i,0,N) if(!vis[i]){
				if(a<b){
					chosen.pb({i,vec[i][0].back()});
					vec[i][0].pop_back();
					a++;
					vis[i]=true;
				}
				else if(b<a){
					b++;
					chosen.pb({i,vec[i][1].back()});
					vec[i][1].pop_back();
					vis[i]=true;
				}
			}
			
			int cur=0;
			FOR(i,0,N) if(!vis[i]){
				if(cur==0){
					chosen.pb({i,vec[i][0].back()});
					vec[i][0].pop_back();
					a++;
					vis[i]=true;
				}
				else{
					b++;
					chosen.pb({i,vec[i][1].back()});
					vec[i][1].pop_back();
					vis[i]=true;
				}
				cur=1-cur;
			}
			for(auto x: chosen) res[x.fi][x.se]=idx;
			ans+=N/2-(max(a,b)-N/2);
		}
	}
	
	//allocate_tickets(res);
	FOR(i,0,N){
		FOR(j,0,M) cout << res[i][j] << ' ';
		cout << endl;
	}
	return ans;
}


int main() {
	boost; IO();

	int N,M,K; cin>>N>>M>>K;
	vector<vi> a(N,vi(M));
	FOR(i,0,N) FOR(j,0,M) cin>>a[i][j];
	cout << find_maximum(K, a) << endl;



	return 0;
}

/*
6 1 1
5
2 
1 
8
9
15
*/


/*
4 2 1
5 9
1 4
3 6
2 7


12

*/

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
