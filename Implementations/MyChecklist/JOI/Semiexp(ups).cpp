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
const int MX = 3000 + 10;
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


ll N,M,K,A,B,C,T;
vi S(MX);
int vis[MX][MX],f[MX][MX]; //f[i][j]
//nb of new visited stations when j'th station is added in i'th block

ll fu(ll mx){
	return mx/A+1;
}

void precompute(){ 
	FOR(i,0,M-1){
		int l=S[i],r=S[i+1],nb=0,cur=l; 
		ll rest=T-(l-1)*B;
		FOR(j,0,K+1) f[i][j]=0;
		if(rest<0) continue;

		f[i][0]=1+min((ll)r-1-cur,rest/A);
		while(rest>0 && cur!=r-1 && nb<K){
			int jump=fu(rest); ckmin(jump,r-1-cur);
			if(C*jump>rest) break;

			cur+=jump; nb++; rest-=jump*C;
			f[i][nb]=cur-l+1;
			f[i][nb]+=min((ll)r-1-cur,rest/A);
		}

		int ff[K+1];
		FOR(j,1,K+1){
			ff[j]=f[i][j]-f[i][j-1];
		}
		FOR(j,1,K+1){
			f[i][j]=ff[j];
			if(f[i][j]<0) f[i][j]=0;
		}
	}
}

int solve(){
	vi v;
	int ans=0;
	FOR(i,0,M-1){
		FOR(j,1,K+1) v.pb(f[i][j]);
		ans+=f[i][0];
	}
	sort(rall(v));
	FOR(i,0,min((ll)sz(v),K)) ans+=v[i];

	return ans-1+((N-1)*B<=T);
}

int main() {
    boost; IO();

    cin>>N>>M>>K>>A>>B>>C>>T; K-=M; 
    FOR(i,0,M) cin>>S[i];

    precompute();

    cout << solve() << endl;

    
    return 0;
}
//Change your approach 