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
const ll INF = 1e9;
const int MX = 300 + 10;
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

const int MX2=42;

int N,M,K;
vi a(MX),b(MX);

int s1,s2;
bool check(){
	if(K>M) return 0;
	s1=0,s2=0;
	FOR(i,0,N){
		if(a[i]<K) return 0;
		s1+=a[i];
	}
	FOR(i,0,M) s2+=b[i];
	if(s1>s2) return 0;
	return 1;
}

int memo[MX][MX*MX];
int solve(int i, int r){
	ckmax(r,0);
	if(i==M){
		if(r>0) return INF;
		return 0;
	}
	if(memo[i][r]!=-1) return memo[i][r];
	int ans=solve(i+1,r);
	ckmin(ans,solve(i+1,r-b[i])+b[i]);
	return memo[i][r]=ans;
}

int main() {
    boost; IO();

    cin>>N>>M>>K;
    FOR(i,0,N) cin>>a[i];
    FOR(i,0,M) cin>>b[i];

    if(!check()){
    	cout << "Impossible" << endl;
    	return 0;
    }

    if(M<=15){
	    int ans=INF;
	    FOR(m,0,(1)<<(M)){
	    	int x=0,v=0;
	    	FOR(i,0,M) if((m)&((1)<<(i))){
	    		x+=min(N,b[i]);
	    		v+=b[i]; 
	    	} 
	    	if(x>=N*K && v>=s1) ckmin(ans,v);
	    }
	    if(ans==INF) cout << "Impossible" << endl;
	    else cout << ans-s1 << endl;
    }
    else if(K==1){
    	memset(memo,-1,sizeof(memo));
    	cout << solve(0,s1)-s1 << endl;
    }
    else{
    	
    }

    

    return 0;
}
//Change your approach 