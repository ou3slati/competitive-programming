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

bool cmp(pair<int,pi> a, pair<int,pi> b){
	return abs(a.fi)<abs(b.fi);
	return a.se.fi<b.se.fi;
}

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
	else if(K==1) {
		vpi final; 
		ans=-1;

		FOR(i,0,N) FOR(vv,0,2){
			ll val=0; vpi chosen; 
			int jj=vv; if(vv==1) jj=M-1; chosen.pb({i,jj});
			int m=x[i][jj];
			//dbg(m);	

			vector<pair<int,pi>> vec;
			FOR(j,0,N) if(j!=i){
				vec.pb({m-x[j][0],{j,0}});
				vec.pb({m-x[j][M-1],{j,M-1}});
			}
			sort(all(vec),cmp);
			
			//for(auto x: vec) cout << x.fi << ' '; cout << endl;

			bool vis[N]; FOR(j,0,N) vis[j]=false; vis[i]=true;
			int l=0,r=0,mid=1;
			while(!vec.empty()){
				if(vis[vec.back().se.fi]){
					vec.pop_back();
					continue;
				}
				
				int xx=vec.back().fi;
				if((xx<=0 && (r<N/2 || xx==0))){ 
					if(xx==0) mid++;
					else r++;
					val+=-xx;
					vis[vec.back().se.fi]=true; chosen.pb(vec.back().se);
				}
				if(xx>0 && l<N/2){
					l++; val+=xx;
					vis[vec.back().se.fi]=true; chosen.pb(vec.back().se);
				}
				vec.pop_back();
			}

			/*cout << m << endl;
			cout << l << ' ' << mid << ' ' << r << endl;
			for(auto x: chosen) cout << x.fi << ' ' << x.se << endl;
			cout << endl;*/

			if(val>ans && l+r+mid==N){
				ans=val;
				final.assign(all(chosen));
			}
		}
		for(auto it: final) res[it.fi][it.se]=0;
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
