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

int modpow(int x, int p){
	if(!p) return 1;
	int v=modpow(x,p/2);
	v*=v; v%=MOD;
	if(p&1) v*=x,v%=MOD;
	return v;
}

int modinv(int x){
	return modpow(x,MOD-2);
}

int32_t main() {
    boost; IO();

    int Q; cin>>Q;
    while(Q--){
    	int N,M,K,B; cin>>N>>M>>K>>B;

    	int L;
    	vi C;

    	if((N*M)%(K+2)!=0){
    		cout << -1 << endl;
    		continue;
    	}
    	else if(K==1 && N%3==0){
    		L=3; 
    		C.assign({0,0,M});
    	}
    	else if(K==2 && N%2==0 && M%2==0){
    		L=2;
    		C.assign({0,M/2});
    	}
    	else if(M%(K+2)!=0){
    		cout << -1 << endl;
    		continue;
    	}
    	else{
    		int x=M/(K+2);
    		L=1;
    		C.assign({x});
    	}

    	int Z=0,Y=N/L;
    	FOR(i,0,L) Z+=(C[i]*modpow(B,i))%MOD,Z%=MOD;

    	int X=modpow(B,L);
    	int ans=(modpow(X,Y)-1+MOD)%MOD;
    	ans*=modinv((X-1+MOD)%MOD); ans%=MOD;
    	ans*=Z; ans%=MOD;

    	if(N%L>=1) ans+=C[0]*modpow(B,N-N%L),ans%=MOD;
    	if(N%L==2) ans+=C[1]*modpow(B,N-1),ans%=MOD;

    	cout << ans << endl;
    }
    

    return 0;
}
//Change your approach 