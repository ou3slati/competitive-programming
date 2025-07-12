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
const int MX = 5e5 + 10;
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


int N,Q; 
vi a(MX);	
V<pair<pi,int>> q[MX];


vi tv(MX,0),tr(MX,0);

int val(int i){
	int ans=0;
	for(;i;i-=i&-i) ans+=tv[i];
	return ans;
}
int rec(int i){
	int ans=0;
	for(;i;i-=i&-i) ans+=tr[i];
	return ans;
}

void upd_val(int i, int x){
	for(;i<MX; i+=i&-i) tv[i]+=x;
}
void upd_rec(int i, int x){
	for(;i<MX; i+=i&-i) tr[i]+=x;
}


int32_t main() {
    boost; IO();

    cin>>N>>Q;
    FOR(i,1,N+1) cin>>a[i];

    FOR(i,1,Q+1){
    	int t,l,r,x; cin>>t>>l>>r;
    	if(t==1){
    		cin>>x;
    		q[l].pb({{1,x},i});
    		q[r+1].pb({{1,-x},i});
    	}
    	else{
    		q[l].pb({{2,1},i});
    		q[r+1].pb({{2,-1},i});
    	}
    }

    int ans=0;
    FOR(i,1,N+1){
    	for(auto op: q[i]){
    		int x=op.fi.se,idx=op.se;
    		if(op.fi.fi==1){
    			ans+=(rec(Q)-rec(idx-1))*x;
    			upd_val(idx,x);
    		}
    		else{
    			ans+=val(idx)*x;
    			upd_rec(idx,x);
    		}
    	}
    	cout << ans+a[i]*rec(Q) << ' '; 
    }
    cout << endl;

    

    return 0;
}
//Change your approach 