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
const int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0}; //right left down up

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

#ifndef LOCAL
#include "shortcut.h"
#endif

const int MX=500;
int N,C,U,V; 
vi L,D;
vector<ll> pref(MX);

ll p(int i){
	if(i<0) return 0;
	return pref[i];
}

ll dist(int i, int j){
	ll a,b,c;	
	a=abs(p(j-1)-p(i-1))+D[i]+D[j];
	b=abs(p(i-1)-p(U-1)) + abs(p(j-1)-p(V-1)) + C + D[i] + D[j];
	c=abs(p(i-1)-p(V-1)) + abs(p(j-1)-p(U-1)) + C + D[i] + D[j];
	return min(min(a,b),c);
}

ll find_shortcut(int n, vi l, vi d, int c){
	N=n; C=c; 
	L.assign(all(l));
	D.assign(all(d));

	FOR(i,0,N-1){
		pref[i]=L[i];
		if(i) pref[i]+=pref[i-1];
	}


	ll ans=INF;
	FOR(u,0,N) FOR(v,u+1,N){
		tie(U,V)={u,v};

		/*ll val=0;
		FOR(i,0,N) FOR(j,0,N) if(i!=j){
			ckmax(val,dist(i,j));
		}*/

		int a=0,b;
		ll mx=-1;
		FOR(i,0,N) if(i!=a) if(ckmax(mx,dist(a,i))) b=i;

		a=b; mx=-1;
		FOR(i,0,N) if(i!=a) if(ckmax(mx,dist(a,i))) b=i;

		ll val=dist(a,b); 

		if(ckmin(ans,val)){
			dbgs(u,v)
			dbgs(a,b)
			dbg(dist(a,b))
		}
	}
	return ans;
}


#ifdef LOCAL
int main() {
    boost; IO();

    int N; cin>>N;
    vi s(N-1),t(N);
    FOR(i,0,N-1) cin>>s[i];
    FOR(i,0,N) cin>>t[i];
    int C; cin>>C;
    cout << find_shortcut(N,s,t,C) << endl;
    	
    return 0;
}
#endif
//Change your approach 


/*
4
2 2 2
1 10 10 1
1
*/

/*
3 
1 1 
1 1 1
3 
*/