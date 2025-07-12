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

const int LOG=10;
vi a(LOG),b(LOG);

int memo[LOG][2][2];
int dp(int i, int f, int f2){
	if(i==-1) return 1;

	int &ind=memo[i][f][f2];
	if(ind!=-1) return ind;

	int ans=0;
	FOR(d,0,3) FOR(d2,0,3){
		if((d<=a[i] || f) && (d2<=b[i] || f2)){
			dbg(i)
			dbgs(f,f2)
			dbgs(d,d2)
			ans+=dp(i-1,((f)|(d<a[i])),((f2)|(d2<b[i])));
		}
	}
	return ind=ans;
}

int solve(int X, int Y){
	int cur=X;
	FOR(i,0,LOG){
		a[i]=cur%3;
		cur/=3;
	}

	cur=Y;
	FOR(i,0,LOG){
		b[i]=cur%3;
		cur/=3;
	}

	FOR(i,0,LOG) if((a[i])%2!=(b[i])%2) return 0;
	return 1;	

	memset(memo,-1,sizeof(memo));
	return dp(LOG-1,0,0);
}

int32_t main() {
    boost; IO();

    int Q; cin>>Q;
    while(Q--){
    	int x,y,d; cin>>d>>x>>y;

    	int ans=0;
    	FOR(i,0,d+1){
    		ans+=solve(x+i,y+i);
    	}
    	cout << ans << endl;
    }

    /*int X; cin>>X;
    FOR(x,0,X+1){
    	solve(x,x);
    	FOR(i,0,LOG) cout << a[i];
    	cout << endl;
    }*/
    

    return 0;
}
//Change your approach 