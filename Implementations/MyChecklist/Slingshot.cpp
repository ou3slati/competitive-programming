//Never stop trying
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;

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
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

const int MOD = 1e9 + 7; //998244353
const ll INF = 1e18;
const int MX = 1e5 + 10;
const int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0}; //right left down up

template<class T> using V = vector<T>;
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } // divide a by b rounded up
constexpr int log2(int x) { return 31 - __builtin_clz(x); } // floor(log2(x))

#define dbg(x) cerr << " - " << #x << " : " << x << endl;
#define dbgs(x,y) cerr << " - " << #x << " : " << x << " / " << #y << " : " << y << endl;
#define dbgv(v) cerr << " - " << #v << " : " << endl << "[ "; for(auto it : v) cerr << it << ' '; cerr << ']' << endl;

void IO2() {
#ifndef ONLINE_JUDGE
	freopen("slingshot.in", "r", stdin);
	freopen("slingshot.out", "w", stdout);
#endif
}

void IO() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}


int N,M;
vi x(MX),y(MX),t(MX); 
vi a(MX),b(MX);
V<pair<pi,pi>> vec;

V<pair<ll,ll>> st(4*4*MX);
int mx;

pi combine(pair<ll,ll> a, pair<ll,ll> b){
	ckmin(a.fi,b.fi);
	ckmin(a.se,b.se);
	return a;
}

void update(int i, int p, ll v, int pos=1, int l=1, int r=mx){
	if(l==r){
		if(p==0) ckmin(st[pos].fi,v);
		else ckmin(st[pos].se,v);
		return;
	}
	int m=(l+r)/2;
	if(i<=m) update(i,p,v,pos*2,l,m);
	else update(i,p,v,pos*2+1,m+1,r);
	st[pos]=combine(st[pos*2],st[pos*2+1]);
}

ll get(int l, int r, int p, int pos=1, int tl=1, int tr=mx){
	if(l>r) return INF;
	if(l==tl && r==tr){
		if(p==0) return st[pos].fi;
		return st[pos].se;
	}


	int tm=(tl+tr)/2;
	return min(   get(l,min(r,tm),p,pos*2,tl,tm)  ,
		get(max(tm+1,l),r,p,pos*2+1,tm+1,tr)  );

}

int main() {
	boost; IO();

	cin>>N>>M;
	FOR(i,0,N){
		cin>>x[i]>>y[i]>>t[i];
		vec.pb({{x[i],y[i]},{0,i}});
	}
	FOR(i,0,M){
		cin>>a[i]>>b[i];
		vec.pb({{a[i],b[i]},{1,i}});
	}
	sort(all(vec));

	vi vv;
	FOR(i,0,M) vv.pb(a[i]),vv.pb(b[i]);
	FOR(i,0,N) vv.pb(x[i]),vv.pb(y[i]);
	sort(all(vv));
	unordered_map<int,int> mp;
	int cnt=0;
	for(auto x: vv){
		if(!mp.count(x)) mp[x]=++cnt;
	} 
	mx=cnt;

	//initialiaze
	st.assign(4*4*MX,{INF,INF});
	ll res[M]; FOR(i,0,M) res[i]=abs(a[i]-b[i]);
	FOR(i,0,N+M){
		if(vec[i].se.fi==0){ //slingshot
			int idx=vec[i].se.se;
			update(mp[y[idx]],0,t[idx]-x[idx]-y[idx]);
			update(mp[y[idx]],1,t[idx]-x[idx]+y[idx]);
		}
		else{ //query
			ll ans=INF,idx=vec[i].se.se;
			ans=min(ans,a[idx]+b[idx]+get(1,mp[b[idx]],0));
			ans=min(ans,a[idx]-b[idx]+get(mp[b[idx]],mx,1));
			ckmin(res[idx],ans);
		}
	}


	//re-initialize
	st.assign(4*4*MX,{INF,INF});
	ROF(i,0,N+M){
		if(vec[i].se.fi==0){ //slingshot
			int idx=vec[i].se.se;
			update(mp[y[idx]],0,t[idx]+x[idx]-y[idx]);
			update(mp[y[idx]],1,t[idx]+x[idx]+y[idx]);
		}
		else{ //query
			ll ans=INF,idx=vec[i].se.se;
			ans=min(ans,-a[idx]+b[idx]+get(1,mp[b[idx]],0));
			ans=min(ans,-a[idx]-b[idx]+get(mp[b[idx]],mx,1));
			if(ckmin(res[idx],ans));
		}
	}

	FOR(i,0,M) cout << res[i] << endl;
	
	return 0;
}

/* Careful!!!
	.Array bounds
	.Infinite loops
	.Uninitialized variables / empty containers
	.Order of input

   Some insights:
	.Binary search
	.Graph representation
	.Write brute force code
	.Change your approach
*/
