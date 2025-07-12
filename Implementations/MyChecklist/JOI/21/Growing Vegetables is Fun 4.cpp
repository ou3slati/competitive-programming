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


int32_t main() {
    boost; IO();

    int N; cin>>N;
    vi a(N); FOR(i,0,N) cin>>a[i];
    vi pref(N,0),suf(N,0);

    FOR(i,1,N){
    	pref[i]=max(0ll,a[i-1]-a[i]+1);
    	pref[i]+=pref[i-1];
    }
    ROF(i,0,N-1){
    	suf[i]=max(0ll,a[i+1]-a[i]+1);
    	suf[i]+=suf[i+1];
    }

    dbgv(pref)
    dbgv(suf)

    int ans=INF;
    FOR(i,0,N){
    	int cur=0,mx=0,p=0;
    	if(i){
    		cur+=pref[i-1];
    		p=pref[i-1];
    		ckmax(mx,a[i-1]);
    	}
    	if(i+1<N){
    		cur+=max(0ll,suf[i+1]-p);
    		ckmax(mx,a[i+1]);
    	}
    	cur+=max(0ll,mx-a[i]+1);
    	ckmin(ans,cur);
    }

    /*FOR(i,0,N){
    	vi cur; cur.assign(all(a));
    	int v=0;
    	FOR(j,1,i+1){
    		if(cur[j]<=cur[j-1]){
    			v+=cur[j-1]-cur[j]+1;
    			FOR(k,j,N) cur[k]+=cur[j-1]-cur[j]+1;
    		}
    	}
    	ROF(j,i,N-1){
    		if(cur[j]<=cur[j+1]){
    			v+=cur[j+1]-cur[j]+1;
    			FOR(k,0,j+1) FOR(k,j,N) cur[k]+=cur[j+1]-cur[j]+1;
    		}
    	}
    	dbgs(i,v)
    	ckmin(ans,v);
    }*/
    cout << ans << endl;
    

    return 0;
}
//Change your approach 