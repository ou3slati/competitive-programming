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

int N; 
vi a(MX);

int query(int t, int i, int j, int x){
	assert(x>=1 && x<N);
	/*if(t==1)
		return max(min(x,a[i]),min(x+1,a[j]));
	return min(max(x,a[i]),max(x+1,a[j]));*/

	cout << "? " << t << ' ' << i << ' ' << j << ' ' << x << endl;
	cout.flush();
	int val; cin>>val;
	return val;
}

int32_t main() {
    boost; IO();

    int t; cin>>t;
    while(t--){
    	cin>>N;
    	//FOR(i,1,N+1) cin>>a[i];

    	vi ans(N+1);
    	int x=0,l=1,r=N-1;
    	while(l<=r){
    		int m=(l+r)/2;

    		int val=query(1,N,1,m);
    		if(val==m+1){
    			x=m; 
    			l=m+1;
    		}
    		else r=m-1;
    	}
    	ans[1]=x+1;

    	FOR(i,2,N+1){
    		if(ans[1]-1<=N-ans[1]){
    			int val=query(1,1,i,N-1);
    			if(val==ans[1]){
    				val=query(2,i,1,1);
    				ans[i]=val;
    			}
    			else ans[i]=val;
    		}
    		else{
    			int val=query(2,i,1,1);
    			if(val==ans[1]){
    				val=query(1,1,i,N-1);
    				ans[i]=val;
    			}
    			else ans[i]=val;
    		}
    	}

    	cout << "! ";
    	FOR(i,1,N+1){
    		cout << ans[i] << ' ';
    	}
    	cout << endl;
    	cout.flush();
    }
    

    return 0;
}
//Change your approach 