//Never stop trying
/*#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
#define int ll
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
const int MX = 3e5 + 100;
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

vi t(4*MX,0);

int N; 
vi a(MX);

void build(int pos=1, int l=0, int r=N-1){
	if(l==r){
		t[pos]=a[l];
		return;
	}
	int m=(l+r)/2;
	build(pos*2,l,m);
	build(pos*2+1,m+1,r);
	t[pos]=min(t[pos*2],t[pos*2+1]);
}

int query(int l, int r, int pos=1, int tl=0, int tr=N-1){
	if(l>r) return INF;
	if(tl==l && tr==r) return t[pos];
	int tm=(tl+tr)/2;

	return min(query(l,min(r,tm),pos*2,tl,tm),  query(max(l,tm+1),r,pos*2+1,tm+1,tr) );
}

vi bit(MX,0);
void update(int i, int v){
	for(;i<MX; i+=i&-i) bit[i]+=v;
}
void upd(int l, int r){
	update(l,1); update(r+1,-1);
}
int sum(int i){
	int ans=0;
	for(;i;i-=i&-i) ans+=bit[i];
	return ans;
}

int32_t main() {
    boost; IO();

    int TC; cin>>TC;
    while(TC--){
    	cin>>N;  a.resize(N);
    	FOR(i,0,N+10) bit[i]=0;
    	FOR(i,0,4*N+10) t[i]=INF;
    	set <int> s;
    	
    	FOR(i,0,N){
    		cin>>a[i];
    		s.insert(a[i]);
    	}
    	int prev=0; bool y=true;
    	for(auto x: s){
    		if(x!=prev+1) y=false;
    		prev=x;
    	}
    	if(!y){
    		FOR(i,0,N) cout << 0;
    		cout << endl;
    		continue;
    	}

    	build();
    	vpi vec[N+1];
    	FOR(i,0,N){
    		int l=0,r=i-1;
    		int left=i;
    		while(l<=r){
    			int m=(l+r)/2;
    			if(query(m,i-1)>a[i]){
    				left=m; 
    				r=m-1;
    			}
    			else l=m+1;
    		}

    		l=i+1,r=N-1;
    		int right=i;
    		while(l<=r){
    			int m=(l+r)/2;
    			if(query(i,m)==a[i]){
    				right=m; 
    				l=m+1;
    			}
    			else r=m-1;
    		}
    		vec[a[i]].pb({left,right});

    		if(left==i || right==i) continue;

    		upd(2,right-left);
    	}

    	FOR(i,1,N+1) if(sz(vec[i])){
    		//vec[i].erase(unique(all(vec[i])),vec[i].end());
    		vi v; for(auto x: vec[i]) v.pb(x.se-x.fi+1);
    		sort(all(v));
    		if(sz(v)<2) continue;
    		int x=v[sz(v)-2];
    		if(x>1) upd(2,x);
    	}
    	
    	// 1 separate
    	vi ans;
    	sort(all(a));

    	bool c=true;
    	FOR(i,1,N){
    		if(a[i]==a[i-1]) c=false;
    	} 
    	if(!c) ans.pb(0);
    	else ans.pb(1);

    	FOR(i,2,N+1){
    		if(sum(i)>0) ans.pb(0);
    		else ans.pb(1);
    	}
    	for(auto x: ans) cout << x; cout << endl;
    }
    

    return 0;
}

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