//Never stop trying
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
#define int ll
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
/////////////////////////ONLY CLEAN CODES ALLOWED/////////////////////////

const int LOG=45;
vi X(LOG),Y(LOG),X2(LOG),Y2(LOG);


vi f(int x){
	vi v(LOG);
	FOR(i,0,LOG){
		v[i]=x%3;
		x/=3;
	}
	return v;
}

const int mxv=10;
int memo[LOG][mxv][mxv][2][2];

int solve(int i, int v1, int v2, int f1, int f2){
	if(i==LOG){
		if(v1+v2+f1+f2) return 0;
		return 1;
	}

	int &ind=memo[i][v1][v2][f1][f2];
	if(ind!=-1) return ind;

	int ans=0;
	FOR(add,0,3){
		int d1=X[i]+add+v1,d2=Y[i]+add+v2;

		if((d1%3)%2!=(d2%3)%2) continue;

		int nf1,nf2;

		if(d1%3>X2[i]) nf1=1;
		else if(d1%3==X2[i]) nf1=f1;
		else nf1=0;

		if(d2%3>Y2[i]) nf2=1;
		else if(d2%3==Y2[i]) nf2=f2;
		else nf2=0;

		ans+=solve(i+1,d1/3,d2/3,nf1,nf2);
	}
	return ind=ans;
}

int32_t main() {
    boost; IO();

    int Q; cin>>Q;
    while(Q--){
    	int x,y,d; cin>>d>>x>>y;

    	vi v=f(x);
    	X.assign(all(v));
    	v=f(y);
    	Y.assign(all(v));
    	v=f(x+d);
    	X2.assign(all(v));
    	v=f(y+d);
    	Y2.assign(all(v));

    	dbgv(X2)
    	
    	memset(memo,-1,sizeof(memo));
    	cout << solve(0,0,0,0,0) << endl;
    }
    

    return 0;
}
//Change your approach 