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

const int mxQ=5e5+10,mxN=2e6+10;

#ifndef LOCAL
#include "wall.h"
#endif

int N,Q; 
vpi t(mxN*4,{-INF,INF});

pi add(pi a, int op, int h){
	if(op==1){
		ckmax(a.fi,h);
		if(h>a.se) a.se=h; 
	}
	else{
		ckmin(a.se,h);
		if(h<a.fi) a.fi=h;
	}
	return a;
}

void push_down(int pos){
	if(t[pos].fi==-INF && t[pos].se==INF) return;
	t[pos*2]=add(t[pos*2],1,t[pos].fi);
	t[pos*2]=add(t[pos*2],2,t[pos].se);
	t[pos*2+1]=add(t[pos*2+1],1,t[pos].fi);
	t[pos*2+1]=add(t[pos*2+1],2,t[pos].se);
	t[pos]={-INF,INF};
}

void upd(int op, int l, int r, int h, int pos=1, int tl=0, int tr=N-1){
	if(l>r) return;

	if(l==tl && r==tr){
		t[pos]=add(t[pos],op,h);
		return;
	}

	push_down(pos);

	int tm=(tl+tr)/2;
	upd(op,l,min(r,tm),h,pos*2,tl,tm);
	upd(op,max(l,tm+1),r,h,pos*2+1,tm+1,tr);
}


int get(int idx, int pos=1, int tl=0, int tr=N-1){
	if(tl==tr){
		return min(t[pos].fi,t[pos].se);
	}

	push_down(pos);

	int tm=(tl+tr)/2;
	if(idx<=tm) return get(idx,pos*2,tl,tm);
	return get(idx,pos*2+1,tm+1,tr);
}

void buildWall(int N, int Q, int op[], int L[], int R[], int H[], int fH[]){
	::N=N; ::Q=Q;
	
	t[1]={0,0};

	FOR(i,0,Q){
		upd(op[i],L[i],R[i],H[i]);
	}
	FOR(i,0,N){
		fH[i]=get(i);
	}
	//FOR(i,0,N) cout << fH[i] << " "; cout << endl;

	return;
}


#ifdef LOCAL
int main() {
    boost; IO();

    int N,Q; cin>>N>>Q;
    int op[Q],l[Q],r[Q],h[Q],fH[N];
    FOR(i,0,Q) cin>>op[i]>>l[i]>>r[i]>>h[i];
    buildWall(N,Q,op,l,r,h,fH);
    
    

    return 0;
}
#endif
//Change your approach 