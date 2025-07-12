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
vi a(MX);

vi pos(MX);
vector<ll> cumA(MX,0),cumB(MX,0),cumC(MX,0);

void precompute(){
	FOR(i,1,N+1) 
		pos[a[i]]=i;
	FOR(i,1,N+1){
		cumA[i]+=cumA[i-1];
		cumB[i]+=cumB[i-1];
	}
	ROF(i,1,N+1) 
		cumC[i]+=cumC[i+1];
}


//seg tree

vector<ll>t(MX*4,INF);

void upd(int i, ll v, int pos=1, int tl=1, int tr=N){
	if(tl==tr){
		t[pos]=v;
		return; 
	}
	int tm=(tl+tr)/2;
	if(i<=tm) upd(i,v,pos*2,tl,tm);
	else upd(i,v,pos*2+1,tm+1,tr);

	t[pos]=min(t[pos*2],t[pos*2+1]);
}

ll get(int l, int r, int pos=1, int tl=1, int tr=N){
	if(l>r) return INF; 
	if(l==tl && r==tr) return t[pos];

	int tm=(tl+tr)/2;
	return min(get(l,min(r,tm),pos*2,tl,tm),
		get(max(l,tm+1),r,pos*2+1,tm+1,tr));
}

int main() {
    boost; IO();

    cin>>N;
    FOR(i,1,N+1) 
    	cin>>a[i];
    FOR(i,1,N+1){
    	cin>>cumA[i]>>cumB[i]>>cumC[i];
    	ckmin(cumB[i],cumA[i]);
    	ckmin(cumC[i],cumA[i]);
    }

    precompute();

    ll dp[N+1]; 
    dp[1]=0; upd(pos[1],-cumA[1]);
    FOR(i,2,N+1){
    	dp[i]=cumB[i-1];

    	ckmin(dp[i],get(1,pos[i])+cumA[i-1]);

    	upd(pos[i],dp[i]-cumA[i]);
    }
    ll ans=INF; 
    FOR(i,1,N+1) ckmin(ans,dp[i]+cumC[i+1]);
    cout << ans << endl;

    return 0;
}
//Change your approach 