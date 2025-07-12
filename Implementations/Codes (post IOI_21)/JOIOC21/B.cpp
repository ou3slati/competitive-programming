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
const int MX = 3e5 + 10;
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

#define prev whatever

int N,D; 
vi a, prev(MX); 

vi t(MX*4,0); 
void upd(int ty, int i, int v, int tl=1, int tr=N, int pos=1){
	if(tl==tr){
		if(ty) t[pos]=v;
		else t[pos]=0;  
		return; 
	}

	int tm=(tl+tr)/2; 
	if(i<=tm) upd(ty,i,v,tl,tm,pos*2); 
	else upd(ty,i,v,tm+1,tr,pos*2+1); 

	t[pos]=max(t[pos*2],t[pos*2+1]); 
}

int get(int l, int r, int tl=1, int tr=N, int pos=1){
	if(l>r) return 0; 

	if(l==tl && r==tr) return t[pos]; 

	int tm=(tl+tr)/2; 
	return max(get(l,min(r,tm),tl,tm,pos*2),get(max(l,tm+1),r,tm+1,tr,pos*2+1)); 
}

int main() {
    boost; IO();

    cin>>N>>D; 
    FOR(i,0,N){
    	int x; cin>>x; 
    	a.pb(x); 
    }
    
    /*vpi cur; 
    FOR(i,0,N) cur.eb(a[i],i); 
    sort(all(cur)); 

    int cnt=0; 
    FOR(i,0,N){
    	a[cur[i].se]=++cnt; 
    }

    FOR(i,0,N){
    	if(!i) prev[cur[i].se]=0; 
    	else if(cur[i].fi!=cur[i-1].fi) prev[cur[i].se]=a[cur[i-1].se]; 
    	else prev[cur[i].se]=prev[cur[i-1].se]; 
    }

    dbgv(a)
    FOR(i,0,N) dbg(prev[i])*/

    vi dp(N,1); 
    FOR(i,1,N){
    	/*dp[i] = get(1,prev[i])+1;
    	ckmax(dp[i],get()) 
    	upd(1,a[i],dp[i]);

    	if(i-D>=0) upd(0,a[i-D],dp[i-D]); */


    	int lst=i; 
    	ROF(j,0,i) if(a[j]<a[i]){
    		if(abs(j-lst)>D) break; 
    		ckmax(dp[i],dp[j]+1); 
    		lst=j; 
    	}
    }

    int ans=0; 
    for(int x: dp) ckmax(ans,x); 
    cout << ans << endl;

	dbgv(dp)


    

    return 0;
}
//Change your approach 