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
int vis[MX][MX],memo[MX][MX];

int mxx[MX];

ll f(ll mx){
	return mx/A+1;
}

void precompute(){ //vis[i][n]
	FOR(i,0,M-1){
		int l=S[i],r=S[i+1],nb=0,cur=l,ans=0; 
		ll rest=T-(l-1)*B;
		
		FOR(j,0,K+1) vis[i][j]=0;
		if(rest<0) continue;

		while(rest>0 && cur!=r && nb<K+1){ //K+1?
			ll x=f(rest);

			if(cur+x>r) x=r-cur;
			if(C*x>rest){
				ans+=x-1;
				if(cur==l) vis[i][0]+=x-1;
				break;
			}

			if(cur!=r) vis[i][nb]+=min((ll)r-cur-1,rest/A);

			cur+=x; ans+=x-(cur==r);
			nb+=(cur!=r);
			rest-=C*x;
			vis[i][nb]=ans;
		}
		FOR(j,nb+1,K+1) vis[i][j]=vis[i][j-1];
		FOR(j,0,K+1){
			vis[i][j]+=((r-1)*B<=T);
		} 

		mxx[i]=nb;
	}
}

int solve(int i, int r){
	if(i==M-1 || (S[i]-1)*B>T) return 0;
	int &ind=memo[i][r];
	if(ind!=-1) return ind;
	int ans=0;
	FOR(j,0,r+1) ckmax(ans,solve(i+1,r-j)+vis[i][j]);

	return ind=ans;
}

int main() {
    boost; IO();

    cin>>N>>M>>K>>A>>B>>C>>T; K-=M; 
    FOR(i,0,M) cin>>S[i];

    precompute();

    memset(memo,-1,sizeof(memo));
    cout << solve(0,K) << endl;
    
    return 0;
}
//Change your approach 