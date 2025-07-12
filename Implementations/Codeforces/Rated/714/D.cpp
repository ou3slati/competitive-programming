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

int N,P; 
vi a(MX);

bool cmp(int i, int j){
	return a[i]<a[j];
}

vpi t(MX*4); 
void precompute(int l=0, int r=N-1, int pos=1){
	if(l==r){
		t[pos].fi=t[pos].se=a[l];
		return; 
	}
	int m=(l+r)/2;
	precompute(l,m,pos*2);
	precompute(m+1,r,pos*2+1);
	t[pos].fi=min(t[pos*2].fi,t[pos*2+1].fi);
	t[pos].se=__gcd(t[pos*2].se,t[pos*2+1].se);
}

int query(int ty, int l, int r, int tl=0, int tr=N-1, int pos=1){
	if(l>r){
		if(ty==0) return INF; 
		return 0;
	}
	if(l==tl && r==tr){
		if(ty==0) return t[pos].fi;
		return t[pos].se;
	}
	int tm=(tl+tr)/2;
	if(!ty)
		return min(query(ty,l,min(r,tm),tl,tm,pos*2),
			query(ty,max(l,tm+1),r,tm+1,tr,pos*2+1));
	return __gcd(query(ty,l,min(r,tm),tl,tm,pos*2),
			query(ty,max(l,tm+1),r,tm+1,tr,pos*2+1));
}

int main() {
    boost; IO();

    int t; cin>>t;
    while(t--){
    	cin>>N>>P;

    	FOR(i,0,N) cin>>a[i];
    	vi vec(N); iota(all(vec),0);
    	sort(all(vec),cmp);

    	/*precompute();

    	vi v[N]; 
    	v[0].pb(P);

    	for(int i: vec){
    		int w=a[i];

    		int L=i,R=i; 

    		int l=0,r=i; 
    		while(l<=r){
    			int m=(l+r)/2;
    			if(query(0,m,i)==a[i]){ 
    				L=m; 
    				r=m-1;
    			} 
    			else l=m+1;
    		}

    		l=i,r=N-1; 
    		while(l<=r){
    			int m=(l+r)/2;
    			if(query(0,i,m)==a[i]){ 
    				R=m;
    				l=m+1;
    			} 
    			else r=m-1;
    		}

    		if(query(1,L,R)!=a[i]) L=i,R=i;

    		v[L].pb(w); 
    		v[R].pb(-w);
    	}

    	multiset<int>s;
    	ll ans=0;
    	FOR(i,0,N-1){
    		for(auto x: v[i]){
    			if(x>0) s.insert(x);
    			else s.erase(s.find(-x));
    		}
    		auto it=s.begin();
    		ans+=*it;
    	}
    	cout << ans << endl;*/

    	ll ans=0;
    	vi vis(N-1,0);
    	for(int i: vec){
    		int w=a[i];
    		if(w>P) continue;
    		
    		int idx=i,mn=a[idx],g=a[idx]; 
    		while(idx>0 && !vis[idx-1]){
    			idx--;
    			ckmin(mn,a[idx]);
    			g=__gcd(g,a[idx]);
    			if(mn!=a[i] || g!=a[i]) break;
    			vis[idx]=1;
    			ans+=w;
    		}

    		idx=i+1,mn=a[i],g=a[i];
    		while(idx<N && !vis[idx-1]){
    			ckmin(mn,a[idx]);
    			g=__gcd(g,a[idx]);
    			if(mn!=a[i] || g!=a[i]) break;
    			vis[idx-1]=1;
    			ans+=w;
    			idx++;
    		}
    	}

    	FOR(i,0,N-1) if(!vis[i]) ans+=P;
    	cout << ans << endl;

    }
    

    return 0;
}
//Change your approach 