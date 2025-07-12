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

ll N; 

ll f(ll x, ll y){
	return x*y;
}


V<ll> t(MX,INF),t2(MX,-INF);
vi L(MX,-1),R(MX,-1),L2(MX,-1),R2(MX,-1);

int cnt=1;
void upd(int i, int v, int pos=1, int l=0, int r=N-1){
	if(l==r){
		t[pos]=v; 
		return; 
	}

	int m=(l+r)/2;
	if(i<=m){
		if(L[pos]==-1) L[pos]=++cnt; 
		upd(i,v,L[pos],l,m);
		ckmin(t[pos],t[L[pos]]);
	}
	else{
		if(R[pos]==-1) R[pos]=++cnt; 
		upd(i,v,R[pos],m+1,r);
		ckmin(t[pos],t[R[pos]]);
	}
}

ll get(int l, int r, int pos=1, int tl=0, int tr=N-1){
	if(l>r) return INF;
	if(l==tl && r==tr) return t[pos];

	int tm=(tl+tr)/2;

	ll ans=INF;
	if(L[pos]!=-1) ckmin(ans,get(l,min(r,tm),L[pos],tl,tm));
	if(R[pos]!=-1) ckmin(ans,get(max(tm+1,l),r,R[pos],tm+1,tr));

	return ans; 
}

int cnt2=1;

void upd2(int i, int v, int pos=1, int l=0, int r=N-1){
	if(l==r){
		t2[pos]=v; 
		return; 
	}

	int m=(l+r)/2;
	if(i<=m){
		if(L2[pos]==-1) L2[pos]=++cnt2; 

		upd2(i,v,L2[pos],l,m);
		ckmax(t2[pos],t2[L2[pos]]);
	}
	else{
		if(R2[pos]==-1) R2[pos]=++cnt2; 

		upd2(i,v,R2[pos],m+1,r);
		ckmax(t2[pos],t2[R2[pos]]);
	}

}

ll get2(int l, int r, int pos=1, int tl=0, int tr=N-1){
	if(l>r) return -INF; 
	if(l==tl && r==tr) return t2[pos];

	int tm=(tl+tr)/2;
	ll ans=-INF;
	if(L2[pos]!=-1) ckmax(ans,get2(l,min(r,tm),L2[pos],tl,tm));

	if(R2[pos]!=-1) ckmax(ans,get2(max(tm+1,l),r,R2[pos],tm+1,tr));

	return ans; 
}

int main() {
    boost; IO();

    cin>>N;
    
    ll ans=(N*(N+1))/2;
    while(1){
    	ll l,d,r; cin>>l; if(l==-1) break;
    	cin>>d; r=l+d-1;

    	ll r3=get(l,N-1),l2=get2(0,r);

    	ans-=f(l+1,N-r);
    	if(r3!=INF) ans+=f(l+1,N-max(r3,r));
    	if(l2!=-INF) ans+=f(min(l2,l)+1,N-r);

    	if(l2!=-INF && r3!=INF) 
    		ans-=f(min(l2,l)+1,N-max(r3,r));

    	upd(l,r);
    	upd2(r,l);

    	cout << ans%MOD << endl; 
    	cout.flush();
    }

    return 0;
}
//Change your approach 