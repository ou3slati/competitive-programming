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
vpi vec[mxN];
vi t[2];

int combine(int t, int x, int y){
	if(t==0) return max(x,y);
	return min(x,y);
}

void upd(int n, int idx, int v, int pos=1, int l=0, int r=Q-1){
	if(l==r){
		t[n][pos]=v;
		return;
	}
	int m=(l+r)/2;
	if(idx<=m) upd(n,idx,v,pos*2,l,m);
	else upd(n,idx,v,pos*2+1,m+1,r);

	t[n][pos]=combine(n,t[n][pos*2],t[n][pos*2+1]);
}

int get(int n, int l, int r, int pos=1, int tl=0, int tr=Q-1){
	if(l>r){
		if(n==0) return 0;
		return INF;
	}
	if(l==tl && r==tr){
		return t[n][pos];
	}
	int tm=(tl+tr)/2;
	return combine(n,get(n,l,min(tm,r),pos*2,tl,tm),
		get(n,max(l,tm+1),r,pos*2+1,tm+1,tr));
}

int solve(){
	int l=0,r=Q-1,idx=Q;

	int xx=0;
	while(l<=r){
		int m=(l+r)/2;
		int x=get(0,m,Q-1),y=get(1,m,Q-1);
		if(x<=y){
			idx=m;
			r=m-1;
			xx=x;
		}
		else l=m+1;
	}
	int ans=xx;
	if(idx) ckmax(ans,get(1,idx-1,Q-1));

	return ans;
}

void buildWall(int N, int Q, int op[], int L[], int R[], int H[], int fH[]){
	::N=N; ::Q=Q;
	t[0].assign(Q*4+10,0);
	t[1].assign(Q*4+10,INF);

	FOR(i,0,Q){
		int l=L[i],r=R[i];
		vec[l].pb({i,1});
		vec[r+1].pb({i,-1});
	}

	FOR(i,0,N){
		for(auto it: vec[i]){
			int idx=it.fi;
			if(it.se==1){
				if(op[idx]==1){
					upd(0,idx,H[idx]);
				}
				else{
					upd(1,idx,H[idx]);
				}
			}
			else{
				if(op[idx]==1){
					upd(0,idx,0);
				}
				else{
					upd(1,idx,INF);
				}
			}
		}

		if(!sz(vec[i])){
			if(!i) fH[i]=0;
			else fH[i]=fH[i-1];
		}
		else fH[i]=solve();
	} 
	//FOR(i,0,N) cout << fH[i] << ' '; cout << endl;

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