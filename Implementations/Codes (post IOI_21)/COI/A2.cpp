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

//-----------------------

int N; 

int query(int l, int r){
	cout << "? " << l << " " << r << endl;
	cout.flush(); 
	int ans; cin>>ans; 
	return ans; 
}

void answer(int ans){
	cout << "! " << ans << endl;
	cout.flush();  
}

//----------------------------

vi vec(MX,0); 


vi h(MX,0), rh(MX,0), power(MX);
void compute(){
	FOR(i,1,N+1){
		h[i]=vec[i]*power[i]; 
		h[i]+=h[i-1], h[i]%=MOD; 
	}

	ROF(i,1,N+1){
		rh[i]=vec[i]*power[N-i+1]; 
		rh[i]+=rh[i+1], rh[i]%=MOD; 
	}
}

int hsh(int l, int r){
	return (((h[r]-h[l-1]+MOD)%MOD)*modinv(power[l-1]))%MOD;
}

int rhsh(int l, int r){
	return (((rh[l]-rh[r+1]+MOD)%MOD)*modinv(power[N-r]))%MOD;
}

int query2(int l, int r){
	int n=r-l+1; 
	if(n==1) return 1; 

	if(n&1) return rhsh(l,l+n/2-1)==hsh(l+n/2+1,r); 
	return rhsh(l,l+n/2-1)==hsh(l+n/2,r); 
}

int32_t main() {
    boost; IO();

    cin>>N; 

    FOR(i,1,N){
    	if(query(i,i+1)) vec[i+1]=vec[i]; 
    	else vec[i+1]=1-vec[i]; 
    }



    power[0]=1; FOR(i,1,N+10) power[i]=(power[i-1]*2)%MOD; 
    compute(); 

    int ans=0; 
    FOR(i,1,N+1){
    	int l=0,r=N,x=0; 
    	while(l<=r){
    		int m=(l+r)/2; 
    		if(i+m<=N && i-m>=1 && query2(i-m,i+m)) x=m, l=m+1;
    		else r=m-1; 
    	}
    	ckmax(ans,2*x+1); 

    	if(i+1<=N && query2(i,i+1)){
    		int l=0,r=N,x=0; 
    		while(l<=r){
	    		int m=(l+r)/2; 
	    		if(i+1+m<=N && i-m>=1 && query2(i-m,i+1+m)) x=m, l=m+1;
	    		else r=m-1; 
	    	}
    		ckmax(ans,2*x+2); 
    	}
    }

    answer(ans); 
    

    return 0;
}
//Change your approach 