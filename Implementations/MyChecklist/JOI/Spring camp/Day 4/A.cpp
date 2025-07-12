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

int N,K,L[MX],R[MX],nxt[MX],memo[MX][2]; 
vi a;

bool cmp(int i, int j){
	return L[i]<L[j];
}

int solve(int i, int st){
	if(i==N) return 0;
	int &ind=memo[i][st];
	if(ind!=-1) return ind; 

	int ans;
	if(st) ans=solve(nxt[i],0)+1;
	else{
		ans=solve(i,1);
		ckmax(ans,solve(i+1,0));
	}
	return ind=ans; 
}

int32_t main() {
    boost; IO();
    
    memset(memo,-1,sizeof(memo));

    cin>>N>>K;
    FOR(i,0,N) cin>>L[i]>>R[i];

    a.resize(N);
    iota(all(a),0);
    sort(all(a),cmp);

    dbgv(a)

    FOR(i,0,N){
    	int l=i+1,r=N-1,ans=N;
    	while(l<=r){
    		int m=(l+r)/2;
    		if(L[a[m]]>=R[a[i]]){
    			ans=m; 
    			r=m-1;
    		}
    		else l=m+1;
    	}
    	nxt[i]=ans; 
    }

    //FOR(i,0,N) cout << nxt[i] << ' '; cout << endl;

    if(solve(0,0)<K){
    	cout << -1 << endl;
    	return 0;
    }

    int l=0; 
    vi ans; 
    while(K){
    	int chosen=INF,idx; 
    	FOR(i,l,N) if(solve(i,1)>=K && ckmin(chosen,a[i])) idx=i;
    	ans.pb(chosen); 
    	l=nxt[idx];  
    	K--;
    }
    sort(all(ans));
    for(auto x: ans) cout << x+1 << endl;
    	
    return 0;
}
//Change your approach 