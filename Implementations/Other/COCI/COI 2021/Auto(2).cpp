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


int N,K,X; 

map<int,vpi>mp;

V<pair<pi,int>>vec;

int bs(int idx){
	int l=0,r=sz(vec)-1,ans;
	while(l<=r){
		int m=(l+r)/2;
		if(idx>=vec[m].fi.fi){
			ans=m;
			l=m+1;
		}
		else r=m-1;
	}
	return ans; 
}

int32_t main() {
    boost; IO();

    cin>>N>>K>>X;
    FOR(idx,0,N){
    	int l,t,r; cin>>l>>t>>r;
    	mp[l].eb(0,1);
    	mp[r+1].eb(0,-1);

    	int l2=l+t;
    	if(l2<=r){
    		mp[l2].eb(1,1);
    		mp[r+1].eb(1,-1);
    	}
    }

    
    int l=-1,x=0,y=0;
    for(auto it: mp){
    	int idx=it.fi; 
    	vpi cur=it.se;

    	if(l!=-1 && x>=K){
    		vec.pb({{l,idx-1},y});
    	}

    	for(auto v: cur){
    		if(v.fi==0) x+=v.se;
    		else y+=v.se;
    	}

    	l=idx;
    }

    int n=sz(vec);
    int pref[n];

    FOR(i,0,n){
    	pref[i]=(vec[i].fi.se-vec[i].fi.fi+1)*vec[i].se;
    	if(i) pref[i]+=pref[i-1];
    }

    int ans=0;
    FOR(i,0,sz(vec)){
    	int l=vec[i].fi.fi;
    	int r=l+X-1; 

    	int j=bs(r); ckmin(r,vec[j].fi.se);

    	int x=0;
    	if(j) x+=pref[j-1]; if(i) x-=pref[i-1]; 
    	x+=(r-vec[j].fi.fi+1)*vec[j].se;

    	ckmax(ans,x);
    }

    for(auto &x: vec){
    	x.fi.fi=INF-x.fi.fi;
    	x.fi.se=INF-x.fi.se;
    	swap(x.fi.fi,x.fi.se);
    }
    sort(all(vec));
    FOR(i,0,n){
    	pref[i]=(vec[i].fi.se-vec[i].fi.fi+1)*vec[i].se;
    	if(i) pref[i]+=pref[i-1];
    }


    FOR(i,0,sz(vec)){
    	int l=vec[i].fi.fi;
    	int r=l+X-1; 

    	int j=bs(r); ckmin(r,vec[j].fi.se);

    	int x=0;
    	if(j) x+=pref[j-1]; if(i) x-=pref[i-1]; 
    	x+=(r-vec[j].fi.fi+1)*vec[j].se;

    	ckmax(ans,x);
    }
    cout << ans << endl;
    

    return 0;
}
//Change your approach 