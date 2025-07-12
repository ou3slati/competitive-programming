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


vi t(MX,0); 

void upd(int i, int x){
	i++; 
	for(;i<MX; i+=i&-i) t[i]+=x; 
}
int g(int i){
	int ans=0; 
	for(;i;i-=i&-i) ans+=t[i]; 
	return ans; 
}
int get(int l, int r){
	l++; r++; 

	return g(r)-g(l-1); 
}

void reset(){
	t.assign(MX,0); 
}

//-------

int N,M, a[MX][MX], L[MX][MX], R[MX][MX]; 

ll ans=0;
void solve(int x, int y){
	reset();  

	vi vec[M]; 
	while(x>=0 && y<M){
		for(int i: vec[y]){
			upd(i,-1); 
		}
		if(!a[x][y]){
			reset();  
			x--; y++; 
			continue; 
		}

		int l=L[x][y], r=R[x][y]; 

		upd(y,1); 
		if(y+r<M) vec[y+r].pb(y); 
		ans+=get(y-l+1,y); 

		x--; y++; 
	}
}

int32_t main() {
    boost; IO();

    cin>>N>>M; 
    FOR(i,0,N) FOR(j,0,M){
    	char c; cin>>c; 
    	a[i][j]=(c=='z'); 
    }

    
    FOR(i,0,N) FOR(j,0,M) L[i][j]=0, R[i][j]=0; 
    FOR(i,0,N){
    	FOR(j,0,M) if(a[i][j]){
    		L[i][j]=a[i][j]; 
    		if(j) L[i][j]+=L[i][j-1];
    	} 

    	ROF(j,0,M) if(a[i][j]){
    		R[i][j]=a[i][j]; 
    		if(j+1<M) R[i][j]+=R[i][j+1];
    	}
    }

    //FOR(i,0,N) FOR(j,0,M) cout << R[i][j] << " \n"[j==M-1]; 
    
    FOR(i,0,N) FOR(j,0,M) if(!j || i==N-1) solve(i,j); 
    cout << ans << endl;
    

    return 0;
}
//Change your approach 