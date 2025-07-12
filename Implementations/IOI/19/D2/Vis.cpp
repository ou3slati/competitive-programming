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
#include "vision.h"
#endif

/////////////////////////ONLY CLEAN CODES ALLOWED/////////////////////////

int H,W;

int dist(int x, int y, int xx, int yy){
	return abs(x-xx)+abs(y-yy);
}
int f(int x, int y){
	return x*W+y;
}

#ifdef LOCAL
int add_or(vi v){return 1;}
int add_xor(vi v){return 1;}
int add_and(vi v){return 1;}
int add_not(int x){return 1;}
#endif

void construct_network(int H, int W, int K){
	::H=H; ::W=W;

	//1&2&5
	/*vi vec;
	FOR(i,0,H) FOR(j,0,W) FOR(k,0,H) FOR(l,0,W) if(dist(i,j,k,l)==K){
		vec.pb(add_and(vi{f(i,j),f(k,l)}));
	}
	int ans=add_or(vec);*/

	//6
	/*vi vec;
	FOR(i,0,H) FOR(j,0,W) if(i+j==K){
		vec.pb(add_and(vi{f(0,0),f(i,j)}));
	}
	int ans=add_or(vec);*/

	//3
	/*vi vec;
	FOR(i,0,H) FOR(j,0,W){
		vi cur;
		FOR(k,i,H) FOR(l,0,W) if(dist(i,j,k,l)==K){
			cur.pb(f(k,l));
		}
		if(!sz(cur)) continue;
		int nw=add_or(cur);
		vec.pb(add_and(vi{f(i,j),nw}));
	}
	int ans=add_or(vec);*/

	//7 
	vi r(H),c(W),rr(H-1),cc(W-1);
	FOR(i,0,H){
		vi cur;
		FOR(j,0,W) cur.pb(f(i,j));
		r[i]=add_xor(cur);
	}
	FOR(j,0,W){
		vi cur;
		FOR(i,0,H) cur.pb(f(i,j));
		c[j]=add_xor(cur);
	}

	FOR(i,0,H-1){
		vi vec,cur;
		FOR(j,0,W) cur.pb(f(i,j));
		vec.pb(add_or(cur));

		cur.clear();
		FOR(j,0,W) cur.pb(f(i+1,j));
		vec.pb(add_or(cur));

		rr[i]=add_and(vec);
	}
	FOR(j,0,W-1){
		vi vec,cur;
		FOR(i,0,H) cur.pb(f(i,j));
		vec.pb(add_or(cur));

		cur.clear();
		FOR(i,0,H) cur.pb(f(i,j+1));
		vec.pb(add_or(cur));

		cc[j]=add_and(vec);
	}

	vi R(2,0),C(2,0);

	vi cur;
	FOR(i,0,H) cur.pb(r[i]);
	R[0]=add_not(add_or(cur));

	cur.clear();
	FOR(i,0,W) cur.pb(c[i]);
	C[0]=add_not(add_or(cur));

	cur.clear();
	FOR(i,0,H-1) cur.pb(rr[i]);
	if(sz(cur)) R[1]=add_or(cur);

	cur.clear();
	FOR(i,0,W-1) cur.pb(cc[i]);
	if(sz(cur)) C[1]=add_or(cur);

	if(H==1){
		int ans=add_and(vi{R[0],C[1]});
	}
	else if(W==1){
		int ans=add_and(vi{R[1],C[0]});
	}
	else{
		vi vec={add_and(vi{R[0],C[1]}),add_and(vi{R[1],C[0]})};
		int ans=add_or(vi{vec[0],vec[1]});
	}
}


/*int main() {
    boost; IO();
    

    return 0;
}*/
//Change your approach 