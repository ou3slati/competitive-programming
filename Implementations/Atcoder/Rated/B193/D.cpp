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

int K; 
str s,t; 

int solve(vi v){
	vi cnt(10,0);
	for(auto x: v) cnt[x]++;
	int ans=0;
	FOR(i,1,10){
		int val=1;
		while(cnt[i]--) val*=10;
		ans+=i*val;
	}
	return ans;
}

int32_t main() {
    boost; IO();

    cin>>K;

    vi cnt(10,0);
    cin>>s>>t;
    vi v,vv;
    for(auto x: s) if(x!='#') cnt[x-'0']++,v.pb(x-'0');
    for(auto x: t) if(x!='#') cnt[x-'0']++,vv.pb(x-'0');

    int a=0,b=0;
    FOR(i,1,10) FOR(j,1,10) if(cnt[i]+1+(j==i)<=K && cnt[j]+1+(j==i)<=K){
    	v.pb(i); vv.pb(j);
    	if(solve(v)>solve(vv)){
    		if(i!=j){
    			a+=(K-cnt[i])*(K-cnt[j]);
			}
    		else{
    			a+=(K-cnt[i])*(K-cnt[j]-1);
    		}
		}
    	if(i!=j){
    		b+=(K-cnt[i])*(K-cnt[j]);
    	}
    	else{
    		b+=(K-cnt[i])*(K-cnt[j]-1);
    	}
    	v.pop_back(); vv.pop_back();
    }
    dbgs(a,b)
    cout << fixed << setprecision(10) << ((ld)a)/b << endl;

    return 0;
}
//Change your approach 