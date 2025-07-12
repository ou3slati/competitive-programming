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

int N,Q; 
vi X(MX,INF); 
int M;
vpi vec;
vi pl(MX,0),pr(MX,0),sl(MX,0),sr(MX,0);

int f(int i){
	int x=X[i],l=-INF,r=INF; 
	if(i) l=X[i-1]; 
	if(i+1<N) r=X[i+1];

	vi v; 
	FOR(i,0,M) if(vec[i].fi){ 
		v.pb(i);
	}

	int lft=0,rgt=sz(v)-1,idx=-1;
	while(lft<=rgt){
		int mid=(lft+rgt)/2;
		if(x+pr[v[mid]]>r-pl[v[mid]]){
			idx=mid;
			rgt=mid-1;
		}	
		else lft=mid+1;
	}
	if(idx==-1) return 0;

	int rmv=x+pr[v[idx]]-(r-pl[v[idx]]);
	/*if(idx) ckmin(rmv,pr[v[idx]]-pr[v[idx-1]]);
	else ckmin(rmv,pr[v[idx]]);*/

	int prev=x;
	if(idx) prev+=pr[v[idx-1]];
	if(prev>r-pl[v[idx]]){
		rmv=pr[v[idx]];
		if(idx) rmv-=pr[v[idx-1]];
	}

	if(v[idx]+1<N) rmv+=sr[v[idx]+1];

	return rmv;
}
int f2(int i){
	int x=X[i],l=-INF,r=INF; 
	if(i) l=X[i-1]; 
	if(i+1<N) r=X[i+1];

	vi v; 
	FOR(i,0,M) if(!vec[i].fi){ 
		v.pb(i);
	}

	int lft=0,rgt=sz(v)-1,idx=-1;
	while(lft<=rgt){
		int mid=(lft+rgt)/2;
		if(x-pl[v[mid]]<l+pr[v[mid]]){
			idx=mid;
			rgt=mid-1;
		}	
		else lft=mid+1;
	}
	if(idx==-1) return 0;

	int rmv=l+pr[v[idx]]-(x-pl[v[idx]]);
	/*if(idx) ckmin(rmv,pl[v[idx]]-pl[v[idx-1]]);
	else ckmin(rmv,pl[v[idx]]);*/

	int prev=x;
	if(idx) prev-=pl[v[idx-1]];

	if(prev<l+pr[v[idx]]){
		rmv=pl[v[idx]];
		if(idx) rmv-=pl[v[idx-1]];
	}

	if(v[idx]+1<N) rmv+=sl[v[idx]+1];
	assert(rmv>=0);
	return rmv;
}


int32_t main() {
    boost; IO();

    cin>>N>>Q;
    FOR(i,0,N) cin>>X[i];
    sort(all(X));

    int mn=0,mx=0,cur=0;
    
   	FOR(i,0,Q){
   		int w; cin>>w;
   		cur+=w;
   		if(cur>mx){
   			vec.eb(1,cur-mx);
   			mx=cur;
   		}
   		else if(cur<mn){
   			vec.eb(0,mn-cur);
   			mn=cur;
   		}
   	}

   	/*for(auto x: vec){
   		cout << x.fi << ' ' << x.se << endl;
   	}*/
   	M=sz(vec);
   	
   	FOR(i,0,M){
   		int d=vec[i].fi,x=vec[i].se;
   		if(d) pr[i]=sr[i]=x;
   		else pl[i]=sl[i]=x;
   	}
   	FOR(i,1,M){
   		pl[i]+=pl[i-1];
   		pr[i]+=pr[i-1];
   	}
   	ROF(i,0,M-1){
   		sl[i]+=sl[i+1];
   		sr[i]+=sr[i+1];
   	}
    
    vi ans(N,mx-mn); 
    FOR(i,0,N){
    	ans[i]-=f(i);
    	ans[i]-=f2(i);
    }
    FOR(i,0,N){
    	assert(ans[i]>=0);
    	cout << ans[i] << endl;
	}

    return 0;
}
//Change your approach 