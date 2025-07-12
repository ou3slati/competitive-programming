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

const int N=(1<<20);
vi a(N+10,-1),t(N+10,0);

int get2(int i){
	int ans=0;
	for(;i;i-=i&-i) ans+=t[i];
	return ans; 
}
int get(int l, int r){
	l++; r++; 
	return get2(r)-get2(l-1);
}
void upd(int i){ 
	i++;
	for(;i<sz(t); i+=i&-i) t[i]++;
}

int32_t main() {
    boost; IO();

    int Q; cin>>Q;
    while(Q--){
    	int ty,x; cin>>ty>>x;
    	int org=x; 
    	x%=N; 

    	if(ty==1){
    		if(get(x,N-1)==N-x) x=0;

    		int l=x,r=N-1,idx;
    		while(l<=r){
    			int m=(l+r)/2;
    			if(get(x,m)<m-x+1){
    				idx=m;
    				r=m-1;
    			}
    			else l=m+1;
    		}
    		upd(idx);
    		a[idx]=org; 
    	}	
    	else{
    		cout << a[x] << endl;
    	}
    }
    

    return 0;
}
//Change your approach 