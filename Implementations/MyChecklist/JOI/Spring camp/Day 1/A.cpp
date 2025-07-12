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
const int MX = 250000 + 10;
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

int N,M,Q,ans[MX],C[MX],K[MX]; 
ll B[MX]; 
vpi q[MX]; 
vi q3[MX];

V<ll> ft(MX,0);
void upd2(int i, int v){
	i++;
	for(;i<MX; i+=i&-i) ft[i]+=v;
}
ll get(int i){
	i++;
	ll ans=0;
	for(;i;i-=i&-i) ans+=ft[i];
	return ans; 
}

ll summ(int l, int r){
	return get(r)-get(l-1);
}

const int S=100;
V<ll> a(MX,0),sum(MX,0),mnp(MX,INF);

void upd(int idx, int v){
	a[idx]+=v;
	idx/=S;
	sum[idx]=0; mnp[idx]=INF;
	FOR(i,idx*S,min((idx+1)*S,Q)){
		sum[idx]+=a[i];
		ckmin(mnp[idx],sum[idx]);
	}
}
 
int solve(int idx){
	ll cur=0;
	FOR(b,0,idx/S){
		if(-mnp[b]>cur)
			cur+=-mnp[b]-cur;
		cur+=sum[b];
	}

	FOR(i,(idx/S)*S,idx+1){
		cur+=a[i];
		if(cur<0) cur=0;
	}

	if(cur<B[idx]) return 0;

	ll x=cur-B[idx]+1;
	int i,l=0,r=idx;
	while(l<=r){
		int m=(l+r)/2;
		if(summ(m,idx)>=x){
			i=m;
			l=m+1;
		}
		else r=m-1;
	}
	return C[i];
}

int main() {
    boost; IO();
    memset(C,-1,sizeof(C));
    memset(ans,-1,sizeof(C));

    cin>>N>>M>>Q;
    FOR(i,0,Q){
    	int t; cin>>t;
    	if(t==1){
    		int l,r; cin>>l>>r>>C[i]>>K[i]; l--; r--;
    		q[l].eb(i,1);
    		q[r+1].eb(i,-1);
    	}
    	else if(t==2){
    		int l,r; cin>>l>>r>>K[i]; l--; r--;
    		q[l].eb(i,1);
    		q[r+1].eb(i,-1);
    	}
    	else{
    		int idx; cin>>idx>>B[i]; idx--;
    		q3[idx].pb(i);
    	}
    }


    FOR(i,0,N){
    	for(auto it: q[i]){
    		int idx=it.fi,t=it.se;
    		if(C[idx]!=-1) upd(idx,K[idx]*t),upd2(idx,K[idx]*t);
    		else upd(idx,-K[idx]*t);
    	}
    	for(int idx: q3[i]){
    		ans[idx]=solve(idx);
    	}
    }
    FOR(i,0,Q) if(ans[i]!=-1) cout << ans[i] << endl;

    return 0;
}
//Change your approach 