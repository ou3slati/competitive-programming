//Never stop trying
/*#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
#define int ll
typedef string str;
typedef double db;
typedef long double ld;
typedef pair<int, int> pi;
#define fi first
#define se second
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<str> vs;
typedef vector<ld> vd;
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

int N;
vi a(MX);

int XOR(int x, int y){
	#ifdef LOCAL
	return ((a[x])^(a[y]));
	#endif
	cout << "XOR " << x << ' ' << y << endl;
	cout.flush();
	int ans; cin>>ans;
	return ans;
}
int AND(int x, int y){
	#ifdef LOCAL
	return ((a[x])&(a[y]));
	#endif
	cout << "AND " << x << ' ' << y << endl;
	cout.flush();
	int ans; cin>>ans;
	return ans;
}
int OR(int x, int y){
	#ifdef LOCAL
	return ((a[x])|(a[y]));
	#endif
	cout << "OR " << x << ' ' << y << endl;
	cout.flush();
	int ans; cin>>ans;
	return ans;
}

int32_t main() {
    boost; IO();

    int LOG=17;
    cin>>N;

    #ifdef LOCAL
    FOR(i,1,N+1) cin>>a[i];
    #endif

    int x=XOR(1,2);
    int xx=XOR(2,3);
    int y=AND(1,2);
    int yy=AND(2,3);
    int yyy=AND(1,3);

    int ans[3][LOG];
    FOR(i,0,LOG){
    	bool r=true,r2=true;
    	if((x)&((1)<<(i))) r=false; //different
    	if((xx)&((1)<<(i))) r2=false; 

    	if(r){ //first and sec are the same
    		if((y)&((1)<<(i))) ans[0][i]=ans[1][i]=1;
    		else ans[0][i]=ans[1][i]=0;
    		if(r2) ans[2][i]=ans[1][i];
    		else ans[2][i]=1-ans[1][i];

    	}else if(r2){ //sec and third are the same
    		if((yy)&((1)<<(i))) ans[1][i]=ans[2][i]=1;
    		else ans[1][i]=ans[2][i]=0;
    		if(r) ans[0][i]=ans[1][i];
    		else ans[0][i]=1-ans[1][i];
    	}else{ //first and third are the same
    		if((yyy)&((1)<<(i))) ans[0][i]=ans[2][i]=1;
    		else ans[0][i]=ans[2][i]=0;
    		if(r) ans[1][i]=ans[0][i];
    		else ans[1][i]=1-ans[0][i];
    	}
    }
    
    
    int res[N+1];
    FOR(i,1,N+1){
    	if(i<=3){
    		int x=0;
    		FOR(b,0,LOG) x+=((1)<<(b))*ans[i-1][b];
    		res[i]=x;
    	}
    	else{
    		int x=XOR(1,i);
    		res[i]=((x)^(res[1]));
    	}
    }
    cout << '!' << ' ';
    FOR(i,1,N+1) cout << res[i] << ' '; 
    cout << endl;
    cout.flush();


    return 0;
}

/* Careful!!!
    .Array bounds
    .Infinite loops
    .Uninitialized variables / empty containers
    .Multisets are shit

   Some insights:
    .Binary search
    .Graph representation
    .Write brute force code
    .Change your approach
*/