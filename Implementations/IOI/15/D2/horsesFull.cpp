//Never stop trying
/*#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
#include "bits/stdc++.h"
#ifndef LOCAL
#include "horses.h"
#endif
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
const ll INF = 1e18;
const int MX = 5e5 + 10;
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

/*int modpow(int x, int p){
	if(p==0) return 1;
	ll v=modpow(x,p/2);
	v*=v; v%=MOD;
	if(p%2==1) v*=x,v%=MOD;
	return v; 
}
int cnvrt(ld x){
	int v=x;
	ll ans=modpow(10,v);
	ld r=x-v;
	ans*=(ll)(pow(10,r)+0.5);
	ans%=MOD;
	return ans;
}*/

int N,X[MX],Y[MX];

struct node{
	ld lazy=0,mx=0; 
	int idx=-1;
};

V<node> t(MX*4);
void push_down(int pos){
	t[pos*2].lazy+=t[pos].lazy;
	t[pos*2+1].lazy+=t[pos].lazy;
	t[pos*2].mx+=t[pos].lazy;
	t[pos*2+1].mx+=t[pos].lazy;
	t[pos].lazy=0;
}
void upd(int l, int r, ld val, int pos=1, int tl=0, int tr=N-1){
	if(l>r) return;
	if(l==tl && r==tr){
		t[pos].mx+=val;
		t[pos].lazy+=val;
		if(l==r) t[pos].idx=l;
		return;
	}
	push_down(pos);
	int tm=(tl+tr)/2;
	upd(l,min(r,tm),val,pos*2,tl,tm);
	upd(max(l,tm+1),r,val,pos*2+1,tm+1,tr);
	if(t[pos*2].mx>=t[pos*2+1].mx){
		t[pos].mx=t[pos*2].mx;
		t[pos].idx=t[pos*2].idx;
	}
	else{
		t[pos].mx=t[pos*2+1].mx;
		t[pos].idx=t[pos*2+1].idx;
	}
}

V<ll> t2(MX*4,0);
void upd2(int i, int val, int pos=1, int tl=0, int tr=N-1){
	if(tl==tr){
		t2[pos]=val;
		return;
	}
	int tm=(tl+tr)/2;
	if(i<=tm) upd2(i,val,pos*2,tl,tm);
	else upd2(i,val,pos*2+1,tm+1,tr);
	t2[pos]=(t2[pos*2]*t2[pos*2+1])%MOD;
}

ll get(int l, int r, int pos=1, int tl=0, int tr=N-1){
	if(l>r) return 1;
	if(l==tl && r==tr){
		return t2[pos];
	}
	int tm=(tl+tr)/2;
	return (get(l,min(r,tm),pos*2,tl,tm)*
		get(max(l,tm+1),r,pos*2+1,tm+1,tr))%MOD;

}


int init(int NN, int XX[], int YY[]) {
	N=NN; FOR(i,0,N) X[i]=XX[i],Y[i]=YY[i];
	FOR(i,0,N){
		upd(i,i,log10((ld)Y[i]));
	}
	FOR(i,0,N){
		upd2(i,X[i]);
		upd(i,N-1,log10((ld)X[i]));
	}
	return (get(0,t[1].idx)*Y[t[1].idx])%MOD;
}

int updateX(int pos, int val) {	
	upd(pos,N-1,log10((ld)val)-log10((ld)X[pos]));
	upd2(pos,val);
	X[pos]=val;
	return (get(0,t[1].idx)*Y[t[1].idx])%MOD;
}

int updateY(int pos, int val) {
	upd(pos,pos,log10((ld)val)-log10((ld)Y[pos]));
	Y[pos]=val;
	return (get(0,t[1].idx)*Y[t[1].idx])%MOD;
}

//613988856

#ifdef LOCAL
int main() {
    boost; IO();

    int N; cin>>N;
    int x[N],y[N]; 
    FOR(i,0,N) cin>>x[i];
    FOR(i,0,N) cin>>y[i];
    cout << init(N,x,y) << endl;

    

    return 0;
}
#endif



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