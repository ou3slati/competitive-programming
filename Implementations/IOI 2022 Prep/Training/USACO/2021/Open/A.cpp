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

int N; 

vi t(MX*4,0); 
void upd(int i, int x, int l=0, int r=N-1, int pos=1){
	if(l==r){
		t[pos]+=x; 
		return; 
	}

	int m=(l+r)/2; 
	if(i<=m) upd(i,x,l,m,pos*2); 
	else upd(i,x,m+1,r,pos*2+1); 

	t[pos]=t[pos*2]+t[pos*2+1]; 
}

int get(int l, int r, int tl=0, int tr=N-1, int pos=1){
	if(l>r) return 0; 

	if(l==tl && r==tr) return t[pos]; 

	int tm=(tl+tr)/2; 
	return get(l,min(r,tm),tl,tm,pos*2) + get(max(l,tm+1),r,tm+1,tr,pos*2+1); 
}


int main() {
    boost; IO();

    cin>>N; 
    vi a(N); 
    FOR(i,0,N) cin>>a[i]; 

    vi prev(N),nxt(N),f(N+1,-1);
    FOR(i,0,N){
    	prev[i]=f[a[i]]; 
    	f[a[i]]=i; 
    }

    f.assign(N+1,N); 
    ROF(i,0,N){
    	nxt[i]=f[a[i]]; 
    	f[a[i]]=i; 
    }

    vi vec[N+1]; 
    ll ans=0; 
    FOR(i,0,N){
    	/*FOR(j,prev[i]+1,i){
    		ans+=(nxt[j]>i); 
		}*/

		for(int j: vec[i]) upd(j,-1);
		upd(i,1); 
		vec[nxt[i]].pb(i); 

    	ans+=get(prev[i]+1,i-1); 
    }
    cout << ans << endl;

    

    return 0;
}
//Change your approach 